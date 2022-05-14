#ifndef DATE_H
#define DATE_H

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
};
bool operator==(const Date& , const Date& );

#endif