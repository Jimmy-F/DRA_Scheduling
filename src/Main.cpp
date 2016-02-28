#include <fstream>
#include "JobShop.hpp"
#include "Job.hpp"

int main(int argc, char **argv)
{
	std::ifstream jobData ("src/jobData.txt");

	JobShop js;
	js.extractJobData(jobData);

	return 0;
}
