/*
 * Task.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Task.hpp"
#include <climits>

Task::Task()
{
	taskTime = SHRT_MAX;
	ID = SHRT_MAX;
	machine = SHRT_MAX;

}

Task::Task(unsigned short int aTaskTime, unsigned short int aID, unsigned short int aMachine)
	: taskTime(aTaskTime), ID(aID), machine(aMachine)
{

}

Task::~Task()
{

}

