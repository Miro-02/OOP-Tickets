#include "ListProduction.h"
void ListProduction::Free()
{
    delete[] mProductions;
}
// void ListProduction::SetListTickets(unsigned int size)
// {
//     for (size_t i = 0; i < mSize; i++)
//     {
//         mProductions[i].SetListTickets(size);
//     }
// }


void ListProduction::CreateEmpty()
{
    mSize = 0;
    mCapacity = 0;
    mProductions = nullptr;
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

void ListProduction::CopyFromOther(const ListProduction &other)
{
    mSize = other.GetSize();
    mCapacity = mSize * 2;
    mProductions = new Production(mSize);
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i] = other.mProductions[i];
    }
}

ListProduction::ListProduction()
{
    mSize = 2;
    mCapacity = 4;
    mProductions = new Production[4];
}

ListProduction::ListProduction(unsigned int size)
{
    mSize = size;
    mCapacity = mSize * 2;
    mProductions = new Production(size);
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
    Free();
    this->CopyFromOther(other);
    return *this;
}

unsigned int ListProduction::GetSize() const
{
    return mSize;
}

void ListProduction::ReserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i].ReserveTicket(date, name, row, col, password, description);
    }
}

void ListProduction::BuyTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password, const char *description = "No description")
{
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i].ReserveTicket(date, name, row, col, password, description);
    }
}

void ListProduction::PrintFreeTickets(const Date &date, const char *name) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        if (mProductions[i].CheckProdction(date, name))
        {
            std::cout << "Date: " << mProductions[i].GetDate() << " Name: " << mProductions[i].GetName() << " Count: " << mProductions[i].PrintFreeTickets() << std::endl;
            return;
        }
    }
}
std::ostream &ListProduction::PrintReservedTickets(std::ostream &stream, const Date &date, bool allDate, const char *name = "No name") const
{
    if (allDate == true)
    {
        for (size_t i = 0; i < mSize; i++)
        {

            stream << "Date: " << mProductions[i].GetDate() << " Name: " << mProductions[i].GetName() << " Count: " << mProductions[i].PrintReservedTickets() << std::endl;
        }
    }
    else
    {
        for (size_t i = 0; i < mSize; i++)
        {
            if (mProductions[i].CheckProdction(date, name))
            {
                stream << "Date: " << mProductions[i].GetDate() << " Name: " << mProductions[i].GetName() << " Count: " << mProductions[i].PrintReservedTickets() << std::endl;
            }
        }
    }

    return stream;
}

void ListProduction::PrintBoughtTickets(const Date &date1, const Date &date2, bool allDate = false) const
{
    if (allDate)
    {
        for (size_t i = 0; i < mSize; i++)
        {

            std::cout << "Date: " << mProductions[i].GetDate() << " Name: " << mProductions[i].GetName() << " Count: " << mProductions[i].PrintBoughtTickets() << std::endl;
        }
    }
    else
    {
        for (size_t i = 0; i < mSize; i++)
        {
            if (mProductions[i].GetDate() > date1 && mProductions[i].GetDate() < date2)
            {
                std::cout << "Date: " << mProductions[i].GetDate() << " Name: " << mProductions[i].GetName() << " Count: " << mProductions[i].PrintBoughtTickets() << std::endl;
            }
        }
    }
}
void ListProduction::UnreserveTicket(const Date &date, const char *name, unsigned int row, unsigned int col, const char *password)
{
    for (size_t i = 0; i < mSize; i++)
    {
        mProductions[i].UnreserveTicket(date, name, row, col, password);
    }
}

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
    mProductions[mSize] = Production(date, name, size);
    mSize++;
}