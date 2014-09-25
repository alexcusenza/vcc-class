/*
 * classBatteryControl.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: jbw
 */

#include "classBatteryControl.h"

/* +----------------------------------------------------+
 * Constructor
 * +----------------------------------------------------+
 */

classBatteryControl::classBatteryControl(
    const int voltage,
    const int dxscan) :
        m_systemvoltage(voltage),
        m_dxscan(dxscan)
{
    int32u nCellCount;                // Number of cells in the vehicle's battery

    // Initialize battery cell count and delta-voltage values
    nCellCount = (m_systemvoltage / 2);

    // Initialize the total voltage column in the battery charge level array
    for (int i = 0; i < BATTERYLEVELCNT; i++)
    {
        disChargeLevel[i].Voltage = ((disChargeLevel[i].VoltsPerCell * nCellCount) / BATTERY_CONVERSION_FACTOR);
    }

}

/* +----------------------------------------------------+
 * Deconstructor
 * +----------------------------------------------------+
 */

classBatteryControl::~classBatteryControl()
{
    // TODO Auto-generated destructor stub
}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */

int classBatteryControl::Reset(
    int readvoltage)
{
    // Initialize the average voltage with the current value
    Vbatt = readvoltage + BATTERY_VOLTAGE_OFFSET;

    // Set the Battery Level reported to the VSM
    for (int x = 0; x < BATTERYLEVELCNT; x++)
    {
        if (Vbatt > disChargeLevel[x].Voltage)
        {
            if (disChargeLevel[x].Voltage <= 1)
            {
                return (0);
            }

            BatteryStatus = disChargeLevel[x].BatteryLevel / 2;
            break;
        }
    }

    return (BatteryStatus);
}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
int classBatteryControl::Monitor(
    bool charging,
    bool moving,
    int readvoltage,
    int readcurrent)
{
    bool Ichrg = false;

    // Capture Current and Voltage reading
    Ibatt = readcurrent * CURRENT_CONVERSTION_FACTOR;
    Vbatt = readvoltage + BATTERY_VOLTAGE_OFFSET;

    if (Ibatt & 0x8000)
        Ichrg = true;

    /***
     * Adjust Ibatt
     * if vehicle is charging, adjust Ibatt
     * otherwise, use the appropriate IRATED parameter
     */
    if (Ichrg)
        Iadj = Ibatt * KTEMPERATURE * KCHARGING;

    else
    {
        if (Ibatt < IRATED6)
            Iadj = Ibatt * KTEMPERATURE;

        else if (Ibatt >= IRATED6 && Ibatt < IRATED5)
            Iadj = Ibatt * KTEMPERATURE * KCURRENT;

        else if (Ibatt >= IRATED5)
            Iadj = Ibatt * KTEMPERATURE * KCURRENT * KCURRENT;
    }

    /***
     * Trapezoid Integration
     * Area = (b-a)/2 * (f(a) + f(b))
     */

    IcurrSumAs = IcurrSumAs + (1 / 2 * m_dxscan / 1000 * (Iadj + prevIadj));
    prevIadj = Iadj;

    /***
     * CurrentStatus
     * Value is represented as a percentage of state of charge remaining of
     * total battery capacity.
     */
    IcurrStatus = (1 - (IcurrSumAs / 3600 / IBATT_NOM_CAP)) * 10;

    // Battery Voltage Monitoring Oneshot logic
    if ((charging == true || moving == true) && voltageactive == true)
    {
        voltageactive = false;
    }
    else if ((charging == false && moving == false) && voltageactive == false)
    {
        voltageactive = true;
        prevBatteryAvgVolts = Vbatt;
    }

    // Calculate voltage
    if (voltageactive == true)
    {
        /***
         * Battery Voltage Weighted Average Calculation
         * AverageValue = AVG_ALPHA * prevAverageValue + (1-AVG_ALPHA) * CurrentValue;
         */

        BatteryAvgVolts  = AVG_ALPHA * prevBatteryAvgVolts + (1-AVG_ALPHA) * Vbatt;
        prevBatteryAvgVolts = BatteryAvgVolts;

        /***
         * Battery Voltage and Current Comparison Logic
         * First determine battery voltage range
         * If not out of bounds, then compare current status with voltage status
         */
        if (BatteryAvgVolts < MINBATTERYVOLTAGE)
        {
            BatteryStatus = 0;
        }
        else if (BatteryAvgVolts > MAXBATTERYVOLTAGE)
        {
            BatteryStatus = 10;
        }
        else
        {
            for (int x = 0; x < BATTERYLEVELCNT; x++)
            {
                if (BatteryAvgVolts > disChargeLevel[x].Voltage)
                {
                    VoltageStatus = disChargeLevel[x].BatteryLevel / 2;
                    break;
                }
            }

            if (IcurrStatus < VoltageStatus)
            {
                BatteryStatus = IcurrStatus;
            }
            else
            {
                BatteryStatus = VoltageStatus;
                IcurrSumAs = VoltageStatus / 10 * IBATT_NOM_CAP;
            }
        }
    }
    else
        BatteryStatus = IcurrStatus;

    return (BatteryStatus);

}
