/*
 * clTravelCase.h
 *
 *  Created on: Aug 27, 2014
 *      Author: jbw
 */

#ifndef CLLASERSCANNER_H_
#define CLLASERSCANNER_H_

struct VehConfigType
{
    int ThetaAngle;
    int CaseIndexMax;
    struct
    {
        int TravelCase;
        char TravelName;
        int Angle;
        int Speed;
        int CPUDeviceCase[];
    } CaseTable[];
};

class clTravelCase
{
public:
    clTravelCase();
    virtual ~clTravelCase();

    void VehicleTrajectory();
    int CaseIndex();
    void TravelCaseRoutine(VehConfigType &);

private:
    int mTravelCaseRequest;

    int mSegmentAngle;
    int mNavTrajectoryAngle;
    int m_CPUCase;
    int m_index;

    static int m_CPUDevice;
    VehConfigType Config;

};

#endif /* CLLASERSCANNER_H_ */
