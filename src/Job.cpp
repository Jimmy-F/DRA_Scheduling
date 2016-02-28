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
	slack = SHRT_MAX;
}

Job::Job(unsigned short int aID, std::string& aJobTask)
	:ID(aID),jobTasks(aJobTask)
{
	startTime = LONG_MAX;
	endTime = LONG_MAX;
	remainingJobTime = LONG_MAX;
	slack = SHRT_MAX;
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
}

void Job::createTasks()
{
	std::string tempTask = "";
	unsigned char whitespaceCounter = 0;
	for(unsigned int i = 0; i < jobTasks.length(); i++)
	{
		tempTask += jobTasks[i];
		if(jobTasks[i] == ' ')
		{
			whitespaceCounter++;
		}
		if(whitespaceCounter == 2)
		{
			std::cout << tempTask << std::endl;
			tempTask = "";
			whitespaceCounter = 0;
		}
	}
}

unsigned short int Job::getID()const
{
	return ID;
}

unsigned long int Job::getRemainingJobTime()const
{
	return remainingJobTime;
}

void Job::setID(const unsigned short int anID)
{
	ID = anID;
}
