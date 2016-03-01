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
	//Constructors
	Job();
	Job(unsigned short int aID, std::string& aJobTask);
	virtual ~Job();

	//Methods
	void updateRemainingTime();
	void createTasks();
	unsigned short int parseTaskMachine(std::string aTaskString);
	unsigned short int parseTaskTime(std::string aTaskString);

	//Getters and Setters
	unsigned long int getRemainingTime()const;
	void setRemainingTime(unsigned long int aRemainingTime);
	unsigned short int getID()const;
	void setID(const unsigned short int anID);
	std::string getJobTasks()const;
	void setJobTasks(const char* aJobTask);
	void calculateSlack(const unsigned short int aCriticalPath);
	bool operator<(const Job& aJob)const;

private:
	unsigned short int ID;
	unsigned long int startTime;
	unsigned long int endTime;
	unsigned long int remainingTime;
	unsigned short int slack;
	std::string jobTasks;
	std::vector<Task>taskList;
};

#endif /* SRC_JOB_HPP_ */
