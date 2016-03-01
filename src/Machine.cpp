/*
 * Machine.cpp
 *
 *  Created on: 1 mrt. 2016
 *      Author: Christus
 */

#include "Machine.hpp"
#include "Job.hpp"
#include <climits>
#include <vector>

Machine::Machine() : machineNumber(SHRT_MAX)
{
	// TODO Auto-generated constructor stub
}

Machine::Machine(const unsigned short int aMachineNumber):machineNumber(aMachineNumber)
{

}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

unsigned short int Machine::executeTask(Job aJob)
{
	unsigned short int taskTime = 0;

	taskTime = aJob.getTaskList()[0].getTaskTime();
	aJob.getTaskList().erase(aJob.getTaskList().begin());
	aJob.getTaskList().shrink_to_fit();
	return taskTime;
}

unsigned short int Machine::getMachineNumber()
{
	return machineNumber;
}
