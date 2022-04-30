#include "Date.h"
#include <iostream>
using namespace std;

bool isYearLeap(const unsigned short year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    return false;
}

const unsigned short Date::GetYear() const
{
    return mYear;
}
const unsigned short Date::GetMonth() const
{
    return mMonth;
}
const unsigned short Date::GetDay() const
{
    return mDay;
}

void Date::SetYear(const unsigned short year)
{
    // try
    // {
    if (year < 2000)
    {
        mYear = 2000;
        // throw 1;
    }
    else if (year > 2030)
    {
        mYear = 2030;
        // throw 2;
    }
    else
    {
        mYear = year;
    }
    // }
    // catch (int e)
    // {
    //     std::cout<<"Invalid year!"<<" "<<"Error code: "<<e<<std::endl;
    // }
}
void Date::SetMonth(const unsigned short month)
{
    bool isValid = true;
    // try
    // {
    if (month > 12)
    {
        mMonth = 12;
        // throw 1;
    }
    else if (month < 1)
    {
        mMonth = 1;
        // throw 2;
    }

    // }
    // catch (int e)
    // {
    //     std::cout << "Invalid month!"<< " "<< "Error code: " << e << std::endl;
    // }
}
void Date::SetDay(const unsigned short day)
{
    unsigned int month = GetMonth();
    // try
    // {
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        mDay = 31;
        // throw 1;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        mDay = 30;
        // throw 2;
    }
    else if (month == 2 && isYearLeap(GetYear()) && day > 29)
    {
        mDay = 29;
        // throw 3;
    }
    else if (month == 2 && !isYearLeap(GetYear()) && day > 28)
    {
        mDay = 28;
        // throw 4;
    }
    else
    {
        mDay = day;
    }
    // }
    // catch (int e)
    // {
    //     std::cout << "Invalid day!"<< " "<< "Error code: " << e << std::endl;
    // }
}

Date::Date(const unsigned short day, const unsigned short month, const unsigned short year)
{
    SetYear(year);
    SetMonth(month);
    SetDay(day);
}

Date::Date()
{
    SetYear(2000);
    SetMonth(1);
    SetDay(1);
}

// int main(int argc, char const *argv[])
// {
//     Date date = Date(-10, 15, 2001);
//     std::cout << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear() << std::endl;
//     return 0;
// }
