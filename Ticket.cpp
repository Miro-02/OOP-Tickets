#include "Ticket.h"
#include <cstring>
#include <iostream>

void Ticket::EmptyTicket()
{
    mIsBought = false;
    mIsReserved = false;
    mPassword = "Not set";
    mDescription = "Not set";
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
const MyString &Ticket::GetDescription() const
{
    return mDescription;
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
void Ticket::SetReserved(bool value)
{
    mIsReserved = value;
}
void Ticket::SetBought(bool value)
{
    mIsReserved = value;
}

void Ticket::ReserveTicket(const char *password, const char *description)
{
    SetReserved(true);
    SetPassword(password);
    SetDescription(description);
}
void Ticket::ReserveTicket(const char *password)
{
    SetReserved(true);
    SetPassword(password);
}
void Ticket::BuyReservedSeat(const char*password)
{
    if (mPassword==password)
    {
        SetBought(true);
    }
}
void Ticket::BuyFreeSeat(const char * password)
{
    SetPassword(password);
    SetReserved(true);
    SetBought(true);
}
void Ticket::BuyFreeSeat(const char * password, const char* description)
{
    BuyFreeSeat(password);
    SetDescription(description);
}
void Ticket::UnreserveSeat(const char * password)
{
    if (mPassword==password)
    {
        EmptyTicket();
    }
}

int main(int argc, char const *argv[])
{
    Ticket ticket;
    std::cout<<ticket.IsBought()<<" "<<ticket.IsReserved()<<" "<<ticket.GetPassword()<<ticket.GetPassword().GetSize()<<ticket.GetDescription();
    return 0;
}
