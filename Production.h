#ifndef PRODUCTION_H
#define PRODUCTION_H
#include "Date.h"
#include "ListTickets.h"
#include "MyString.h"

class Production
{
private:
    Date mDate;
    MyString mName;
    ListTickets mTickets;
public:
    void PrintFreeSeats() const;
    void PrintReservedSeats() const;
    unsigned int BoughtTickets() const;
};

#endif