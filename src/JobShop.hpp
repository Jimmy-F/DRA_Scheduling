/*
 * JobShop.hpp
 *
 *  Created on: 28 feb. 2016
 *      Author: Christus
 */

#ifndef SRC_JOBSHOP_HPP_
#define SRC_JOBSHOP_HPP_

#include "Job.hpp"
#include <vector>
#include <fstream>

class JobShop {
public:
	JobShop();
	JobShop(std::vector<Job>aJobList);
	virtual ~JobShop();
	std::vector<Job> extractJobData(std::ifstream& jobData);
private:
	std::vector<Job>jobList;
};

#endif /* SRC_JOBSHOP_HPP_ */
