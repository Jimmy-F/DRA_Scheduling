#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<std::string> jobs;
	std::string jobMachineLine;
	std::string line;
	std::ifstream jobData ("src/jobData.txt");

	if (jobData.is_open())
	{
		std::getline(jobData, jobMachineLine);
		std::cout << jobMachineLine << std::endl;

		for (int i = 0; i < (int)jobMachineLine[0] - '0'; i++)
		{
			std::string buffer;
			std::getline(jobData, buffer);
			jobs.push_back(buffer);
		}
		jobData.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}


	for (const std::string n : jobs)
	{
		std::cout << n << std::endl;
	}

	std::cout << jobs.size() << std::endl;

	  return 0;
}
