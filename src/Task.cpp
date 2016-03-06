/*
 * Task.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Task.hpp"
#include <climits>

Task::Task() :
		taskTime(SHRT_MAX),ID(SHRT_MAX),machine(SHRT_MAX), jobID(SHRT_MAX)
{

}

Task::Task(const unsigned short int aTaskTime, const unsigned short int aID,
		   const unsigned short int aMachine, const unsigned short int aJobID) :
		taskTime(aTaskTime), ID(aID), machine(aMachine), jobID(aJobID)
{

}

Task::~Task()
{

}

unsigned short int Task::getTaskTime()const
{
	return taskTime;
}

unsigned short int Task::getID()const
{
	return ID;
}

unsigned short int Task::getMachine()const
{
	return machine;
}

unsigned short int Task::getJobID()const
{
	return jobID;
}

Task& Task::operator=(const Task& aTask)
{
	if (this != &aTask)
	{
		taskTime = aTask.taskTime;
		jobID = aTask.jobID;
		ID = aTask.ID;
		machine = aTask.machine;
	}
	return *this;
}

bool Task::operator==(const Task& aTask)const
{
	if (taskTime == aTask.taskTime && jobID == aTask.jobID
		&& ID == aTask.ID && machine == aTask.machine)
	{
		return true;
	}
	else
	{
		return false;
	}
}
