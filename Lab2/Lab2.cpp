#include "Lab2.h"
#include <string>
#include <iomanip>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;
		std::string trash;
		//              12          10          8
		out << "         oct        dec      hex\n";
		out << "------------ ---------- --------\n";


		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				out << std::setw(12) << std::oct << number << " ";
				out << std::setw(10) << std::dec << number << " ";
				out << std::setw(8) << std::uppercase << std::hex << number << std::endl;
				continue;
			}
			if (in.eof())
			{
				in.clear(); //clear하고 trash에 비워줘야함.
				break;
			}
			in.clear(); //clear하고 trash에 비워줘야함.
			in >> trash;
		}
	}


	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float max = -FLT_MAX;
		float number;
		std::string trash;
		while (true)
		{
			in >> number;
			if (!in.fail())
			{
				max = max < number ? number : max;
				out << "     " << std::setw(15) << std::showpos << std::showpoint << std::fixed << std::setprecision(3) << std::internal << number << std::endl;
				continue;
			}
			if (in.eof())
			{
				in.clear();
				break;
			}
			in.clear();
			in >> trash;
		}
		out << "max: " << std::setw(15) << std::showpos << std::showpoint << std::fixed << std::setprecision(3) << std::internal << max << std::endl;
	}
}