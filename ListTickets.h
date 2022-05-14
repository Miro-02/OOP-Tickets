#ifndef LISTTICKETS_H
#define LISTTICKETS_H
#include "Ticket.h"

class ListTickets
{
private:
    Ticket **mTickets;
    unsigned int mSize;
    void Free();

public:
    ListTickets(/* args */);
    ListTickets(unsigned int);
    ListTickets(const ListTickets &other);
    ~ListTickets();
    unsigned int GetSize() const;
    ListTickets &operator=(const ListTickets &other);
    void ReserveTicket(unsigned int, unsigned int, char *, char *);
    void ReserveTicket(unsigned int, unsigned int, char *);
    void BuyReservedSeat(unsigned int, unsigned int, char*);
    void BuyFreeSeat(unsigned int, unsigned int, char *);
    void BuyFreeSeat(unsigned int, unsigned int, char *, char*);
    void Print();
    void SetListTickets(unsigned int);
    void CopyOther(const ListTickets &other);
};



#endif