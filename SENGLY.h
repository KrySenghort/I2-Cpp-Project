#ifndef SENGLY_H_INCLUDED
#define SENGLY_H_INCLUDED

#endif // SENGLY_H_INCLUDED

#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include "sqlite3.h"

// declarations of functions

using namespace std;
int search(int);
int display();

string check(int);       //   for checking quantity
//   build a node

struct node {
    int ID;
    string proName;
    double prePrice;            //   product price
    int quantity;
    struct    node* next;
};
struct node* head = NULL;

static int callback(void* data, int argc, char** argv, char** ColName);

void  createTable();
void _createDataBase();
void end();
void begin();
void modify();
void delPro();
void buy();

static int buying(void* data, int argc, char** argv, char** ColName);

//        Main function


void Sengly_main() {

int temp = 1;
    while (true) {
        int ch;                     //            choice for below message
        cout
            << "\t\tEnter 1 for ADD a new product \n\n\t\tEnter 2 to display all products \n\n\t\tEnter 3 for MODIFY Existing product\n\n";
        cout
            << "\t\tEnter 4 for Delete a particular product item\n\n\t\tEnter 5 for Buy something\n\n\t\tEnter 0 for exit\n\n";
        cout << "*********>>>>>***********>>>>>>>>";
        cin >> ch;
        switch (ch) {
        case 1:

            _createDataBase();
            createTable();
            if (temp == 0) {              //    Second time and on ward this is only executed
                end();
            }
            if (temp == 1) {               //    this will be executed only one time
                begin();
                temp = 0;
            }
            break;
        case 2:
            system("cls");
            cout << "1>> for Show Existing Items\n";
            int c;
            cin >> c;
           display();
           break;
        case 3:
            modify();
            break;
        case 4:
            delPro();
            break;
        case 5:
            buy();
            break;
        case 0:
            //        cout<<"Exiting..."<<end;
            exit(true);                    //   exit from while loop
            break;
        default:
            system("cls");
            cout << "\t\t<<<Wrong choice>>>\n\n";
        }
    }
}
void _createDataBase()
{
    sqlite3* DB;

    int exit = 0;
    exit = sqlite3_open("DataBaseSystem.db", &DB);

    if (exit != SQLITE_OK)
    {
        std::cerr << "\n\t\tError in creating Database...!";
    }

    sqlite3_close(DB);
}

void  createTable()
{
    sqlite3* db;
    int rc;
    string sql;
    char* zErrMsg = 0;

    rc = sqlite3_open("DataBaseSystem.db", &db);
    sql = "CREATE TABLE ACCESSORY("\
        "ID INT PRIMARY KEY       NOT NULL,"\
        "NAME           TEXT      NOT NULL,"\
        "PRICE          REAL,"\
        "QUANTITY       INT       NOT NULL);";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    sqlite3_close(db);
}

void insert_item(int ID, std::string name, int quantity, double price)
{
    sqlite3* DB;
    int exit = 0;
    char* messageError;

    std::string query = ("INSERT INTO ACCESSORY (ID , NAME , QUANTITY , PRICE) VALUES (" + std::to_string(ID) + " , '" + name + "', " + std::to_string(quantity) + " , " + std::to_string(price) + ");");

    exit = sqlite3_open("DataBaseSystem.db", &DB);

    exit = sqlite3_exec(DB, query.c_str(), nullptr, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error in inserting data!" << std::endl;
    }
    sqlite3_close(DB);
}


//      for entering(saving) 1st record in list
void begin()
{
    system("cls");
    int id, quant;           //  quant    for quantity
    string name;
    double pre;            //  pre for price
    struct node* t = new node;
    cout << "\t\t\tEnter product ID:-";
    cin >> id;
    t->ID = id;
    cout << "\t\t\tEnter product Name:-";
    cin >> name;
    t->proName = name;
    cout << "\t\t\tEnter product price:-";
    cin >> pre;
    t->prePrice = pre;
    cout << "\t\t\tEnter product quantity:-";
    cin >> quant;
    t->quantity = quant;
    t->next = head;
    head = t;
    system("cls");
    cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";

    insert_item(id, name, quant, pre);

}
// for entering(saving) 2nd and onward records in list

void end()
{
    system("cls");
    int id, quant;      //   quant for quantity
    string name;
    double pre;            //  pre for price
    struct node* t = new node;
    struct node* p = head;
    cout << "\t\t\tEnter product ID:-";
    cin >> id;
    t->ID = id;
    cout << "\t\t\tEnter product Name:-";
    cin >> name;
    t->proName = name;
    cout << "\t\t\tEnter product price:-";
    cin >> pre;
    t->prePrice = pre;
    cout << "\t\t\tEnter product quantity:-";
    cin >> quant;
    t->quantity = quant;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = t;
    t->next = NULL;
    system("cls");
    cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";

    insert_item(id, name, quant, pre);
}
void delPro()
{
    system("cls");
    sqlite3* db;
    display();
    int id;
    int rc;
    char* zErrMsg = 0;
    const char* data = "Callback function called";
    rc = sqlite3_open("DataBaseSystem.db", &db);
    struct node* cur = head;
    struct node* pre = head;
    cout << "\n\nEnter ID to delete that product:\n\n";
    cin >> id;
    if (head == NULL)
    {
        system("cls");
        cout << "List is empty" << endl;
    }
    int pos = 0;
    int count = display();               //   for load no of nodes
    pos = search(id);                        //   for check weather desire node is exist or not
    if (pos <= count) {

        while (cur->ID != id) {                //  for delete middle area products
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        system("cls");
        cout << "\n<<item is deleted>>\n";
    }
    else {
        cout << "\n<<<Not found>>\n\n";
    }
    string sql = "DELETE from ACCESSORY WHERE ID =" + to_string(id);

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    sqlite3_close(db);
    cout << endl << "\t\t\tOperation ends..." << endl;
}
void modify() {
    sqlite3* db;
    sqlite3_stmt *stmt;

    string sql;
    display();
    int id;
    int quant;
    double pre;        //    pre for price
    string pName;      //   pName for new name
    if (head == NULL)
    {
        system("cls");
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "\n\nEnter ID to modify product Name and its price:\n";
        cin >> id;
        struct node* cur = head;
        int pos = 0;
        int count = display();               //   for load no of nodes
        pos = search(id);                        //   for check weather desire node is exist or not
        if (pos <= count) {

            while (cur->ID != id) {
                cur = cur->next;
            }
            cout << "\n\nOld Name : " << cur->proName;
            cout << "\n\nOld Price : " << cur->prePrice << endl;
            cout << "\nOld Quantity : " << cur->quantity << endl;

            cout << "\nEnter new Name:";
            cin >> pName;
            cur->proName = pName;
            cout << "Enter new Price:";
            cin >> pre;
            cur->prePrice = pre;
              cout << "Enter new Quantity:";
              cin >> quant;
              cur->quantity=quant;
        }
        else {
            cout << id << " is <<<Not found>>\n\n";

        }
        sql = "UPDATE ACCESSORY SET ID = "+to_string(id)+", NAME = '"+pName+"', PRICE = "+to_string(pre)+", QUANTITY = "+to_string(quant)+
          " WHERE ID = "+to_string(id);
    if (sqlite3_open("DataBaseSystem.db", &db) == SQLITE_OK){
        sqlite3_prepare( db, sql.c_str(), -1, &stmt, NULL );//preparing the statement
        sqlite3_step( stmt );//executing the statement
        cout<<endl<<"\t\t\tOperation ends..."<<endl;
    }
}
}

int display() {
    system("cls");
    sqlite3*db;
    int rc;
    char *sql;
    char *zErrMsg = 0;
    const char* data = "Callback function called";
    int c = 0;             //   c for count products
    struct node* p = head;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\t\tPrice(USD)\tQuantity\n";
    while (p != NULL)
    {
        cout << p->ID << "\t\t" << p->proName << "\t\t\t\t" << p->prePrice << "\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
        p = p->next;
        c = c + 1;
    }
    cout << "\nTotal products in our store is : " << c << "\n\n\n";
    return c;
  rc = sqlite3_open("DataBaseSystem.db", &db);
    sql = "SELECT *from ACCESSORY";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    sqlite3_close(db);

}
string check(int quant) {  //        check function
    sqlite3*db;
    int rc;
    char *sql;
    char *zErrMsg = 0;
    const char* data = "Callback function called";
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();

    if (quant <= 0)
        return "out of stock!";
    else
        return quantity;
       rc = sqlite3_open("DataBaseSystem.db", &db);
    sql = "SELECT *from ACCESSORY";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    sqlite3_close(db);
}
void buy() {
    system("cls");
    sqlite3* db;
    int rc;
    char* zErrMsg = 0;
    const char* data = "Buying function called";
    rc = sqlite3_open("DataBaseSystem.db", &db);
    string products[20]; //   for display sold items
    int pay = 0, no, c = 0, price, id, i = 1;
    if (head == NULL) {
        cout << "\n<<<<There is no items to buy>>>>\n\n";
    }
    else {
        cout << "How many items you wanna to buy!\n";
        cin >> no;
        int count = display();           //   for store no of nodes  in c
        while (i <= no) {
            struct node* cur = head;

            int quant, cho;              //   quant   for quantity  and cho for choice
            cout << "Enter id of item that you want to buy: ";
            int id, pos = 0;
            cin >> id;
            pos = search(id);
            string sql = "SELECT *from ACCESSORY WHERE ID =" + to_string(id);

            sqlite3_close(db);
            if (pos <= count) {
                //     item is available in store
                while (cur->ID != id) {
                    cur = cur->next;
                }
                cout << "How many quantities you want:";
                cin >> quant;
                products[c] = cur->proName; c++;
                pay = pay + (cur->prePrice * quant);         //     calculate Bill
                cur->quantity = cur->quantity - quant;           //    change quantity
                i++;
            }
            else {
                cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        }
        system("cls");
        cout << "\n\n\n\n\t\t\tYou have bought : ";
        for (int i = 0; i < no; i++) {              //    show that item you have bought
            cout << products[i] << ",";
        }
        price = pay * (0.95);           //    with 5% discount
        cout << "\n\nOriginal price : " << pay;
        cout << "\n with 5% discount: " << price << "\nThank you! for the shopping\n\n";
    }
}

int search(int id)                     //    for search item in list
{
    sqlite3 *db;
    int rc;

    char *zErrMsg = 0;
    display();
    const char* data = "Callback function called";
    rc = sqlite3_open("DataBaseSystem.db", &db);
    int count = 1;
    struct node* p = head;
    while (p != NULL)
    {
        if (p->ID == id)
            break;
        else
            count++;
        p = p->next;
    }
    return count;
    string sql = "SELECT *from ACCESSORY WHERE ID ="+to_string(id);
    sqlite3_close(db);
}
