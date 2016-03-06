/*
 * JobShop.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Jimmy
 */

#ifndef SRC_JOBSHOP_HPP_
#define SRC_JOBSHOP_HPP_

#include "Job.hpp"
#include "Machine.hpp"
#include <vector>
#include <fstream>

/**
 * @class JobShop
 */
class JobShop {
	public:
		/**
		 * @fn JobShop()
		 * @brief Default contructor.
		 */
		JobShop();
		/**
		 * @fn virtual ~JobShop()
		 * @brief Destructor.
		 */
		virtual ~JobShop();
		/**
		 * @fn std::vector<Job> getJobList()const
		 * @brief Getter jobList
		 * @returns The Job vector from the JobShop object.
		 */
		std::vector<Job> getJobList()const;
		/**
		 * @fn void setJobList(const std::vector<Job> aJobList)
		 * @brief Setter for jobList.
		 * @param aJobList The Job vector to set the jobList to.
		 */
		void setJobList(const std::vector<Job> aJobList);
		/**
		 * @fn std::vector<Job> extractJobData(std::ifstream& jobData)
		 *
		 * @pre jobData is a textfile containing job data. This file has to have
		 * a certain structure like the example.
		 *
		 * @post A Job vector has been created. The objects in the vector are initialized
		 * containing their string jobTasks.
		 *
		 * @param jobData The file to extract the data from
		 *
		 * @returns A vector containing initialized Jobs
		 *
		 * @brief Extracts job data from a file
		 *
		 * This function looks into the data file and creates a vector of Jobs
		 * based on the data in the file. The Jobs in the vector also are initialized
		 * containing a string jobTasks which is also extracted from the data.
		 */
		void extractJobData(std::ifstream& jobData);
		/**
		 * @fn void scheduleJobs(std::ifstream& jobData)
		 * @brief Schedules jobs
		 * @pre The jobData file is a text file which has the same structure
		 * as the example
		 * @post All the jobs are executed and an output of the time per job
		 * has been printed.
		 * @param jobData The file to read data from
		 *
		 */
		void scheduleJobs(std::ifstream& jobData);
		/**
		 * @fn void updateCriticalPath()
		 * @pre All the jobs from jobList have a remainingTime
		 * @post criticalPath has been updated
		 * @brief Updates criticalPath
		 * This function reads all the remaining time of the jobs and takes
		 * the highest remaining time. This time will be the new criticalPath,
		 */
		void updateCriticalPath();
		/**
		 * @fn void initializeJobList(std::ifstream& jobData)
		 * @pre
		 */
		void initializeJobList(std::ifstream& jobData);
		/**
		 * @fn void updateSlackJobList()
		 * @brief Updates the slack per available job,
		 *
		 */
		void updateSlackJobList();
		/**
		 * @fn unsigned short int getNumberOfJobs(std::string firstLine)
		 * @brief Retrieves the number of jobs from the string.
		 * @pre The first line from the data has been given as parameter.
		 * @post The number of jobs has been retrieved.
		 * @param firstLine The string to get the number of jobs from.
		 * @returns The number of jobs.
		 */
		unsigned short int getNumberOfJobs(std::string firstLine);
		/**
		 * @fn unsigned short int getNumberOfMachines(std::string firstLine)
		 * @brief Retrieves the number of machines from the string.
		 * @pre The string is the first line from the data file.
		 * @post The number of machines has been retrieved.
		 * @param firstLine The string to get the number of machines from.
		 * @returns The number of machines
		 */
		unsigned short int getNumberOfMachines(std::string firstLine);
		/**
		 * @fn void printJobShop(std::vector<Job> aJobList)
		 * @brief Prints the start time and end time per completed job.
		 * @pre All the jobs are completed.
		 * @post Prints the start and end time per job.
		 * @param aJobList The completed job vector.
		 */
		void printJobShop(std::vector<Job> aJobList);
		/**
		 * @fn void setTasks()
		 * @brief Assigns tasks to machines.
		 * If a machine is available a task will be assigned to it. It will loop
		 * through the jobList, which is sorted on slack.
		 */
		void setTasks();
		/**
		 * @fn void runMachines()
		 * @brief Runs the machines and erases tasks when completed.
		 * A machine will execute a task when a task is set for it. Also this function
		 * will erase the task from a job when the machine has completed the task
		 */
		void runMachines();
		/**
		 * @fn void updateEndTime()
		 * @brief Increases the end time per job
		 */
		void updateEndTimes();

	private:
		/**
		 * @var jobList
		 * The jobList contains all the jobs which are to be executed.
		 */
		std::vector<Job>jobList;
		/**
		 * @var machineList
		 * The machineList contains all the machines that will execute the tasks.
		 */
		std::vector<Machine>machineList;
		/**
		 * @var criticalPath
		 * The criticalPath is the highest remaining time from the jobList
		 */
		unsigned short int criticalPath;
};

#endif /* SRC_JOBSHOP_HPP_ */
