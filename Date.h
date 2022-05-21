#ifndef DATE_H
#define DATE_H
#include <fstream>

class Date
{
private:
    unsigned short mYear;
    unsigned short mMonth;
    unsigned short mDay;

public:
    void SetYear(const unsigned short);
    void SetMonth(const unsigned short);
    void SetDay(const unsigned short);
    const unsigned short GetYear() const;
    const unsigned short GetMonth() const;
    const unsigned short GetDay() const;
    Date();
    Date(const unsigned short, const unsigned short, const unsigned short);
    friend std::ostream &operator<<(std::ostream &, const Date &);
    Date& operator=(const char*);
};
bool operator==(const Date &, const Date &);
unsigned int operator>(const Date &, const Date &);
unsigned int operator<(const Date &, const Date &);

#endif