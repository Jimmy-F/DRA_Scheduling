/*
 * Job.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Job.hpp"

Job::Job()
{
	ID = SHRT_MAX;
	startTime = LONG_MAX;
	endTime = LONG_MAX;
}

Job::Job(unsigned short int aID,const char* aJobTask)
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
