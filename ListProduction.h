#ifndef LISTPRODUCTION_H
#define LISTPRODUCTION_H
#include "Production.h"

class ListProduction
{
private:
    Production *mProductions;
    unsigned int mSize;
    unsigned int mCapacity;
    void Free();
    void CreateEmpty();
    void CopyFromOther(const ListProduction &);
    bool ShouldBeResized(unsigned int size) const;
    void ResizeUp();

public:
    ListProduction();
    ListProduction(unsigned int);
    ListProduction(const ListProduction &);
    ~ListProduction();
    ListProduction &operator=(const ListProduction &);
    unsigned int GetSize() const;
    const Production &GetData() const;

    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void BuyTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void UnreserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *);
    void AddProduction(const Date &, const char *, unsigned int);
    void PrintFreeTickets(const Date &, const char *) const;
    std::ostream &PrintReservedTickets(std::ostream &stream, const Date &, bool, const char *) const;
    void PrintBoughtTickets(const Date &, const Date &, bool) const;
};

#endif