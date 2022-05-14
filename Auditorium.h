#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "ListTickets.h"

class Auditorium
{
private:
    unsigned int mID;
    unsigned int mRowCount;
    unsigned int mSeats;
public:
    Auditorium();
    ~Auditorium();
};

#endif