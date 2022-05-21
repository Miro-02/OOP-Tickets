#include "Ticket.h"
#include <cstring>
#include <iostream>
using namespace std;

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

void Ticket::SetPassword(const char *other)
{
    if (strlen(other) < 8)
    {
        throw 3;
    }
    mPassword = other;
}
void Ticket::SetDescription(const char *other)
{
    if (other == nullptr)
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

void Ticket::ReserveTicket(const char *password, const char *description = "No description")
{
    if (IsReserved() || IsBought())
    {
        cout << "Ticket is already reserved";
        return;
    }
    SetReserved(true);
    SetPassword(password);
    SetDescription(description);
    cout << "Ticket is reserved." << endl;
}
Ticket::Ticket()
{
    mIsBought = false;
    mIsReserved = false;
    mPassword = MyString();
    mDescription = MyString();
}
// void Ticket::ReserveTicket(const char *password)
// {
//     if(IsReserved()||IsBought())
//     {
//         cout<<"Ticket is reserved";
//         return;
//     }
//     SetReserved(true);
//     SetPassword(password);
// }
// void Ticket::BuyReservedSeat(const char *password)
// {
//     if (IsBought())
//     {
//         cout << "Ticket is already reserved." << endl;
//         return;
//     }
//     else if (mPassword == password)
//     {
//         SetBought(true);
//         cout << "Ticket is bought." << endl;
//     }
//     return;
// }
// void Ticket::BuyFreeSeat(const char * password)
// {
//     if(IsBought()||IsReserved())
//     {
//         cout<<"Ticket is reserved."<<endl;
//         return;
//     }
//     SetPassword(password);
//     SetReserved(true);
//     SetBought(true);
// }
void Ticket::BuyTicket(const char *password, const char *description = "No description")
{
    if (IsBought())
    {
        cout << "Ticket is already reserved." << endl;
        return;
    }
    else if (IsReserved())
    {
        if (mPassword == password)
        {
            if (!strcmp(description, "No description"))
            {
                SetDescription(description);
            }
            SetBought(true);
            cout << "Ticket is bought." << endl;
            return;
        }
        cout << "Wrong password." << endl;
        return;
    }
    SetPassword(password);
    SetReserved(true);
    SetBought(true);
    SetDescription(description);
    cout << "Ticket is bought." << endl;
}

void Ticket::UnreserveTicket(const char *password)
{
    if (!IsBought() || !IsReserved())
    {
        cout << "Bad position." << endl;
        return;
    }
    else if (mPassword == password)
    {
        cout << "Ticket is unreserved" << endl;
        EmptyTicket();
        return;
    }
    cout << "Wrong password." << endl;
}

// int main(int argc, char const *argv[])
// {
//     Ticket ticket;
//     std::cout << ticket.IsBought() << " " << ticket.IsReserved() << " " << ticket.GetPassword() << ticket.GetPassword().GetSize() << ticket.GetDescription();
//     return 0;
// }
