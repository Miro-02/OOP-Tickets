#include "Auditorium.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void PrintFunctions()
{
    cout << "Choose function: " << endl
         << "New production: 1, Print free tickets: 2, Reserve ticket: 3, Unreserve ticket: 4, Buy ticket: 5, Print reserved tickets: 6, Print bought tickets: 7, Stop: 8" << endl;
}

void PrintReserveTicket()
{
    cout << "Choose function:" << endl
         << "Without description: 1, With description: 2 " << endl;
}

int main(int argc, char const *argv[])
{
    Auditorium auditoriums[10];
    int function;
    // Date date;
    // date = "21.05.2020";
    // cout<<5;
    // auditoriums[1].AddProduction(date, "Miro");
    do
    {
        PrintFunctions();
        cin >> function;

        if (function == 1)
        {
            int ID;
            Date date;
            char dateBuff[12];
            char name[101];
            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();
            cout << "Insert production name: " << endl;
            cin.getline(name, 100);
            // cout << name;
            cout << "Insert date: dd.mm.yyyy " << endl;
            cin.getline(dateBuff, 11);
            date = dateBuff;
            // cout<<date;
            auditoriums[ID].AddProduction(date, name);
        }
        else if (function == 2)
        {
            int ID;
            Date date;
            char name[101];
            char dateBuff[12];
            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();

            cout << "Insert production name: " << endl;
            cin.getline(name, 100);
            cout << "Insert date: dd.mm.yyyy" << endl;
            cin.getline(dateBuff, 11);
            date = dateBuff;
            auditoriums[ID].PrintFreeTickets(date, name);
        }
        else if (function == 3)
        {
            int ID, row, col;
            Date date;
            char name[101], password[21], description[101], dateBuff[12];
            int function2;
            PrintReserveTicket();
            cin >> function2;
            cin.get();

            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();

            cout << "Insert production name: "<<endl;
            cin.getline(name, 100);
            cout << "Insert date: dd.mm.yyyy"<<endl;
            cin.getline(dateBuff, 11);
            date = dateBuff;
            cout << "Insert row"<<endl;
            cin >> row;
            cin.get();

            cout << "Insert col"<<endl;
            cin >> col;
            cin.get();

            cout << "Insert password"<<endl;
            cin.getline(password, 20);
            if (function2 == 1)
            {
                auditoriums[ID].ReserveTicket(date, name, row, col, password, "No description");
            }
            else if (function2 == 2)
            {
                cout << "Insert description"<<endl;
                cin.getline(description, 100);
                auditoriums[ID].ReserveTicket(date, name, row, col, password, description);
            }
        }
        else if (function == 4)
        {
            int ID, row, col;
            Date date;
            char name[101], password[21], dateBuff[12];
            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();

            cout << "Insert production name: "<<endl;
            cin.getline(name, 100);
            cout << "Insert date: dd.mm.yyyy"<<endl;
            cin.getline(dateBuff, 11);
            date = dateBuff;
            cout << "Insert password"<<endl;
            cin.getline(password, 20);
            cout << "Insert row"<<endl;
            cin >> row;
            cin.get();

            cout << "Insert col"<<endl;
            cin >> col;
            cin.get();

            auditoriums[ID].UnreserveTicket(date, name, row, col, password);
        }
        else if (function == 5)
        {
            int ID, row, col;
            Date date;
            char name[101], password[21], dateBuf[12];
            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();

            cout << "Insert production name: "<<endl;
            cin.getline(name, 100);
            cout << "Insert date: dd.mm.yyyy"<<endl;
            cin.getline(dateBuf, 11);
            date = dateBuf;
            cout << "Insert password"<<endl;
            cin.getline(password, 20);
            cout << "Insert row"<<endl;
            cin >> row;
            cin.get();

            cout << "Insert col"<<endl;
            cin >> col;
            cin.get();

            auditoriums[ID].BuyTicket(date, name, row, col, password, "No description");
        }
        else if (function == 6)
        {
            int ID;
            Date date;
            char name[101], dateBuf[12];
            char filename[121];
            cout << "Insert auditorium ID: " << endl;
            cin >> ID;
            cin.get();

            cout << "Insert date: dd.mm.yyyy" << endl;
            cin.getline(dateBuf, 11);
            if (strcmp(dateBuf, "ALL"))
            {
                fstream file("report-ALL-ALL.txt");
                auditoriums[ID].PrintReservedTickets(file, date, true, name);
                file.close();
            }
            else if (strcmp(name, "ALL"))
            {
                cout << "Insert production name: " << endl;
                cin.getline(name, 100);
                strcpy(filename, "report-ALL-");
                strcat(filename, dateBuf);
                strcat(filename, ".txt");
                date = dateBuf;
                fstream file(filename);
                auditoriums[ID].PrintReservedTickets(file, date, false, name);
                file.close();
            }
            else
            {
                cout << "Insert production name: " << endl;
                cin.getline(name, 100);
                strcpy(filename, "report-");
                strcat(filename, name);
                strcat(filename, dateBuf);
                date = dateBuf;
                strcat(filename, ".txt");
                fstream file(filename);
                auditoriums[ID].PrintReservedTickets(file, date, false, name);
                file.close();
            }
        }
        else if (function == 7)
        {
            int ID;
 //           cout<<5;
            Date date1, date2;
            char dateBuff[12], IDBuff[4];
            cout << "Insert auditorium ID: " << endl;
            cin.get();
            cin.getline(IDBuff, 3);
            if (strcmp(IDBuff, "ALL"))
            {
                for (size_t i = 0; i < 10; i++)
                {
                    auditoriums[i].PrintBoughtTickets(date1, date2, true);
                }
            }
            else
            {
                ID = atoi(IDBuff);
                cout << "Insert date1: dd.mm.yyyy" << endl;
                cin.getline(dateBuff, 11);
                date1 = date2;
                cout << "Insert date1: dd.mm.yyyy" << endl;
                cin.getline(dateBuff, 11);
                date2 = date2;
                auditoriums[ID].PrintBoughtTickets(date1, date2, false);
            }
        }
    } while (function != 8);

    return 0;
}
