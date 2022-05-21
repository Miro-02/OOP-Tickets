#include "Date.h"
#include <iostream>
#include <cstring>
#include <iomanip>

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
Date &Date::operator=(const char *date)
{
    cout<<date;
    char day[3], month[3], year[4];
    day[0] = date[0];
    day[1] = date[1];
    month[0] = date[3];
    month[1] = date[4];
    for (size_t i = 0; i < 4; i++)
    {
        year[i] = date[i+6];
    }
    SetYear(atoi(year));
    SetMonth(atoi(month));
    SetDay(atoi(day));
    return *this;
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

    if (year < 2000 || year > 2030)
    {
        cout << "Year must be after 2000 and before 2030." << endl;
        throw 1;
    }
    mYear = year;
}
void Date::SetMonth(const unsigned short month)
{
    bool isValid = true;

    if (month > 12 || month < 1)
    {
        cout << "Month must be between 1 and 12." << endl;
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
    if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || day < 1)
    {
        cout << "Day must be between 1 and 31" << endl;
        throw 1;
    }
    else if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || day < 1)
    {
        cout << "Day must be between 1 and 30" << endl;
        throw 1;
    }
    else if ((month == 2 && isYearLeap(GetYear()) && day > 29) || day < 1)
    {
        cout << "Day must be between 1 and 29" << endl;
        throw 1;
    }
    else if ((month == 2 && !isYearLeap(GetYear()) && day > 28) || day < 1)
    {
        cout << "Day must be between 1 and 28" << endl;
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
bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs.GetDay() == rhs.GetDay() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetYear() == rhs.GetYear();
}
unsigned int operator>(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() > rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() > rhs.GetMonth())
    {
        return true;
    }
    else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() > rhs.GetDay())
    {
        return true;
    }
    return false;
}
unsigned int operator<(const Date &lhs, const Date &rhs)
{
    if (lhs > rhs)
    {
        return false;
    }
    return true;
}
std::ostream &operator<<(std::ostream &stream, const Date &date)
{

    stream << date.GetYear() << '.' << setw(2) << setfill('0') << date.GetMonth() << '.' << setw(2) << setfill('0') << date.GetDay();
    return stream;
}
// int main(int argc, char const *argv[])
// {
//     Date date = Date();
//     char date2[20] = "21.05.2022";
//     date = date2;
//     cout<<date;
//     return 0;
// }
