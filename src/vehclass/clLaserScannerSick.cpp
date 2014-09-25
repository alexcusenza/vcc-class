/*
 * clLaserScannerSick.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: jbw
 */

#include "clLaserScannerSick.h"

clLaserScannerSick::clLaserScannerSick(
    clTravelCase * tptr):
    m_clTravel(tptr)
{
    m_CPUDevice++;
}

clLaserScannerSick::~clLaserScannerSick()
{
    // TODO Auto-generated destructor stub
}

void clLaserScannerSick::setcase()
{
    m_index = m_clTravel->getIndex();
    caseselect.CaseInput = Config.CaseTable[m_index].CPUDeviceCase[m_CPUDevice];

}

void clLaserScannerSick::getcase()
{


}
