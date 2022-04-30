#ifndef SEATS_H
#define SEATS_H

class Seat
{
private:
    int mRow;
    int mCol;
    bool mIsReserved;
public:
    Seat(/* args */);
    ~Seat();
};

#endif