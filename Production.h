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
    Production();
    Production(unsigned int);
    Production(const Date&, const char*, unsigned int);
    const MyString &GetName() const;
    unsigned int GetSize() const;
    const Date &GetDate() const;
    void SetDate(const Date &);
    void SetName(const char *);
    // void ReserveTicket(unsigned int, unsigned int, const char *);
    // void BuyReservedSeat(unsigned int, unsigned int, const char *);
    // void BuyFreeSeat(unsigned int, unsigned int, const char *);
    void ReserveTicket(const Date &date, const char *name, unsigned int, unsigned int, const char *, const char *);
    void BuyTicket(const Date &date, const char *name, unsigned int, unsigned int, const char *, const char *);
    //void SetListTickets(unsigned int);
    void UnreserveTicket(const Date &date, const char *name, unsigned int, unsigned int, const char *);
    unsigned int PrintFreeTickets() const;
    unsigned int PrintReservedTickets() const;
    unsigned int PrintBoughtTickets() const;
    bool CheckProdction(const Date&, const char*);
};

#endif