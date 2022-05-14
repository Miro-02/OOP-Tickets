#ifndef PRODUCTION_H
#define PRODUCTION_H
#include "Date.h"
#include "Ticket.h"
#include "MyString.h"

class Production
{
private:
    Date mDate;
    MyString mName;
    
    
public:
    Production(/* args */);
    ~Production();
};

Production::Production(/* args */)
{
}

Production::~Production()
{
}

#endif