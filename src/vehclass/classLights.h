/*
 * classLights.h
 *
 *  Created on: Jul 30, 2014
 *      Author: jbw
 */

#ifndef CLASSLIGHTS_H_
#define CLASSLIGHTS_H_

#include "CFwTimer.h"

const int turningrate = 500;
const int guiderate = 500;

class classLights
{
public:
    classLights();
    ~classLights();

    void TurnSignal(int);
    bool Toggle(int);
    void GuidanceControl(int);
    void ErrorLight();

private:
    int seq;
    bool light;
    bool lightout;
    bool amberStart;
    bool amberToggle;

    static CFwTimer ToggleTimer;
};


#endif /* CLASSLIGHTS_H_ */
