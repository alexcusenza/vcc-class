/*
 * classLights.cpp
 *
 *  Created on: Jul 30, 2014
 *      Author: jbw
 */

#include "classLights.h"

/*
 * +----------------------------------------------------+
 * Constructor
 * +----------------------------------------------------+
 */

classLights::classLights()
{
    // TODO Auto-generated constructor stub

}


/* +----------------------------------------------------+
 * DeConstructor
 * +----------------------------------------------------+
 */

classLights::~classLights()
{
    // TODO Auto-generated destructor stub
}


/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
bool classLights::Toggle(int delay)
{
    if ( ToggleTimer.IsTimeout() == true )
    {
        light = ~light;
        ToggleTimer.SetTimer(delay);
    }

    return(light);
}


/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
void classLights::TurnSignal(int turning)
{
    if (turning == 0)
    {
        lightout = Toggle(turningrate);
    }
    else if (turning == 1)
    {
        lightout = Toggle(turningrate);
    }
    else
    {
        lightout = false;
    }

}


/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */

void classLights::GuidanceControl(int GuidanceStatus)
{
    if (GuidanceStatus == gsGuidesafe)
    {
        lightout = true;

    }
    else if (GuidanceStatus == gsClose )
    {

        lightout = Toggle(guiderate);

    }
    else if (GuidanceStatus == gsNotClose )
    {
        lightout = Toggle(guiderate * 2);

    }
    else
    {
        lightout = false;

    }
}


/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */

void classLights::ErrorLight()
{



}
