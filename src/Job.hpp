/*
 * Job.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#ifndef SRC_JOB_HPP_
#define SRC_JOB_HPP_

class Job {
public:
	Job();
	Job(unsigned short int aID,unsigned long int aStartTime, unsigned long int aEndTime);
	virtual ~Job();
private:
	unsigned short int ID;
	unsigned long int startTime;
	unsigned long int endTime;
};

#endif /* SRC_JOB_HPP_ */
