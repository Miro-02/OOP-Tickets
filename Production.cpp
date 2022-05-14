#include "Production.h"

void Production::PrintFreeSeats() const
{
    mTickets.PrintFreeSeats();
}
void Production::PrintReservedSeats() const
{
    mTickets.PrintReservedSeats();
}
unsigned int Production::BoughtTickets() const
{
    return mTickets.BoughtTickets();
}