/*
 * Job.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Job.hpp"
#include <climits>
#include <iostream>

Job::Job()
{
	ID = SHRT_MAX;
	startTime = LONG_MAX;
	endTime = LONG_MAX;
	remainingJobTime = LONG_MAX;
}

Job::Job(unsigned short int aID, std::string& aJobTask)
	:ID(aID),jobTasks(aJobTask)
{
	startTime = LONG_MAX;
	endTime = LONG_MAX;
	remainingJobTime = LONG_MAX;
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

void Job::calculateTotalRemainingTime()
{
	for(unsigned int i = 0; i < jobTasks.length(); i++)
	{
		std::cout << jobTasks.length() << std::endl;
	}
}

unsigned short int Job::getID()const
{
	return ID;
}

unsigned long int Job::getRemainingJobTime()
{
	return remainingJobTime;
}

void Job::setID(const unsigned short int anID)
{
	ID = anID;
}
