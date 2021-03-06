/*
 * clTravelCase.h
 *
 *  Created on: Aug 27, 2014
 *      Author: jbw
 */

#ifndef CLLASERSCANNER_H_
#define CLLASERSCANNER_H_

class clTravelCase
{
public:
    clTravelCase();
    virtual ~clTravelCase();

    void VehicleTrajectory();
    int CaseIndex();
    void TravelCaseRoutine(VehConfigType &);
    int getIndex()
    {
        return m_index;
    }

private:
    int mTravelCaseRequest;

    int mSegmentAngle;
    int mNavTrajectoryAngle;
    int m_CPUCase;
    int m_index;

    VehConfigType Config;

};

#endif /* CLLASERSCANNER_H_ */
