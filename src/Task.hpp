/*
 * Task.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#ifndef SRC_TASK_HPP_
#define SRC_TASK_HPP_

class Task {
public:
	Task();
	Task(unsigned short int aTaskTime,unsigned short int aID, unsigned short int machine);
	virtual ~Task();
	unsigned short int getTaskTime()const;
	unsigned short int getID()const;
	unsigned short int getMachine()const;
private:
	unsigned short int taskTime;
	unsigned short int ID;
	unsigned short int machine;
};

#endif /* SRC_TASK_HPP_ */
