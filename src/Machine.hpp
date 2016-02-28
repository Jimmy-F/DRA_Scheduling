/*
 * Machine.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#ifndef SRC_MACHINE_HPP_
#define SRC_MACHINE_HPP_

class Machine {
public:
	Machine();
	Machine(unsigned char aID);
	virtual ~Machine();
private:
	unsigned char ID;
};

#endif /* SRC_MACHINE_HPP_ */
