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

    if (year < 2000)
    {
        throw 1;
    }
    else if (year > 2030)
    {
        throw 1;
    }
    else
    {
        mYear = year;
    }
}
void Date::SetMonth(const unsigned short month)
{
    bool isValid = true;

    if (month > 12)
    {
        throw 1;
    }
    else if (month < 1)
    {
        throw 1;
    }
    else
    {
        mMonth = month;
    }
}
void Date::SetDay(const unsigned short day)
{
    unsigned int month = GetMonth();
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        throw 1;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        throw 1;
    }
    else if (month == 2 && isYearLeap(GetYear()) && day > 29)
    {
        throw 1;
    }
    else if (month == 2 && !isYearLeap(GetYear()) && day > 28)
    {
        throw 1;
    }
    else
    {
        mDay = day;
    }

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
bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetDay()==rhs.GetDay()&&lhs.GetMonth()==rhs.GetMonth()&&lhs.GetYear()==rhs.GetYear();
}
unsigned int operator>(const Date& lhs, const Date& rhs)
{
    if(lhs.GetYear()>rhs.GetYear())
    {
        return true;
    }
    else if(lhs.GetYear()==rhs.GetYear()&&lhs.GetMonth()>rhs.GetMonth())
    {
        return true;
    }
    else if(lhs.GetYear()==rhs.GetYear()&&lhs.GetMonth()==rhs.GetMonth()&&lhs.GetDay()>rhs.GetDay())
    {
        return true;
    }
    return false;
}
unsigned int operator<(const Date& lhs, const Date& rhs)
{
    if(lhs>rhs)
    {
        return false;
    }
    return true;
}
std::ostream &operator<<(std::ostream &stream, const Date &date)
{
    
    stream << date.GetYear()<<'.'<<date.GetMonth()<<'.'<<date.GetDay();
    return stream;
}
// int main(int argc, char const *argv[])
// {
//     Date date = Date(100, 10, 2001);
//     std::cout << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear() << std::endl;
//     return 0;
// }
