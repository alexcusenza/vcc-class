/*
 * clStop.h
 *
 *  Created on: Aug 27, 2014
 *      Author: jbw
 */

#ifndef CLSTOP_H_
#define CLSTOP_H_


struct ExecType
{
    bool Estop;
    bool Cstop;
};


class clStop
{
public:
    clStop();
    virtual ~clStop();

    void Fstop();
    void Estop();
    void Cstop();


private:
    enSystemStateType mSystemState;
    TravelStateType mTravelMode;
    ExecType mExec;
    bool mAutoOn;
    bool mNavRunFlag;
    bool mRunEnable;
};

#endif /* CLSTOP_H_ */
