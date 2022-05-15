#include "Auditorium.h"
#include <iostream>
#include <fstream>
using namespace std;

void PrintFunctions()
{
    cout << "Choose function: " << endl
         << "New production: 1, Print free tickets: 2, Reserve ticket: 3, Unreserve ticket: 4, Buy ticket: 5, Print reserved tickets: 6, Print bought tickets: 7" << endl;
}

void PrintReserveTicket()
{
    cout << "Choose function:" << endl
         << "Without description: 1, With description: 2 " << endl;
}

int main(int argc, char const *argv[])
{
    Auditorium auditoriums[10];

    PrintFunctions();
    int function;
    cin >> function;

    if (function == 1)
    {
        int ID, day, month, year;
        Date date;
        char name[101];
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: " << endl;
        cin.getline(name, 100);
        cout << "Insert day: " << endl;
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: " << endl;
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: " << endl;
        cin >> year;
        date.SetYear(year);
        auditoriums[ID].AddProduction(date, name);
    }
    else if (function == 2)
    {
        int ID, day, month, year;
        Date date;
        char name[101];
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: " << endl;
        cin.getline(name, 100);
        cout << "Insert day: " << endl;
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: " << endl;
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: " << endl;
        cin >> year;
        date.SetYear(year);
        for (size_t i = 0; i < 10; i++)
        {
            auditoriums[i].PrintFreeSeats(date, name);
        }
    }
    else if (function == 3)
    {
        int ID, day, month, year, row, col;
        Date date;
        char name[101], password[21], description[101];
        int function2;
        PrintReserveTicket();
        cin >> function2;
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: ";
        cin.getline(name, 100);
        cout << "Insert day: ";
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: ";
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: ";
        cin >> year;
        cout << "Insert row";
        cin >> row;
        cout << "Insert col";
        cin >> col;
        date.SetYear(year);
        cout << "Insert password";
        cin.getline(password, 20);
        if (function2 == 1)
        {
            auditoriums[ID].ReserveTicket(date, name, row, col, password);
        }
        else if (function2 == 1)
        {
            cout << "Insert description";
            cin.getline(description, 100);
            auditoriums[ID].ReserveTicket(date, name, row, col, password, description);
        }
    }
    else if (function == 4)
    {
        int ID, day, month, year, row, col;
        Date date;
        char name[101], password[21];
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: ";
        cin.getline(name, 100);
        cout << "Insert day: ";
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: ";
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: ";
        cin >> year;
        date.SetYear(year);
        cout << "Insert password";
        cin.getline(password, 20);
        cout << "Insert row";
        cin >> row;
        cout << "Insert col";
        cin >> col;
        auditoriums[ID].UnreserveSeat(date, name, row, col, password);
    }
    else if (function == 5)
    {
        int ID, day, month, year, row, col;
        Date date;
        char name[101], password[21];
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: ";
        cin.getline(name, 100);
        cout << "Insert day: ";
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: ";
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: ";
        cin >> year;
        date.SetYear(year);
        cout << "Insert password";
        cin.getline(password, 20);
        cout << "Insert row";
        cin >> row;
        cout << "Insert col";
        cin >> col;
        auditoriums[ID].BuyReservedSeat(date, name, row, col, password);
    }
    // else if(function==6)
    // {
    //     int ID, month, year;;
    //     char day[10]; 
    //     Date date;
    //     char name[101];
    //     char filename[121] = "report-";
        
    //     cout << "Insert auditorium ID: " << endl;
    //     cin >> ID;
    //     cout << "Insert production name: ";
    //     cin.getline(name, 100);
    //     cout << "Insert day: ";
    //     cin.getline(name, 100);
    //     if(name=="All"&&day=="ALL")
    //     {    
    //         ostream file("report-");
    //         auditoriums[ID].PrintAllReservedSeats(file);
    //     }
    //     cout << "Insert month: ";
    //     cin >> month;
    //     date.SetMonth(month);
    //     cout << "Insert year: ";
    //     cin >> year;
    //     date.SetYear(year);

    // }
    else if(function==7)
    {
        int ID, day, month, year, row, col;
        Date date;
        char name[101], password[21];
        cout << "Insert auditorium ID: " << endl;
        cin >> ID;
        cout << "Insert production name: ";
        cin.getline(name, 100);
        cout << "Insert day: ";
        cin >> day;
        date.SetDay(day);
        cout << "Insert month: ";
        cin >> month;
        date.SetMonth(month);
        cout << "Insert year: ";
        cin >> year;
        date.SetYear(year);

    }
    return 0;
}
