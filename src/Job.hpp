/*
 * Job.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#ifndef SRC_JOB_HPP_
#define SRC_JOB_HPP_

#include <vector>
#include <string>
#include "Task.hpp"

class Job {
public:
	Job();
	Job(unsigned short int aID, std::string& aJobTask);
	virtual ~Job();
	std::string getJobTasks()const;
	void setJobTasks(const char* aJobTask);
	void calculateTotalRemainingTime();
	unsigned short int getID()const;
	void setID(const unsigned short int anID);
	unsigned long int getRemainingJobTime()const;
private:
	unsigned short int ID;
	unsigned long int startTime;
	unsigned long int endTime;
	unsigned long int remainingJobTime;
	std::string jobTasks;
	std::vector<Task>taskList;
};

#endif /* SRC_JOB_HPP_ */
