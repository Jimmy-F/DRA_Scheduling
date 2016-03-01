/*
 * Machine.hpp
 *
 *  Created on: 1 mrt. 2016
 *      Author: Christus
 */

#ifndef SRC_MACHINE_HPP_
#define SRC_MACHINE_HPP_

#include "Job.hpp"

class Machine {
public:
	Machine();
	Machine(const unsigned short int aMachineNumber);
	virtual ~Machine();
	unsigned short int executeTask(Job aJob);
	unsigned short int getMachineNumber();
private:
	unsigned short int machineNumber;
};

#endif /* SRC_MACHINE_HPP_ */
