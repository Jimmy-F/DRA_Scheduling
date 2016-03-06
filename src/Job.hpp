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

class Task;
class Job {
	public:
		/**
		 * @fn Job()
		 * @brief Default constructor.
		 */
		Job();
		/**
		 * @fn Job(unsigned short int aID, std::string& aJobTask)
		 * @brief Constructor
		 * @param aID The ID to give the job
		 * @param aJobTask A string containing information about the tasks the job has
		 */
		Job(unsigned short int aID, std::string& aJobTask);
		/**
		 * @fn virtual ~Job()
		 * @brief Destructor.
		 */
		virtual ~Job();

		//Methods
		/**
		 * @fn updateRemainingTime()
		 * @brief Updates the remaining time the tasks should take.
		 */
		void updateRemainingTime();
		/**
		 * @fn void createTasks()
		 * @brief Creates the tasks for the Job.
		 */
		void createTasks();
		/**
		 * @fn unsigned short int parseTaskMachine(std::string aTaskString)
		 * @brief Parses the string to get the machine.
		 * @param aTaskString The string to parse from.
		 * @returns The machine the task has.
		 */
		unsigned short int parseTaskMachine(std::string aTaskString);
		/**
		 * @fn unsigned short int parseTaskTime(std::string aTaskString)
		 * @brief Parses The time a task takes from a string.
		 * @param aTaskString The string to get the time of a task from.
		 * @returns The time the task takes.
		 */
		unsigned short int parseTaskTime(std::string aTaskString);

		//Getters and Setters
		/**
		 * @fn unsigned long int getRemainingTime()const
		 * @brief Getter for remainingTime.
		 * @returns The remaining time of Job.
		 */
		unsigned long int getRemainingTime()const;
		/**
		 * @fn setRemainingTime(unsigned long int aRemainingTime)
		 * @brief Setter remainingTime.
		 * @param aRemainingTime The remaining time to give to a job.
		 */
		void setRemainingTime(unsigned long int aRemainingTime);
		/**
		 * @fn unsigned short int getID()const
		 * @brief Getter for ID.
		 * @return The ID of a Job.
		 */
		unsigned short int getID()const;
		/**
		 * @fn void setID(const unsigned short int anID)
		 * @brief Setter for ID.
		 * @param anID The ID to set to a Job.
		 */
		void setID(const unsigned short int anID);
		/**
		 * @fn std::string getJobTasks()const
		 * @brief Getter for jobTasks.
		 * @returns The JobTasks string.
		 */
		std::string getJobTasks()const;
		/**
		 * @fn void setJobTasks(const char* aJobTask)
		 * @brief Setter for jobTasks.
		 * @param aJobTask The char*(string) to set the jobTasks string to.
		 */
		void setJobTasks(const char* aJobTask);
		/**
		 * @fn unsigned short int getSlack()const
		 * @brief Getter for slack.
		 * @returns The slack of a Job.
		 */
		unsigned short int getSlack()const;
		/**
		 * @fn void setSlack(const unsigned short int newSlack)
		 * @brief Setter for slack.
		 * @param newSlack The new slack to set on the Job.
		 */
		void setSlack(const unsigned short int newSlack);
		/**
		 * @fn void calculateSlack(const unsigned short int aCriticalPath)
		 * @brief Calculates slack.
		 * @pre aCriticalPath is a higher number or the same as the remaining time of a Job.
		 * @post The slack has been calculated and updated.
		 * @param aCriticalPath The critical path to calculate the slack from.
		 * This function calculates the slack. The slack is based on the critical path
		 * minus the remaining time of a Job.
		 */
		void calculateSlack(const unsigned short int aCriticalPath);
		/**
		 * @fn bool operator<(const Job& aJob)const
		 * @brief Lesser than operator.
		 * @pre Both the Jobs have slack.
		 * @post True or false is given.
		 * @param aJob The Job to check the slack from.
		 * This function checks which Job has the lesser slack.
		 */
		bool operator<(const Job& aJob)const;
		/**
		 * @fn bool operator==(const Job& aJob)const
		 * @brief Comparison operator.
		 * @pre Both Jobs have an ID.
		 * @post True or false is given based on the ID of both the IDs.
		 * @param aJob The Job to check the ID from.
		 * This function compares both the IDs from the Jobs. If the Jobs have the same ID
		 * the function will return true, else it will return false.
		 */
		bool operator==(const Job& aJob)const;
		/**
		 * @fn std::vector<Task> getTaskList()const
		 * @brief Getter for taskList.
		 * @returns The taskList from the Job.
		 */
		std::vector<Task> getTaskList()const;
		/**
		 * @fn void eraseTask()
		 * @brief Erases task.
		 * This function erases the first task in the taskList.
		 */
		void eraseTask();
		/**
		 * @fn void increaseEndTime()
		 * @brief Increases endTime.
		 */
		void increaseEndTime();
		/**
		 * @fn bool hasStarted()const
		 * @brief Gives the started variable.
		 * This function returns if the Job has started or not.
		 */
		bool hasStarted()const;
		/**
		 * @fn void setStartTime(const unsigned long int aStartTime)
		 * @brief Setter for startTime
		 * @param aStartTime The startTime to give to the Job.
		 */
		void setStartTime(const unsigned long int aStartTime);
		/**
		 * @fn unsigned long int getStartTime()const
		 * @brief Getter for startTime.
		 * @returns The startTime of the Job.
		 */
		unsigned long int getStartTime()const;
		/**
		 * @fn unsigned long int getEndTime()const
		 * @brief Getter for endTime.
		 * @returns The endTime of the Job.
		 */
		unsigned long int getEndTime()const;

	private:
		/**
		 * @var ID
		 * The ID of the Job.
		 */
		unsigned short int ID;
		/**
		 * @var startTime
		 * The time the Job has started.
		 */
		unsigned long int startTime;
		/**
		 * @var endTime
		 * The time the Job has ended.
		 */
		unsigned long int endTime;
		/**
		 * @var remainingTime
		 * The time of all tasks in the Job.
		 */
		unsigned long int remainingTime;
		/**
		 * @var slack
		 * Critical path - the remaining time.
		 */
		unsigned short int slack;
		/**
		 * @var jobTasks
		 * A string containing information about the Job.
		 */
		std::string jobTasks;
		/**
		 * @var taskList
		 * A vector containing tasks of the Job.
		 */
		std::vector<Task>taskList;
		/**
		 * @var started
		 * A boolean if the Job has started or not.
		 */
		bool started;

};


#endif /* SRC_JOB_HPP_ */
