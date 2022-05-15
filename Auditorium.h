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
    ~Auditorium();
    void SetID(unsigned int);
    void SetSize(unsigned int);
    unsigned int GetSize() const;
    const ListProduction &GetData() const;
    void SetListTickets(unsigned int);
    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyReservedSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyFreeSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyFreeSeat(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    //void Print(const Date &, const char *) const;
    void UnreserveSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void AddProduction(const Date &, const char *);
    void PrintFreeSeats(const Date &, const char *) const;
    std::ostream &PrintReservedSeats(std::ostream &, const Date &, const char *) const;
    std::ostream &PrintReservedSeatsForDate(std::ostream &, const Date &) const;
    std::ostream &PrintAllReservedSeats(std::ostream &) const;
    void PrintBoughtSeats(const Date &, const Date &) const;
    void PrintAllBoughtSeats() const;
};

#endif