#include "Auditorium.h"

void Auditorium::SetID(unsigned int ID)
{
    mID = ID;
}

Auditorium::Auditorium(unsigned int size)
{
    mSize = size;
    mProductions.SetListTickets(size);
}

unsigned int Auditorium::GetSize() const
{
    return mSize;
}

void Auditorium::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description)
{
    mProductions.ReserveTicket(date, name, row, col, password, description);
}
void Auditorium::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{

    mProductions.ReserveTicket(date, name, row, col, password);
}
void Auditorium::BuyReservedSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{

    mProductions.ReserveTicket(date, name, row, col, password);
}
void Auditorium::BuyFreeSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    mProductions.BuyFreeSeat(date, name, row, col, password);
}
void Auditorium::BuyFreeSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description)
{
    mProductions.BuyFreeSeat(date, name, row, col, password, description);
}
// void Auditorium::Print(const Date &date, const char *name) const
// {
//     mProductions.Print(date, name);
// }

void Auditorium::PrintFreeSeats(const Date &date, const char *name) const
{
    mProductions.PrintFreeSeats(date, name);
}
std::ostream &Auditorium::PrintReservedSeats(std::ostream &stream, const Date &date, const char *name) const
{
    return mProductions.PrintReservedSeats(stream, date, name);
}
std::ostream &Auditorium::PrintReservedSeatsForDate(std::ostream &stream, const Date &date) const
{
    return mProductions.PrintReservedSeatsForDate(stream, date);
}
std::ostream &Auditorium::PrintAllReservedSeats(std::ostream &stream) const
{
    return mProductions.PrintAllReservedSeats(stream);
}
void Auditorium::PrintBoughtSeats(const Date &date1, const Date &date2) const
{
    mProductions.PrintBoughtSeats(date1, date2);
}
void Auditorium::PrintAllBoughtSeats() const
{
    mProductions.PrintAllBoughtSeats();
}
void Auditorium::UnreserveSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    mProductions.UnreserveSeat(date, name, row, col, password);
}

/**
 * @brief
 *
 * @param date
 * @param name
 */
void Auditorium::AddProduction(const Date &date, const char *name)
{
    mProductions.AddProduction(date, name, mSize);
}
