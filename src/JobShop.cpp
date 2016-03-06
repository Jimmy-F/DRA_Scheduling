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


void JobShop::extractJobData(std::ifstream& jobData)
{
		std::vector<Machine> machines;
		std::string line;
		unsigned short int nJobs = 0;
		unsigned short int nMachines = 0;

		if (jobData.is_open())
		{
			std::getline(jobData, line);
			nJobs = getNumberOfJobs(line);
			nMachines = getNumberOfMachines(line);

			for (unsigned int i = 0; i < nJobs; i++)
			{
				std::string buffer;
				std::getline(jobData, buffer);
				Job job(i, buffer);
				jobList.push_back(job);
			}
			jobData.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
		}

		for (int i = 0; i < nMachines; i ++)
		{
			Machine m(i, true);
			machineList.push_back(m);
		}
}

void JobShop::scheduleJobs(std::ifstream& jobData)
{
	extractJobData(jobData);
	initializeJobList(jobData);
	std::vector<Job> completedJobs;
	while (jobList.size() != 0)
	{
		updateCriticalPath();
		updateSlackJobList();
		std::sort(jobList.begin(), jobList.end());
		setTasks();
		runMachines();

		for (Job& j : jobList)
		{
			if (j.getTaskList().size() == 0)
			{
				completedJobs.push_back(j);
				jobList.erase(std::find(jobList.begin(), jobList.end(),j));
			}
		}
		updateEndTimes();
	}
	printJobShop(completedJobs);
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

unsigned short int JobShop::getNumberOfJobs(std::string firstLine)
{
	std::string nJobsStr = "";
	unsigned short int nJobs = 0;

	for (unsigned int i = 0; i < firstLine.length(); i++)
	{
		if (firstLine[i] == ' ')
		{
			break;
		}
		nJobsStr += firstLine[i];
	}
	return nJobs = std::stoi(nJobsStr);
}

unsigned short int JobShop::getNumberOfMachines(std::string firstLine)
{
	std::string nMachinesStr = "";
	unsigned short int nMachines = 0;
	unsigned char spaceCounter = 0;

	for (unsigned int i = 0; i < firstLine.length(); i++)
	{
		if (spaceCounter >= 1 && firstLine[i] != ' ')
		{
			nMachinesStr += firstLine[i];
		}
		if (firstLine[i] == ' ')
		{
			spaceCounter++;
		}
	}
	return nMachines = std::stoi(nMachinesStr);
}

void JobShop::printJobShop(std::vector<Job> aJobList)
{
	std::sort(aJobList.begin(), aJobList.end(), [](const Job& j1, const Job& j2)
				  {return j1.getID() < j2.getID();});
	for (Job j : aJobList)
	{
		std::cout << j.getID() << ' ' << j.getStartTime() << ' ' << j.getEndTime() << std::endl;
	}
}

void JobShop::setTasks()
{
	for (Job& j : jobList)
	{
		if (j.getTaskList().size() != 0)
		{
			if (machineList[j.getTaskList()[0].getMachine()].getIdle())
			{
				if (j.hasStarted() == false)
				{
					j.setStartTime(j.getEndTime());
				}
				machineList[j.getTaskList()[0].getMachine()].setTask(j.getTaskList()[0]);
			}
		}
	}
}

void JobShop::runMachines()
{
	for (Machine& m : machineList)
	{
		if (m.getIdle() == false)
		{
			m.execute();
		}

		if (m.isTaskDone())
		{
			for (Job& j : jobList)
			{
				if (j.getID() == m.getTask().getJobID())
				{
					j.eraseTask();
					j.updateRemainingTime();
				}
			}
		}
	}
}

void JobShop::updateEndTimes()
{
	for (Job& j : jobList)
	{
		j.increaseEndTime();
	}
}













