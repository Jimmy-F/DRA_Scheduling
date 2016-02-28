/*
 * Task.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "Task.hpp"

Task::Task()
{
	taskTime = 0;
	ID = 0;
}

Task::Task(unsigned short int aTaskTime, unsigned short int aID)
	:taskTime(aTaskTime),ID(aID)
{

}

Task::~Task()
{

}

