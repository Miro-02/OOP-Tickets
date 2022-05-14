#ifndef LISTTICKETS_H
#define LISTTICKETS_H
#include "Ticket.h"

class ListTickets
{
private:
    Ticket **mTickets;
    unsigned int mSize;
    void Free();
    void CopyOther(const ListTickets &other);

public:
    ListTickets();
    ListTickets(unsigned int);
    ListTickets(const ListTickets &other);
    ListTickets &operator=(const ListTickets &other);
    ~ListTickets();
    unsigned int GetSize() const;
    void ReserveTicket(unsigned int, unsigned int, char *, char *);
    void ReserveTicket(unsigned int, unsigned int, char *);
    void BuyReservedSeat(unsigned int, unsigned int, char *);
    void BuyFreeSeat(unsigned int, unsigned int, char *);
    void BuyFreeSeat(unsigned int, unsigned int, char *, char *);
    void Print() const;
    void PrintFreeSeats() const;
    void PrintReservedSeats() const;
    void SetListTickets(unsigned int);
    void UnreserveSeat(unsigned int, unsigned int, char *);
    unsigned int BoughtTickets() const;
};

#endif