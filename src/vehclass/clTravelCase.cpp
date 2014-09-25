/*
 * clTravelCase.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: jbw
 */

#include "clTravelCase.h"

clTravelCase::clTravelCase()
{


}


clTravelCase::~clTravelCase()
{
    // TODO Auto-generated destructor stub
}


void clTravelCase::VehicleTrajectory()
{
    /*
     * mNavTrajectoryAngle: Trajectory angle of vehicle from Nav
     * Config.ThetaAngle: Param in Config for allowed angle movement, ie: +/- 5 degs.
     * TrajAngle: Trajectory plus half ThetaAngle
     */
    int TrajAngle = (mNavTrajectoryAngle + Config.ThetaAngle/2);

    if ((TrajAngle % CDEG(90)) < Config.ThetaAngle) // 90's: 0,2, 4, 6
    {
        mSegmentAngle = (TrajAngle / CDEG(90)) * 2;
    }
    else  // 45's : 1,3,5,7
    {
        mSegmentAngle = (TrajAngle / CDEG(90)) * 2 + 1;
    }
}


int clTravelCase::CaseIndex()
{
    VehicleTrajectory();       // function to convert actual vehicle trajectory angle to Vehicle Sector

    for (int idx = 0; idx < Config.CaseIndexMax; idx++)
    {
        if (Config.CaseTable[idx].TravelCase == mTravelCaseRequest)
        {
            // Allow the vehicle to traverse in the 45 angled trajectory defined and +/- 45 degrees.
            if (Config.CaseTable[idx].Angle == mSegmentAngle ||
                    Config.CaseTable[idx].Angle == (mSegmentAngle + 7)%8 ||   // "-1"
                    Config.CaseTable[idx].Angle == (mSegmentAngle + 1)%8 )
            {
                return (idx);
            }
        }
    }
    return (9999);
}


void clTravelCase::TravelCaseRoutine(VehConfigType & tmp)
{
    static int index;                           // Returned value from configuration index into array
    MessType m;

    Config = tmp;

    if (NavStatusptr->Pendant.Active )
    {
        m_CPUCase = 0;
    }
    else
    {
        if (mTravelCaseRequest != 0)
        {
            index = TravelCaseMode();

            if (index == 9999)
            {
                m_CPUCase = Config.CaseTable[index].CPUDeviceCase[m_CPUDevice];
                VMGlobalptr->SpeedData.BumperSpeed = 33;
            }
            else if ( index >= 0)
            {
                m_CPUCase = Config.CaseTable[index].CPUDeviceCase[m_CPUDevice];
                VMGlobalptr->SpeedData.BumperSpeed = Config.CaseTable[index].Speed;
            }
        }
    }
}

