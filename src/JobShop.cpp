/*
 * JobShop.cpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#include "JobShop.hpp"
#include "Job.hpp"
#include <iostream>
#include <algorithm>

JobShop::JobShop() :
	criticalPath(0)
{

}

JobShop::JobShop(std::vector<Job>aJobList) :
		jobList(aJobList), criticalPath(0)
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
	initializeJobList(jobData);
	updateCriticalPath();
	updateSlackJobList();

}

void JobShop::updateCriticalPath()
{
	std::vector<Job>::iterator it = std::max_element(jobList.begin(), jobList.end(),
				[](const Job& j1, const Job& j2)
				{return j1.getRemainingTime() < j2.getRemainingTime();}
	);
	criticalPath = jobList[std::distance(jobList.begin(), it)].getRemainingTime();
}

void JobShop::initializeJobList(std::ifstream& jobData)
{
	jobList = extractJobData(jobData);
	for(Job& n : jobList)
		{
			n.createTasks();
			n.updateRemainingTime();
		}
}

void JobShop::updateSlackJobList()
{
	for (Job& n : jobList)
		{
			n.calculateSlack(criticalPath);
		}
}
