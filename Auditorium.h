#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "ListProduction.h"

class Auditorium
{
private:
    unsigned int mID;
    ListProduction mProductions;
    unsigned int mSize;

public:
    Auditorium();
    Auditorium(unsigned int);
    void SetID(unsigned int);
    void SetSize(unsigned int);
    unsigned int GetSize() const;
    const ListProduction &GetData() const;
    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void BuyTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void UnreserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *);
    void AddProduction(const Date &, const char *);
    void PrintFreeTickets(const Date &, const char *) const;
    std::ostream &PrintReservedTickets(std::ostream &, const Date &,bool, const char * ) const;
    void PrintBoughtTickets(const Date &, const Date &, bool) const;
};

#endif