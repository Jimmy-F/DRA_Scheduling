/*
 * Job.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Job.hpp"
#include <climits>

Job::Job()
{
	ID = SHRT_MAX;
	startTime = LONG_MAX;
	endTime = LONG_MAX;
}

Job::Job(unsigned short int aID, std::string& aJobTask)
	:ID(aID),jobTasks(aJobTask)
{
	startTime = LONG_MAX;
	endTime = LONG_MAX;
}

Job::~Job()
{
}

std::string Job::getJobTasks()const
{
	return jobTasks;
}

void Job::setJobTasks(const char* aJobTask)
{
	jobTasks = aJobTask;
}

unsigned short int Job::getID()const
{
	return ID;
}

void Job::setID(const unsigned short int anID)
{
	ID = anID;
}
