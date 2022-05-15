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
    void Resize();
    void CopyFromOther(const ListProduction &);
    void CopyFromOtherWithoutResize(const ListProduction &);
    void ResizeUp();
    bool ShouldBeResized(unsigned int) const;

public:
    ListProduction();
    ListProduction(unsigned int);
    ListProduction(const ListProduction &);
    ~ListProduction();
    ListProduction &operator=(const ListProduction &);
    unsigned int GetSize() const;
    unsigned int GetCapacity() const;
    const Production &GetData() const;
    void SetListTickets(unsigned int);
    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    void ReserveTicket(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyReservedSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyFreeSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void BuyFreeSeat(const Date &, const char *, unsigned int, unsigned int, const char *, const char *);
    // void Print(const Date &, const char *) const;

    void UnreserveSeat(const Date &, const char *, unsigned int, unsigned int, const char *);
    void AddProduction(const Date &, const char *, unsigned int);
    void PrintFreeSeats(const Date &, const char *) const;
    std::ostream & PrintReservedSeats(std::ostream &stream, const Date &, const char *) const;
    std::ostream & PrintReservedSeatsForDate(std::ostream &stream, const Date &) const;
    std::ostream & PrintAllReservedSeats(std::ostream &stream) const;
    void PrintBoughtSeats(const Date &, const Date &) const;
    void PrintAllBoughtSeats() const;
};

#endif