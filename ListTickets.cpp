#include "ListTickets.h"
#include <iostream>
void ListTickets::CopyOther(const ListTickets &other)
{
    for (size_t i = 0; i < other.mSize; i++)
    {
        for (size_t j = 0; j < other.mSize; j++)
        {
            mTickets[i][j] = other.mTickets[i][j];
        }
    }
}

void ListTickets::SetListTickets(unsigned int size)
{
    if (size > 10 || size < 4)
    {
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
    mSize = 0;
    mTickets = new Ticket *[1];
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
    Free();
    SetListTickets(other.mSize);
    CopyOther(other);
    return *this;
}
void ListTickets::ReserveTicket(unsigned int row, unsigned int col, char *password, char *description)
{
    mTickets[row][col].ReserveTicket(password, description);
}
void ListTickets::ReserveTicket(unsigned int row, unsigned int col, char *password)
{
    mTickets[row][col].ReserveTicket(password);
}
void ListTickets::BuyReservedSeat(unsigned int row, unsigned int col, char *password)
{
    mTickets[row][col].BuyReservedSeat(password);
}
void ListTickets::BuyFreeSeat(unsigned int row, unsigned int col, char *password)
{
    mTickets[row][col].BuyFreeSeat(password);
}
void ListTickets::BuyFreeSeat(unsigned int row, unsigned int col, char *password, char *description)
{
    mTickets[row][col].BuyFreeSeat(password, description);
}
void ListTickets::Print()
{
    unsigned size = GetSize();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (mTickets[i][j].IsBought())
            {
                std::cout << "B";
            }
            else if (mTickets[i][j].IsReserved())
            {
                std::cout << "R";
            }
            else
            {
                std::cout << "F";
            }
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
