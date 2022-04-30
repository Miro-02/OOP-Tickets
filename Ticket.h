#ifndef TICKET_H
#define TICKET_H

class Ticket
{
private:
    char* mName;
    //Date mDate;
    char* mPassword;
public:
    Ticket();
    Ticket(Ticket &other);
    Ticket& operator=(const Ticket &other);
    ~Ticket();
};

#endif