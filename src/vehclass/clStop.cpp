/*
 * clStop.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: jbw
 */

#include "clStop.h"

clStop::clStop()
{
    // TODO Auto-generated constructor stub

}

clStop::~clStop()
{
    // TODO Auto-generated destructor stub
}

void clStop::Fstop()
{
    if (mSystemState != enSS_FatalError)
    {
        mSystemState = enSS_FatalError;

        mAutoOn = false;
        mNavRunFlag = false;
        mTravelMode = tsEStop;

        // Pull the estop....
        WriteIOMap(OUT_VehMgr_Estop, 0);

        // Set the travel command to estop
        CFwObjectDictionary::GetThis().ChangeValue(ITravelCommand, tsEStop, true);

        // Take the navigation manager out of operational mode
        CFwObjectDictionary::GetThis().ChangeValue(IOperationalMode, false, true);
    }

    if ( ErrCode != 0 )
    {
        ErrArbirt( ErrCode );                        // Send the error to the Arbirtrator
    }

    return;
}


void clStop::Estop()
{
    if (mAutoOn)
    {
        mAutoOn = false;                // Clear the Auto-On flag
        Hornptr->EStopHorn = true;                   // Sound the Emergency-stop horn
        VMGlobalptr->RedBeaconCondition = true;      // Turn on the red beacon
    }

    if (mTravelMode != tsEStop)        // Travel state set to E-Stop?
    {
        mTravelMode = tsEStop;

        mExec.Estop = true;              // Set executing estop flag
        mExec.Cstop = false;             // Clear executing cstop flag
        mRunEnable = false;             // Clear run enable flag

        VMGlobalptr->SpeedData.RequestSpeed = 0;     // Set requested speed to zero

        CFwObjectDictionary::GetThis().ChangeValue(ITravelCommand, mTravelMode, true);

    }
    else if (((mTravelMode == tsEStop) || (mTravelMode == tsControlledStop) ||
            mExec.Estop || mExec.Cstop) && (NavStatusptr->CurrentVel == 0))
    {
        mExec.Estop = false;             // Clear executing estop flag
        mExec.Cstop = false;             // Clear executing cstop flag
        mRunEnable = false;             // Clear run enable flag
    }

    if ( ErrCode != 0 )
    {
        ErrArbirt( ErrCode );                        // Send the error to the Arbirtrator
    }

    return;
}

void clStop::Cstop()
{
    if (mAutoOn)
    {
        mAutoOn = false;        // Clear the Auto-On flag
        Hornptr->AStopHorn = true;                   // Sound the Auto-stop horn
        VMGlobalptr->RedBeaconCondition = true;
    }

    // Is travel state not set to C-Stop or E-Stop?
    if ((mTravelMode != tsControlledStop) && (mTravelMode != tsEStop))
    {
        mTravelMode = tsControlledStop;

        mExec.Estop = false;             // Clear executing estop flag
        mExec.Cstop = true;              // Set executing cstop flag
        mRunEnable = false;             // Clear run enable flag

        VMGlobalptr->SpeedData.RequestSpeed = 0;     // Set requested speed to zero

        CFwObjectDictionary::GetThis().ChangeValue(ITravelCommand, mTravelMode, true);
    }

    else if ((mTravelMode == tsControlledStop || mExec.Cstop) &&
            NavStatusptr->CurrentVel == 0)
    {
        mExec.Estop = false;             // Clear executing estop flag
        mExec.Cstop = false;             // Clear executing cstop flag
        mRunEnable = false;             // Clear run enable flag
    }

    if ( CndCode != 0 )
    {
        CndArbirt( CndCode );                      // Send the condition to the Arbirtrator
    }

    return;

}
