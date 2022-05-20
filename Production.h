#ifndef PRODUCTION_H
#define PRODUCTION_H
#include "Date.h"
#include "ListTickets.h"
#include "MyString.h"
#include <fstream>
class Production
{
private:
    Date mDate;
    MyString mName;
    ListTickets mTickets;

public:
    unsigned int PrintFreeSeats() const;
    unsigned int PrintReservedSeats() const;
    unsigned int PrintBoughtSeats() const;
    const MyString &GetName() const;
    unsigned int GetSize() const;
    const Date &GetDate() const;
    void SetDate(const Date &);
    void SetName(const MyString &);
    void ReserveTicket(unsigned int, unsigned int, const char *, const char *);
    void ReserveTicket(unsigned int, unsigned int, const char *);
    void BuyReservedSeat(unsigned int, unsigned int, const char *);
    void BuyFreeSeat(unsigned int, unsigned int, const char *);
    void BuyFreeSeat(unsigned int, unsigned int, const char *, const char *);
    void Print() const;
    void SetListTickets(unsigned int);
    void UnreserveSeat(unsigned int, unsigned int, const char *);
    void SetTickets(unsigned int);
};

#endif