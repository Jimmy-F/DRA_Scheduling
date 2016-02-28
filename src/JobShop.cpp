/*
 * JobShop.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "JobShop.hpp"
#include "Job.hpp"
#include <iostream>

JobShop::JobShop()
{

}

JobShop::JobShop(std::vector<Job>aJobList):jobList(aJobList)
{

}

JobShop::~JobShop()
{

}

std::vector<Job> JobShop::getJobList()const
{
	return jobList;
}

void JobShop::setJobList(const std::vector<Job> aJobList)
{
	jobList = aJobList;
}

std::vector<Job> JobShop::extractJobData(std::ifstream& jobData)
{
		std::vector<std::string> jobsStr;
		std::vector<Job> jobs;
		std::string jobMachineLine;
		std::string line;

		if (jobData.is_open())
		{
			std::getline(jobData, jobMachineLine);

			for (int i = 0; i < (int)jobMachineLine[0] - '0'; i++)
			{
				std::string buffer;
				std::getline(jobData, buffer);
				Job job(i, buffer);
				jobs.push_back(job);
			}
			jobData.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
		}
		return jobs;
}

void JobShop::scheduleJobs(std::ifstream& jobData)
{
	jobList = extractJobData(jobData);
	for(Job n : jobList) {
		n.createTasks();
		n.updateRemainingTime();
	}
}
