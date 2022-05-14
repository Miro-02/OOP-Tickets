#include "ListProduction.h"

void ListProduction::Free()
{
    delete[] mProduction;
}

ListProduction::ListProduction()
{
    mSize = 0;
    mProduction = new Production[1];
}

ListProduction::~ListProduction()
{

}