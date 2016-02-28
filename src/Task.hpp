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
	Task(unsigned short int aTaskTime,unsigned short int aID);
	virtual ~Task();
private:
	unsigned short int taskTime;
	unsigned short int ID;
};

#endif /* SRC_TASK_HPP_ */
