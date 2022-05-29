#include "Production.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool CheckSmallLetter(char ch)
{
    if (ch < 'a' || ch > 'z')
    {
        return false;
    }
    return true;
}
bool CheckCapitalLetter(char ch)
{
    if (ch < 'A' || ch > 'Z')
    {
        return false;
    }
    return true;
}
Production::Production()
{
    mDate = Date();
    mName = MyString();
    //mTickets = ListTickets();
}
bool Production::CheckProdction(const Date& date, const char* name)
{
    if (date==mDate&&strcmp(name, "ALL"))
    {
        return true;
    }
    else if (date==mDate&&name==mName)
    {
        return true;
    }
    return false;
    
}

Production::Production(unsigned int size)
{
    mTickets = ListTickets(size);
}
Production::Production(const Date& date, const char* name, unsigned int size)
{
    mTickets = ListTickets(size);
    SetDate(date);
    SetName(name);
}
void Production::SetDate(const Date &date)
{
    mDate = date;
}
void Production::SetName(const char *name)
{
    /*if (name == nullptr)
    {
        cout << "Bad name." << endl;
        throw 6;
    }
    else if (!CheckCapitalLetter(name[0]))
    {
        cout << "Bad name." << endl;
        throw 6;
    }
    for (size_t i = 1; i < strlen(name); i++)
    {
        if (!CheckSmallLetter(name[i]))
        {
            cout << "Bad name." << endl;
            throw 6;
        }
    }*/
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

void Production::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    if (CheckProdction(date, name))
    {
        mTickets.ReserveTicket(row, col, password, description);
        return;
    }
    else
    cout << "Bad date." << endl;
}

// void Production::BuyFreeSeat(unsigned int row, unsigned int col, const char *password, const char *description)
// {
//     mTickets.BuyFreeSeat(row, col, password, description);
// }
// void Production::Print() const
// {
//     mTickets.Print();
// }

void Production::BuyTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    if (CheckProdction(date, name))
    {
        mTickets.BuyTicket(row, col, password, description);
        return;
    }
    cout << "Bad date." << endl;
}

void Production::UnreserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    if (CheckProdction(date, name))
    {
        mTickets.UnreserveTicket(row, col, password);
        return;
    }
    cout << "Bad date." << endl;
}

// void Production::SetListTickets(unsigned int size)
// {
//     mTickets.SetListTickets(size);
// }
unsigned int Production::PrintFreeTickets() const
{
    return mTickets.PrintFreeTickets();
}
unsigned int Production::PrintReservedTickets() const
{
    return mTickets.PrintReservedTickets();
}
unsigned int Production::PrintBoughtTickets() const
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
