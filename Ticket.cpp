#include "Ticket.h"

void Ticket::Free()
{
    delete[] mPassword;
}

Ticket::Ticket()
{
    mIsBought = false;
    mIsReserved = false;
    mPassword = new char[1];
    mPassword[0]='\0';
}