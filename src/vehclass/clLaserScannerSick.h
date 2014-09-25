/*
 * clLaserScannerSick.h
 *
 *  Created on: Sep 14, 2014
 *      Author: jbw
 */

#ifndef CLLASERSCANNERSICK_H_
#define CLLASERSCANNERSICK_H_
#include "clTravelCase.h"

struct CPUCaseType
{
    union
    {
        struct
        {
            bool InputA : 1;
            bool InputB : 1;
            bool InputC : 1;
            bool InputD : 1;
            bool InputE : 1;
            bool InputF : 1;
            bool InputG : 1;
            bool InputH : 1;
        }sCaseInput;
        char CaseInput;
    };
};

class clLaserScannerSick
{
public:
    clLaserScannerSick(clTravelCase *);
    virtual ~clLaserScannerSick();

    void setcase();
    void getcase();

private:
    VehConfigType Config;
    static int m_CPUDevice;
    clTravelCase * m_clTravel;
    CPUCaseType caseselect;
    int m_index;


};

#endif /* CLLASERSCANNERSICK_H_ */
