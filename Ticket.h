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
    void SetPassword(const char *);
    void SetBought(bool);
    void SetReserved(bool);
    void SetDescription(const char *);
    void ReserveTicket(char *, char *);
    void ReserveTicket(char *);
    void BuyReservedSeat(char *);
    void BuyFreeSeat(char *);
    void BuyFreeSeat(char *, char *);
    void UnreserveSeat(char *);    
};

#endif