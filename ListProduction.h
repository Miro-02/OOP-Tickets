#ifndef LISTPRODUCTION_H
#define LISTPRODUCTION_H
#include "Production.h"

class ListProduction
{
private:
    Production *mProduction;
    unsigned int mSize;
    void Free();
    void CopyOther(const Production &other);

public:
    ListProduction();
    ListProduction(unsigned int);
    ListProduction(const ListProduction &);
    ~ListProduction();
    unsigned int GetSize() const;
    void ReserveTicket(char*, unsigned int, unsigned int, char *, char *);
    void ReserveTicket(char*,unsigned int, unsigned int, char *);
    void BuyReservedSeat(char*,unsigned int, unsigned int, char *);
    void BuyFreeSeat(char*,unsigned int, unsigned int, char *);
    void BuyFreeSeat(char*,unsigned int, unsigned int, char *, char *);
    void Print() const;
    void PrintFreeSeats() const;
    void PrintReservedSeats() const;
    void SetListTickets(char*, unsigned int);
    void UnreserveSeat(char*,unsigned int, unsigned int, char *);
    unsigned int BoughtTickets() const;
};

#endif