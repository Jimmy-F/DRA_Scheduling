/*
 * Job.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Job.hpp"

Job::Job()
{
	ID = 0;
	startTime = 0;
	endTime = 0;
}

Job::Job(unsigned short int aID,unsigned long int aStartTime, unsigned long int aEndTime)
	:ID(aID),startTime(aStartTime),endTime(aEndTime)
{

}

Job::~Job()
{
}

