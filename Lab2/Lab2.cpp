#include "Lab2.h"
#include <string>
#include <iomanip>

//PrintIntegers()와 PrintMaxFloat()는 반드시 첫 번째 매개변수 in에서 입력을 읽어 와야 합니다.std::cin을 사용하면 0점 처리 합니다.
//PrintIntegers()와 PrintMaxFloat()는 반드시 두 번째 매개변수 out에 출력을 해야 합니다.std::cout을 사용하면 0점 처리 합니다.
//PrintIntegers()과 PrintMaxFloat()는 반드시 각 함수의 스펙에 따라 출력 포맷을 맞춰야 합니다.
//부동 소수점 값을 다룰 때에는 반드시 double 대신 float를 써야 합니다.

namespace lab2
{
    //일련의 정수들을 입력 받아 각 정수를 8진수, 10진수, 16진수로 출력합니다.출력 형식은 아래와 일치해야 합니다.
    //
    //    .........oct........dec......hex⤶
    //    ------------.----------.--------⤶
    //    ..........64.........52.......34⤶
    //    .........146........102.......66⤶
    //    ...........1..........1........1⤶
    //    ........4516.......2382......94E⤶
    //일련의 정수들을 입력 받아 각 정수를 8진수, 10진수, 16진수로 출력합니다.출력 형식은 아래와 일치해야 합니다.
    //
    //    .........oct........dec......hex⤶
    //    ------------.----------.--------⤶
    //    ..........64.........52.......34⤶
    //    .........146........102.......66⤶
    //    ...........1..........1........1⤶
    //    ........4516.......2382......94E⤶
   //입력값 오류처리
   //    입력에는 최소한 하나의 정수가 있을 것입니다.
   //    입력은 다음으로만 구성됩니다.
   //    양의 정수
   //    공백
   //    문자열
   //    모든 문자열은 무시해야 합니다.
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
        float max = FLT_MIN;
        float number;
        std::string trash;
        while (true)
        {
            in >> number;
            if (!in.fail())
            {
                max = max < number ? number : max;
                out << "     " << std::setw(15) << std::showpos << std::showpoint << std::internal << number << std::endl;             
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
        out << "max: " << std::setw(15) << std::showpos << std::showpoint << std::internal << max << std::endl;
    }
}