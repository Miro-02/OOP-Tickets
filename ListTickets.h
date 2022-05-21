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
    // void SetTickets(unsigned int);
    void SetListTickets(unsigned int);

public:
    ListTickets();
    ListTickets(unsigned int);
    ListTickets(const ListTickets &other);
    ListTickets &operator=(const ListTickets &other);
    ~ListTickets();
    unsigned int GetSize() const;
    void ReserveTicket(unsigned int, unsigned int, const char *, const char *);
    // void ReserveTicket(unsigned int, unsigned int, const char *);
    // void BuyReservedSeat(unsigned int, unsigned int, const char *);
    // void BuyFreeSeat(unsigned int, unsigned int, const char *);
    void BuyTicket(unsigned int, unsigned int, const char *, const char *);
    unsigned int PrintFreeTickets() const;
    unsigned int PrintReservedTickets() const;
    unsigned int PrintBoughtTickets() const;
    void UnreserveTicket(unsigned int, unsigned int, const char *);
};

#endif