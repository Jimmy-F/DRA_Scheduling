#include "JobShop.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	std::ifstream jobData (argv[1]);

	JobShop js;
	js.scheduleJobs(jobData);

	return 0;
}
