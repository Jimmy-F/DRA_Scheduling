/*
 * Machine.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: jimmy
 */

#include "Machine.hpp"
#include <iostream>
#include <climits>

Machine::Machine() :
		machineID(SHRT_MAX),runTime(LONG_MAX), idle(true)
{
	// TODO Auto-generated constructor stub

}

Machine::Machine(const unsigned short int aMachineID, const bool state) :
		machineID(aMachineID), runTime(0), idle(state)
{

}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

void Machine::setRunTime(const unsigned long aRunTime)
{
	runTime = aRunTime;
}

unsigned short int Machine::getMachineID()const
{
	return machineID;
}

unsigned long int Machine::getRunTime()const
{
	return runTime;
}

bool Machine::getIdle()const
{
	return idle;
}

void Machine::setIdle(const bool state)
{
	idle = state;
}

Task Machine::getTask()const
{
	return task;
}

void Machine::setTask(const Task& aTask)
{
	task = aTask;
	setIdle(false);
}

void Machine::execute()
{
	runTime++;
}

bool Machine::isTaskDone()
{
	if (runTime == task.getTaskTime())
	{
		setIdle(true);
		runTime = 0;
		return true;
	}
	else
	{
		return false;
	}
}










