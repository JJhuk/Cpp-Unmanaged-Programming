#include <iostream>
#include "TimeSheet.h"

using namespace std;
using namespace lab3;

int main()
{
    lab3::TimeSheet employee1("John", 10);
    employee1.AddTime(4);
    employee1.AddTime(7);
    std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;


    system("pause");
    return 0;

	return 0;
}