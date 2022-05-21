#include "Auditorium.h"

void Auditorium::SetID(unsigned int ID)
{
    mID = ID;
}

Auditorium::Auditorium(unsigned int size)
{
    mSize = size;
    mProductions = ListProduction(size);
}

unsigned int Auditorium::GetSize() const
{
    return mSize;
}
Auditorium::Auditorium()
{
    mID = 0;
    mSize = 4;
    mProductions = ListProduction(4);
}

void Auditorium::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    mProductions.ReserveTicket(date, name, row, col, password, description);
}

void Auditorium::BuyTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    mProductions.BuyTicket(date, name, row, col, password, description);
}
void Auditorium::PrintFreeTickets(const Date &date, const char *name) const
{
    mProductions.PrintFreeTickets(date, name);
}

std::ostream &Auditorium::PrintReservedTickets(std::ostream &stream, const Date &date, bool allDate, const char *name = "No name" ) const
{
    return mProductions.PrintReservedTickets(stream, date, allDate, name );
}

void Auditorium::PrintBoughtTickets(const Date &date1, const Date &date2, bool allData = false) const
{
    mProductions.PrintBoughtTickets(date1, date2, allData);
}

void Auditorium::UnreserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    mProductions.UnreserveTicket(date, name, row, col, password);
}

void Auditorium::AddProduction(const Date &date, const char *name)
{
    mProductions.AddProduction(date, name, mSize);
}
