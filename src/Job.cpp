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
	remainingTime = LONG_MAX;
	slack = SHRT_MAX;
}

Job::Job(unsigned short int aID, std::string& aJobTask)
	:ID(aID),jobTasks(aJobTask)
{
	startTime = LONG_MAX;
	endTime = LONG_MAX;
	remainingTime = LONG_MAX;
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

void Job::updateRemainingTime()
{
	unsigned long int newRemainingTime = 0;
	for(Task t : taskList)
	{
		newRemainingTime += t.getTaskTime();
	}
	setRemainingTime(newRemainingTime);
}

unsigned long int Job::getRemainingTime()const
{
	return remainingTime;
}

void Job::setRemainingTime(unsigned long int aRemainingTime)
{
	remainingTime = aRemainingTime;
}

void Job::createTasks()
{
	std::string tempTask = "";
	unsigned short int taskID = 0;
	unsigned short int whitespaceCounter = 0;
	for(unsigned int i = 0; i < jobTasks.length(); i++)
	{
		tempTask += jobTasks[i];
		if(jobTasks[i] == ' ')
		{
			whitespaceCounter++;
		}
		if(whitespaceCounter == 2 || i+1 == jobTasks.length())
		{
			taskList.push_back(Task(parseTaskTime(tempTask),taskID,parseTaskMachine(tempTask)));
			taskID++;
			tempTask = "";
			whitespaceCounter = 0;
		}
	}
}

unsigned short int Job::parseTaskMachine(std::string aTaskString)
{
	std::string taskMachineString = "";
	unsigned short int taskTime = 0;
	for(unsigned int i = 0;i < aTaskString.length();i++)
	{
		if(aTaskString[i] == ' ')
		{
			break;
		}
		else
		{
			taskMachineString += aTaskString[i];
		}
	}
	taskTime = std::stoi(taskMachineString);
	return taskTime;
}

unsigned short int Job::parseTaskTime(std::string aTaskString)
{
	std::string taskTimeString = "";
	unsigned short int machineNumber;
	unsigned char whitespaceCounter = 0;
	for(unsigned int i = 0; i < aTaskString.length();i++)
	{
		if(aTaskString[i] == ' ')
		{
			whitespaceCounter++;
		}
		if(whitespaceCounter == 1)
		{
			taskTimeString += aTaskString[i];
		}
	}
	machineNumber = std::stoi(taskTimeString);
	return machineNumber;
}

unsigned short int Job::getID()const
{
	return ID;
}

void Job::setID(const unsigned short int anID)
{
	ID = anID;
}
