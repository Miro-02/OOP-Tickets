#include "ListProduction.h"
void ListProduction::Free()
{
    delete[] mProductions;
}
void ListProduction::SetListTickets(unsigned int size)
{
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i].SetListTickets(size);
    }
}

void ListProduction::CreateEmpty()
{
    mSize = 0;
    mCapacity = 0;
    mProductions = new Production[1];
}

bool ListProduction::ShouldBeResized(unsigned int size) const
{
    if (size > mCapacity)
    {
        return true;
    }
    return false;
}
void ListProduction::ResizeUp()
{
    Production productions[mSize];
    for (size_t i = 0; i < mSize; i++)
    {
        productions[i] = mProductions[i];
    }
    Free();
    mCapacity = mSize * 2;
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i] = productions[i];
    }
}

void ListProduction::CopyFromOtherWithoutResize(const ListProduction &other)
{
    mSize = other.mSize;
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i] = other.mProductions[i];
    }
}

void ListProduction::CopyFromOther(const ListProduction &other)
{
    mSize = other.GetSize();
    mCapacity = mSize * 2;
    mProductions = new Production[mCapacity];
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i] = other.mProductions[i];
    }
}

ListProduction::ListProduction()
{
    CreateEmpty();
}

ListProduction::ListProduction(unsigned int size)
{
    if (size == 0 || size > 10)
    {
        throw 7;
    }
    mSize = size;
    mCapacity = mSize * 2;
    mProductions = new Production[mCapacity];
}
ListProduction::ListProduction(const ListProduction &other)
{
    this->CopyFromOther(other);
}

ListProduction::~ListProduction()
{
    Free();
}
ListProduction &ListProduction::operator=(const ListProduction &other)
{
    if (this == &other)
    {
        throw 8;
    }
    if (other.mSize == 0)
    {
        CreateEmpty();
    }
    else if (ShouldBeResized(other.mSize))
    {
        Free();
        CopyFromOther(other);
    }
    else
    {
        CopyFromOtherWithoutResize(other);
    }
    return *this;
}

unsigned int ListProduction::GetSize() const
{
    return mSize;
}
unsigned int ListProduction::GetCapacity() const
{
    return mCapacity;
}
void ListProduction::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
        {
            mProductions[i].ReserveTicket(row, col, password, description);
            return;
        }
    }
}
void ListProduction::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
        {
            mProductions[i].ReserveTicket(row, col, password);
            return;
        }
    }
}
void ListProduction::BuyReservedSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
        {
            mProductions[i].ReserveTicket(row, col, password);
        }
    }
}
void ListProduction::BuyFreeSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
        {
            mProductions[i].BuyFreeSeat(row, col, password);
            return;
        }
    }
}
void ListProduction::BuyFreeSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
        {
            mProductions[i].BuyFreeSeat(row, col, password, description);
            return;
        }
    }
}
// void ListProduction::Print(const Date &date, const char *name) const
// {
//     for (size_t i = 0; i < mSize; i++)
//     {
//         if (mProductions[i].GetName() == name && mProductions[i].GetDate() == date)
//         {
//             mProductions[i].Print();
//             return;
//         }
//     }
// }
void ListProduction::PrintFreeSeats(const Date &date, const char *name) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions->GetDate() == date && mProductions->GetName() == name)
        {
            std::cout << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintFreeSeats() << std::endl;
        }
    }
}
std::ostream &ListProduction::PrintReservedSeats(std::ostream &stream, const Date &date, const char *name) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions->GetDate() == date && mProductions->GetName() == name)
        {
            stream << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintFreeSeats() << std::endl;
        }
    }
    return stream;
}
std::ostream &ListProduction::PrintReservedSeatsForDate(std::ostream &stream, const Date &date) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions->GetDate() == date)
        {
            stream << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintFreeSeats() << std::endl;
        }
    }
    return stream;
}
std::ostream &ListProduction::PrintAllReservedSeats(std::ostream &stream) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        stream << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintReservedSeats() << std::endl;
    }
    return stream;
}
void ListProduction::PrintBoughtSeats(const Date &date1, const Date &date2) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions->GetDate() > date1 && mProductions->GetDate() < date2)
        {
            std::cout << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintReservedSeats() << std::endl;
        }
    }
}
void ListProduction::PrintAllBoughtSeats() const
{
    for (size_t i = 0; i < mSize; i++)
    {

        std::cout << "Date: " << mProductions->GetDate() << " Name: " << mProductions->GetName() << " Count: " << mProductions->PrintReservedSeats() << std::endl;
    }
}
void ListProduction::UnreserveSeat(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if(mProductions[i].GetDate()==date && mProductions[i].GetName()==name)
        {
            mProductions[i].UnreserveSeat(row, col, password);
        }
    }
    
}

/**
 * @brief
 *
 * @param date
 * @param name
 */
void ListProduction::AddProduction(const Date &date, const char *name, unsigned int size)
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].GetDate() == date)
        {
            throw 9;
        }
    }
    if (ShouldBeResized(mSize + 1))
    {
        ResizeUp();
    }
    mProductions[mSize].SetDate(date);
    mProductions[mSize].SetName(name);
    mProductions[mSize].SetListTickets(size);
}