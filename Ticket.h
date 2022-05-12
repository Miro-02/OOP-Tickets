#ifndef TICKET_H
#define TICKET_H

class Ticket
{
private:
    bool mIsBought;
    bool mIsReserved;
    char *mPassword;
    void Free(); 

public:
    bool isBought() const;
    bool isReserved() const;
    const char& getPassword();
    void setPassword(const char*);
    Ticket();
    Ticket(Ticket &other);
    Ticket &operator=(const Ticket &other);
    ~Ticket();
};

#endif