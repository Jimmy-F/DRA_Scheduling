/*
 * Machine.hpp
 *
 *  Created on: Mar 3, 2016
 *      Author: jimmy
 */

#ifndef SRC_MACHINE_HPP_
#define SRC_MACHINE_HPP_

#include "Task.hpp"

class Machine
{
	public:
		/**
		 * @fn Machine()
		 * @brief Default constructor.
		 */
		Machine();
		/**
		 * @fn Machine(const unsigned short int aMachineID, const bool state
		 * @brief Constructor
		 * @param aMachineID ID to give to the machine.
		 * @param state The state to give to the machine.
		 */
		Machine(const unsigned short int aMachineID, const bool state);
		/**
		 * @fn virtual ~Machine()
		 * @brief Destructor
		 */
		virtual ~Machine();
		/**
		 * @fn setRunTime(const unsigned long int aRunTime)
		 * @brief Setter for runTime.
		 * @param aRunTime The time to give to the runTime variable to the machine.
		 */
		void setRunTime(const unsigned long int aRunTime);
		/**
		 * @fn unsigned short int getMachineID()const
		 * @brief Getter for machineID.
		 * @returns The machineID.
		 */
		unsigned short int getMachineID()const;
		/**
		 * @fn unsigned long int getRunTime()const
		 * @brief Getter for runTime
		 * @returns The runTime of the Machine.
		 */
		unsigned long int getRunTime()const;
		/**
		 * @fn bool getIdle()const
		 * @brief Getter for idle.
		 * @returns If the Machine is idle or not.
		 */
		bool getIdle()const;
		/**
		 * @fn void setIdle(const bool state)
		 * @brief Setter for idle.
		 * @param state The state to set the Machine.
		 * The Machine only has 2 states; idle or not idle.
		 */
		void setIdle(const bool state);
		/**
		 * @fn Task getTask()const
		 * @brief Getter for Task.
		 * @returns The task of the Machine.
		 */
		Task getTask()const;
		/**
		 * @fn void setTask(const Task& aTask)
		 * @brief Setter for the task.
		 * @param aTask The task to give to the machine.
		 */
		void setTask(const Task& aTask);
		/**
		 * @fn void execute()
		 * @brief Executes the task on a machine
		 * This function increases the runTime of the machine which simulates
		 * the execution of a task.
		 */
		void execute();
		/**
		 * @fn bool isTaskDone()
		 * @brief Checks if the task from the machine is done.
		 */
		bool isTaskDone();
	private:
		/**
		 * @var machineID
		 * The ID of the machine.
		 */
		unsigned short int machineID;
		/**
		 * @var runTime
		 * The time the Machine has been running a task.
		 */
		unsigned long int runTime;
		/**
		 * @var idle
		 * If the Machine is idle or not.
		 */
		bool idle;
		/**
		 * @var task
		 * The task of a Machine.
		 */
		Task task;
};

#endif /* SRC_MACHINE_HPP_ */

