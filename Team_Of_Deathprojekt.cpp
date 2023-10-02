#include <iostream>
#include <cstring>
#include <conio.h>
#include <sqlite3.h>
#include "RITH.h"
#include "TITO.h"
#include "KIMHOUNG.h"
#include "SENGLY.h"

using namespace std;

int input_ID;
string input_name;
int input_quantity;
float input_price;

int choice;

sqlite3* db;
sqlite3_stmt* stmt;
char* err;

using namespace std;

void section()
{

    cout << "\n\t\t-----------------------------------------------\n"
         << "\n\t\t\tWelcome To Admin Menu"
         << "\n\t\t-----------------------------------------------\n";
    cout << "\n\t\t1]. Food"
         << "\n\t\t2]. Beverage"
         << "\n\t\t3]. Clothes"
         << "\n\t\t4]. Accessories";
}

int main()
{
    int ch1, ch2;

    string email, username, password;
    string EMAIL, PASSWORD;

    cout << "\n\n\n\n\n\n\n\n\n\t\t\t|============= WELCOME TO SALE MANAGEMENT SYSTEM =============|";
    system("cls");
    cout << "\n\n\t\t        SALE MANAGEMENT SYSTEM" << endl;
    cout << "\t=====================================================";
    cout << "\n\n\t\t  1]. ADMIN LOGIN\n\n\t\t  2]. CUSTOMER LOGIN" << endl;
    cout << "\n\t===================================================";
    cout << "\n\tEnter your choice : ";
    cin >> ch1;

    if (ch1 == 1)
    {
        system("cls");
        cout << "\n==================================================";
        cout << "\n\n\t\t   ADMIN LOGIN" << endl;
        cout << "\n==================================================";

        cout << "\n\n\t\t Enter Email : ";
        cin >> email;
        cout << "\n\n\t\t Enter Password : ";
        cin >> password;

          if (email == "soy" && password == "ITC88889999")
          {
              cout << "\n\n\t\tLOGIN!";
             system("cls");
             section();
             cout << "\n\t\t Enter choice ";
             cout << "[ ]\b\b";
             cin >> choice;

            system("cls");

                   if (choice == 1)
                   {
                cout << "\n\t\t--------------------------------------------------\n"
                 << "\n\t\t\tWelcome To Food Section"
                 << "\n\t\t--------------------------------------------------\n";
                 Tito_Main();


    }
    else if (choice == 2)
    {
        cout << "\n\t\t--------------------------------------------------\n"
            << "\n\t\t\tWelcome To Beverage Section"
            << "\n\t\t--------------------------------------------------\n";
        RITH_main();
    }
    else if (choice == 3)
    {
        cout << "\n\t\t--------------------------------------------------\n"
             << "\n\t\t\tWelcome To Clothes Section"
             << "\n\t\t--------------------------------------------------\n";
        KIMHOUNG_main();
    }
    else if (choice == 4)
    {
        cout << "\n\t\t--------------------------------------------------\n"
            << "\n\t\t\tWelcome To Accessory Section"
            << "\n\t\t--------------------------------------------------\n";
        Sengly_main();

    }
          }
    }
}
