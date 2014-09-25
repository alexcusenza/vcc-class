/*
 * classBatteryControl.h
 *
 *  Created on: Jul 22, 2014
 *      Author: jbw
 */

#ifndef CLASSBATTERYCONTROL_H_
#define CLASSBATTERYCONTROL_H_

#include "TypeDefs.h"
#include "VMDefs.h"
#include "msgnum.h"
#include "GlobalFunctions.h"
#include "GlobalStructures.h"

typedef struct
{
    int32u Voltage;                                // Total battery voltage (scaled by VOLTS_PER_BIT)
    float  VoltsPerCell;                           // Corresponding volts per cell
    int32u BatteryLevel;                           // Battery level
} VoltageLevels;

static VoltageLevels disChargeLevel[] =
{
        // Volts/cell  Charge Level
        {   0,  2.060,  20  },
        {   0,  2.053,  19  },
        {   0,  2.045,  18  },
        {   0,  2.038,  17  },
        {   0,  2.030,  16  },
        {   0,  2.023,  15  },
        {   0,  2.015,  14  },
        {   0,  2.008,  13  },
        {   0,  2.000,  12  },
        {   0,  1.988,  11  },
        {   0,  1.975,  10  },
        {   0,  1.963,  9   },
        {   0,  1.950,  8   },
        {   0,  1.938,  7   },
        {   0,  1.925,  6   },
        {   0,  1.913,  5   },
        {   0,  1.900,  4   },
        {   0,  1.880,  3   },
        {   0,  1.860,  2   },
        {   0,  1.750,  1   },
        {   0,  1.700,  0   }

};

static const float BATTERY_CONVERSION_FACTOR = (100 / 65535);
static const float BATTERY_VOLTAGE_OFFSET = (2.11 / BATTERY_CONVERSION_FACTOR);
static const float CURRENT_CONVERSTION_FACTOR = (600 / 32767);          //  600Amp / 15bit: ADC conversion of Current Sensor

static const float KCURRENT = 1.0;
static const float KTEMPERATURE = 1.0;
static const float KCHARGING = 1.0;

static const int16u IRATED6 = 170;              // C/XX: 1020 AmpHrs / 6 hrs
static const int16u IRATED5 = 190;              // C/XX: 970 AmpHrs / 5 hrs
static const int16u IBATT_NOM_CAP = 1300;       // 1300 AmpHrs

static const float AVG_ALPHA = 0.9;             // value used for weighted-average moving filter


/* +----------------------------------------------------+
 * Class Definition
 * +----------------------------------------------------+
 */

class classBatteryControl
{
public:
    classBatteryControl(int, int);
    ~classBatteryControl();

    int Reset(int);
    int Monitor(bool, bool, int, int);

private:
    const int16u m_systemvoltage;           // 12, 24, 36, 48 or 72 volts
    const int16u m_dxscan;                  // in milliseconds

    bool voltageactive = true;
    int32u prevBatteryAvgVolts;
    int32u BatteryAvgVolts;
    int32u Ibatt;
    int32u Vbatt;
    int32u Iadj;
    int32u prevIadj;
    float IcurrSumAs;
    int16u IcurrStatus;
    int16u VoltageStatus;
    int16u BatteryStatus;

    static const int16u BATTERYLEVELCNT = sizeof(disChargeLevel) / sizeof(VoltageLevels);
    const float MAXBATTERYVOLTAGE = (1.82 * (m_systemvoltage / 2) * BATTERY_CONVERSION_FACTOR);
    const float MINBATTERYVOLTAGE = (2.04 * (m_systemvoltage / 2) * BATTERY_CONVERSION_FACTOR);

};

#endif /* CLASSBATTERYCONTROL_H_ */
