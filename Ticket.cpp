#include "Ticket.h"
#include <cstring>
#include <iostream>

Ticket::Ticket()
{
    mIsBought = false;
    mIsReserved = false;
    mPassword = "No password";
    mDescription = "No description";
}
bool Ticket::IsBought() const
{
    return mIsBought;
}
bool Ticket::IsReserved() const
{
    return mIsReserved;
}
const MyString &Ticket::GetPassword() const
{
    return mPassword;
}
void Ticket::SetPassword(const char * other)
{
    if (strlen(other)<8)
    {
        throw 3;
    }
    mPassword = other;
}
void Ticket::SetDescription(const char * other)
{
    if(other==nullptr)
    {
        return;
    }
    mDescription = other;
}
void Ticket::SetReserved()
{
    mIsReserved = true;
}
void Ticket::SetBought()
{
    mIsReserved = true;
}

void Ticket::ReserveTicket(char *password, char *description)
{
    SetReserved();
    SetPassword(password);
    SetDescription(description);
}
void Ticket::ReserveTicket(char *password)
{
    SetReserved();
    SetPassword(password);
}
void Ticket::BuyReservedSeat(char*password)
{
    if (mPassword==password)
    {
        SetBought();
    }
}
void Ticket::BuyFreeSeat(char * password)
{
    SetPassword(password);
    SetReserved();
    SetBought();
}
void Ticket::BuyFreeSeat(char * password, char* description)
{
    SetPassword(password);
    SetDescription(description);   
    SetReserved();
    SetBought();
}

// int main(int argc, char const *argv[])
// {
//     Ticket ticket;
//     std::cout<<ticket.IsBought()<<" "<<ticket.IsReserved()<<" "<<ticket.GetPassword()<<ticket.GetPassword().GetSize();
//     return 0;
// }
