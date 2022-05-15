#ifndef TICKET_H
#define TICKET_H
#include "MyString.h"

class Ticket
{
private:
    bool mIsBought;
    bool mIsReserved;
    MyString mPassword;
    MyString mDescription;
    void EmptyTicket();

public:
    bool IsBought() const;
    bool IsReserved() const;
    const MyString &GetPassword() const;
    const MyString &GetDescription() const;
    void SetPassword(const char *);
    void SetBought(bool);
    void SetReserved(bool);
    void SetDescription(const char *);
    void ReserveTicket(const char *, const char *);
    void ReserveTicket(const char *);
    void BuyReservedSeat(const char *);
    void BuyFreeSeat(const char *);
    void BuyFreeSeat(const char *, const char *);
    void UnreserveSeat(const char *);    
};

#endif