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
    void SetTickets(unsigned int);
    void ReserveTicket(unsigned int, unsigned int, const char *, const char *);
    void ReserveTicket(unsigned int, unsigned int, const char *);
    void BuyReservedSeat(unsigned int, unsigned int, const char *);
    void BuyFreeSeat(unsigned int, unsigned int, const char *);
    void BuyFreeSeat(unsigned int, unsigned int, const char *, const char *);
    unsigned int PrintFreeSeats() const;
    unsigned int PrintReservedSeats() const;
    unsigned int PrintBoughtTickets() const;
    void SetListTickets(unsigned int);
    void UnreserveSeat(unsigned int, unsigned int, const char *);
};

#endif