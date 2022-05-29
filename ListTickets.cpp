#include "ListTickets.h"
#include <iostream>
using namespace std;
void ListTickets::CopyOther(const ListTickets &other)
{
    if (this == &other)
    {
        return;
    }
    mSize = other.mSize;
    for (size_t i = 0; i < mSize; i++)
    {
        for (size_t j = 0; j < mSize; j++)
        {
            mTickets[i][j] = other.mTickets[i][j];
            
        }
    }
}

void ListTickets::SetListTickets(unsigned int size)
{
    if (size > 10 || size < 4)
    {
        cout << "Size must be between 4 and 10";
        throw 4;
    }
    mSize = size;
    mTickets = new Ticket *[size];
    for (size_t i = 0; i < size; i++)
    {
        mTickets[i] = new Ticket[size];
    }
}
void ListTickets::Free()
{
    for (size_t i = 0; i < mSize; i++)
    {
        delete[] mTickets[i];
    }
    delete[] mTickets;
}

ListTickets::ListTickets()
{
    mSize = 4;
    mTickets = new Ticket*[4];
    for (size_t i = 0; i < 4; i++)
    {
        mTickets[i] = new Ticket[4];
    }
    
}
ListTickets::ListTickets(unsigned int size)
{
    SetListTickets(size);
}
ListTickets::ListTickets(const ListTickets &other)
{
    SetListTickets(other.mSize);
    CopyOther(other);
}
ListTickets::~ListTickets()
{
    Free();
}
unsigned int ListTickets::GetSize() const
{
    return mSize;
}
ListTickets &ListTickets::operator=(const ListTickets &other)
{
    if (this == &other)
    {
        return *this;
    }
    Free();
    SetListTickets(other.mSize);
    CopyOther(other);
    return *this;
}
void ListTickets::ReserveTicket(unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    if(row>mSize||col>mSize)
    {
        cout<<"Bad spot."<<endl;
        return;
    }
    mTickets[row][col].ReserveTicket(password, description);
}
void ListTickets::BuyTicket(unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    mTickets[row][col].BuyTicket(password, description);
}

// void ListTickets::ReserveTicket(unsigned int row, unsigned int col, const char *password)
// {
//     mTickets[row][col].ReserveTicket(password);
// }
// void ListTickets::BuyReservedSeat(unsigned int row, unsigned int col, const char *password)
// {
//     mTickets[row][col].BuyReservedSeat(password);
// }
// void ListTickets::BuyFreeSeat(unsigned int row, unsigned int col, const char *password)
// {
//     mTickets[row][col].BuyFreeSeat(password);
// }
// void ListTickets::BuyFreeSeat(unsigned int row, unsigned int col, const char *password, const char *description)
// {
//     mTickets[row][col].BuyFreeSeat(password, description);
// }
// void ListTickets::Print() const
// {
//     unsigned int size = GetSize();
//     for (size_t i = 0; i < size; i++)
//     {
//         for (size_t j = 0; j < size; j++)
//         {
//             if (mTickets[i][j].IsBought())
//             {
//                 std::cout << "B";
//             }
//             else if (mTickets[i][j].IsReserved())
//             {
//                 std::cout << "R";
//             }
//             else
//             {
//                 std::cout << "F";
//             }
//             std::cout << " ";
//         }
//         std::cout << std::endl;
//     }
// }
unsigned int ListTickets::PrintFreeTickets() const
{
    unsigned int size = GetSize();
    unsigned int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (!mTickets[i][j].IsReserved() || !mTickets[i][j].IsBought())
            {
                count++;
            }
        }
    }
    return count;
}

unsigned int ListTickets::PrintReservedTickets() const
{
    unsigned int size = GetSize();
    unsigned int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (mTickets[i][j].IsReserved() && !mTickets[i][j].IsBought())
            {
                count++;
            }
        }
    }
    return count;
}
unsigned int ListTickets::PrintBoughtTickets() const
{
    unsigned int size = GetSize();
    unsigned int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (mTickets[i][j].IsBought())
            {
                count++;
            }
        }
    }
    return count;
}

void ListTickets::UnreserveTicket(unsigned int row, unsigned int col, const char *password)
{
    if (row > 10 || col > 10)
    {
        cout << "Bad position." << endl;
        throw 5;
    }
    mTickets[row][col].UnreserveTicket(password);
}

// void ListTickets::SetTickets(unsigned int size)
// {
//     Free();
//     mTickets = new Ticket *[size];
//     for (size_t i = 0; i < size; i++)
//     {
//         mTickets[i] = new Ticket[size];
//     }
// }

