#include "Production.h"
#include <iostream>
#include <fstream>

void Production::SetDate(const Date &date)
{
    mDate = date;
}
void Production::SetName(const MyString &name)
{
    mName = name;
}

const MyString &Production::GetName() const
{
    return mName;
}
const Date &Production::GetDate() const
{
    return mDate;
}

void Production::ReserveTicket(unsigned int row, unsigned int col, const char *password, const char *description)
{
    mTickets.ReserveTicket(row, col, password, description);
}
void Production::ReserveTicket(unsigned int row, unsigned int col, const char *password)
{
    mTickets.ReserveTicket(row, col, password);
}
void Production::BuyReservedSeat(unsigned int row, unsigned int col, const char *password)
{
    mTickets.BuyReservedSeat(row, col, password);
}
void Production::BuyFreeSeat(unsigned int row, unsigned int col, const char *password)
{
    mTickets.BuyFreeSeat(row, col, password);
}
void Production::BuyFreeSeat(unsigned int row, unsigned int col, const char *password, const char *description)
{
    mTickets.BuyFreeSeat(row, col, password, description);
}
// void Production::Print() const
// {
//     mTickets.Print();
// }

void Production::SetListTickets(unsigned int size)
{
    mTickets.SetListTickets(size);
}
void Production::UnreserveSeat(unsigned int row, unsigned int col, const char *password)
{
    mTickets.UnreserveSeat(row, col, password);
}
void Production::SetTickets(unsigned int size)
{
    mTickets.SetTickets(size);
}
unsigned int Production::PrintFreeSeats() const
{
    return mTickets.PrintFreeSeats();
}
unsigned int Production::PrintReservedSeats() const
{
    return mTickets.PrintReservedSeats();
}
unsigned int Production::PrintBoughtSeats() const
{
    return mTickets.PrintBoughtTickets();
}

// std::ostream &Production::PrintAllReservedSeatsForDate(std::ostream &stream, const Date &date) const
// {
//     if (mDate == date)
//     {
//         stream << "Date: " << mDate << " Name: " << mName << " Bought tickets: " << mTickets.PrintReservedSeats() << std::endl;
//     }
//     return stream;
// }
// std::ostream &Production::PrintAllReservedSeats(std::ostream &stream) const
// {
//     stream << "Date: " << mDate << " Name: " << mName << " Bought tickets: " << mTickets.PrintReservedSeats() << std::endl;
//     return stream;
// }
// void Production::PrintBoughtSeats(const Date &date1, const Date &date2) const
// {
//     for (size_t i = 0; i < mTickets.GetSize(); i++)
//     {
//         if (mDate > date1 && mDate < date2)
//         {
//             std::cout << "Date: " << mDate << " Name: " << mName << " Bought tickets: " << mTickets.PrintBoughtTickets();
//         }
//     }
// }

// void Production::PrintAllBoughtSeats() const
// {
//     for (size_t i = 0; i < mTickets.GetSize(); i++)
//     {
//         std::cout << "Sold tickets for " << mName << " - " << mTickets.PrintBoughtTickets();
//     }
// }
