/*
 * Task.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Jimmy
 */

#ifndef SRC_TASK_HPP_
#define SRC_TASK_HPP_

#include "Job.hpp"

class Task {
	public:
		/**
		 * @fn Task()
		 * @brief Default contructor.
		 */
		Task();
		/**
		 * @fn Task(const unsigned short int aTaskTime, const unsigned short int aId, const unsigned short int machine, const unsigned short int a JobID)
		 * @brief Constructor.
		 */
		Task(const unsigned short int aTaskTime, const unsigned short int aID,
			 const unsigned short int machine, const unsigned short int aJobID);
		/**
		 * @fn virtual ~Task()
		 * @brief Destructor.
		 */
		virtual ~Task();
		/**
		 * @fn unsigned short int getTaskTime()const
		 * @brief Getter for taskTime.
		 * @returns The taskTime of a task.
		 */
		unsigned short int getTaskTime()const;
		/**
		 * @fn unsigned short int getID()const
		 * @brief Getter for ID.
		 * @return The ID of the Task.
		 */
		unsigned short int getID()const;
		/**
		 * @fn unsigned short int getMachine()const
		 * @brief Getter for Machine.
		 * @returns The machineID of the task.
		 */
		unsigned short int getMachine()const;
		/**
		 * @fn unsigned short int getJobID()const
		 * @brief Getter for JobID
		 * @returns The JobID of the Task.
		 */
		unsigned short int getJobID()const;
		/**
		 * @fn Task& operator=(const Task& aTask)
		 * @brief Assignment operator.
		 * @param aTask The Task to copy the attributes from.
		 */
		Task& operator=(const Task& aTask);
		/**
		 * @fn bool operator==(const Task& aTask)const
		 * @brief Comparison operator.
		 * @param aTask The Task to compare to.
		 */
		bool operator==(const Task& aTask)const;
	private:
		/**
		 * @var taskTime
		 * The time the task takes.
		 */
		unsigned short int taskTime;
		/**
		 * @var ID
		 * The ID of the Task.
		 */
		unsigned short int ID;
		/**
		 * @var machine
		 * The ID of the Machine the task has to be executed on.
		 */
		unsigned short int machine;
		/**
		 * @var jobID
		 * The ID of the Job where the Task belongs to.
		 */
		unsigned short int jobID;
};

#endif /* SRC_TASK_HPP_ */
