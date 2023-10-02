#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
#include<sqlite3.h>

using namespace std;

class food {
public:
    int id;
    string name;
    float price;
    int qty;
};
//for tree
struct Node {
    int id;
    string name;
    float price;
    int qty;
    Node* left, * right;
};
//for linked list
struct Element {
    int idll;
    string namell;
    float pricell;
    int qtyll;
    Element* next;
};
struct Element* headll = NULL;

Node* insertTree(Node* root, int newid, string newname, float newprice, int newqty);
static int callback(void* data, int argc, char** argv, char** ColName);
void  createTable_();
void inorderToDB(Node* root);
//Add function
void insertFoodinDB();
//Show function
void showFood();
//Modify function
void modifyFood();
//Search function
static int searching(void* data, int argc, char** argv, char** ColName);
void searchFood();
//Delete function
void deleteFood();
//Restock function
void restockFood();
//For Customer
//Buy function
void buyFood();
static int buying(void* data, int argc, char** argv, char** ColName);
void add_Element(int new_id, string new_name, float new_price, int new_qty);//if head == NULL
void insert_End(int new_id, string new_name, float new_price, int new_qty);//if head != NULL
void in_cart();
void Tito_Main();
Node* insertTree(Node* root, int newid, string newname, float newprice, int newqty) {
    if (root == NULL) {
        //new node here
        root = new Node;
        root->id = newid;
        root->name = newname;
        root->price = newprice;
        root->qty = newqty;
        root->left = NULL;
        root->right = NULL;
    }
    else if (newid > root->id) { //go right
        root->right = insertTree(root->right, newid, newname, newprice, newqty);
    }
    else if (newid < root->id) { //go left
        root->left = insertTree(root->left, newid, newname, newprice, newqty);
    }
    return root;
}
static int callback(void* data, int argc, char** argv, char** ColName) {
    int i;
    for (i = 0; i < argc; i++) {
        if (i == 0) {
            cout.setf(ios::left);
            cout.width(24);
            cout << " ";
            cout.setf(ios::left);
            cout.width(8);
            cout << argv[i];
        }
        else if (i == 1) {
            cout.setf(ios::left);
            cout.width(20);
            cout << argv[i];
        }
        else if (i == 2) {
            cout.setf(ios::left);
            cout.width(15);
            cout << argv[i];
        }
        else if (i == 3) {
            cout << argv[i];
        }
    }
    cout << endl;
    return 0;
}
void  createTable_()
{
    sqlite3* db;
    int rc;
    char* zErrMsg = 0;

    rc = sqlite3_open("DataBaseSystem.db", &db);
    string sql = "CREATE TABLE FOOD("\
        "ID INT PRIMARY KEY       NOT NULL,"\
        "NAME           TEXT      NOT NULL,"\
        "PRICE          REAL,"\
        "QUANTITY       INT       NOT NULL);";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    sqlite3_close(db);
}
void inorderToDB(Node* root) { //put in DB in order
    food f1;
    string sql;
    sqlite3* db;
    sqlite3_stmt* stmt;
    if (root != NULL) {
        inorderToDB(root->left);
        sql = "INSERT INTO FOOD(ID, NAME, PRICE, QUANTITY) VALUES('" + to_string(root->id) + "','" + root->name + "','" + to_string(root->price) + "','" + to_string(root->qty) + "');";
        if (sqlite3_open("DataBaseSystem.db", &db) == SQLITE_OK) {
            sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);//preparing the statement
            sqlite3_step(stmt);//executing the statement
            inorderToDB(root->right);
        }
       /* sqlite3_finalize(stmt);*/
        sqlite3_close(db);
    }
}
//Add function
void insertFoodinDB() {
    int toAdd;

    food f1;
    Node* r1 = NULL;
    showFood();
    createTable_();
    cout << "\t\t\tEnter number of food to add: ";
    cin >> toAdd;
    for (int i = 0; i < toAdd; i++) {
        cout << "\t\t\tEnter ID: ";
        cin >> f1.id;
        cout << "\t\t\tEnter name: ";
        cin.sync();
        getline(cin, f1.name);
        cout << "\t\t\tEnter price: ";
        cin >> f1.price;
        cout << "\t\t\tEnter quantity: ";
        cin >> f1.qty;
        r1 = insertTree(r1, f1.id, f1.name, f1.price, f1.qty);
    }
    inorderToDB(r1);
}
//Show function
void showFood() {
    sqlite3* db;
    int rc;
    char* zErrMsg = 0;
    const char* data = "Callback function called";
    cout << "\t\t\t\t\t\tMENU" << endl << endl;
    cout << "\t\t\tID      NAME                PRICE(USD)     QUANTITY" << endl;
    rc = sqlite3_open("DataBaseSystem.db", &db);
    string sql = "SELECT *from FOOD";
    rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    sqlite3_close(db);
}
//Modify function
void modifyFood() {
    food f2;
    sqlite3* db;
    sqlite3_stmt* stmt;

    string sql;

    int oldId;
    showFood();
    cout << endl << "\t\t\tEnter food's ID: ";
    cin >> oldId;
    cout << "\t\t\tEnter new ID: ";
    cin >> f2.id;
    cout << "\t\t\tEnter new name: ";
    cin.sync();
    getline(cin, f2.name);
    cout << "\t\t\tEnter new price: ";
    cin >> f2.price;
    cout << "\t\t\tEnter new quantity: ";
    cin >> f2.qty;
    sql = "UPDATE FOOD SET ID = " + to_string(f2.id) + ", NAME = '" + f2.name + "', PRICE = " + to_string(f2.price) + ", QUANTITY = " + to_string(f2.qty) +//dun forget '' at NAME
        " WHERE ID = " + to_string(oldId);
    if (sqlite3_open("DataBaseSystem.db", &db) == SQLITE_OK) {
        sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);//preparing the statement
        sqlite3_step(stmt);//executing the statement
        cout << endl << "\t\t\tOperation ends..." << endl;
    }
 /*   sqlite3_finalize(stmt);*/
    sqlite3_close(db);
}
//Search function
static int searching(void* data, int argc, char** argv, char** ColName) {
    int i;
    cout << "\t\t\tID      NAME                PRICE(USD)     QUANTITY" << endl;
    for (i = 0; i < argc; i++) {
        if (i == 0) {
            cout.setf(ios::left);
            cout.width(24);
            cout << " ";
            cout.setf(ios::left);
            cout.width(8);
            cout << argv[i];
        }
        else if (i == 1) {
            cout.setf(ios::left);
            cout.width(20);
            cout << argv[i];
        }
        else if (i == 2) {
            cout.setf(ios::left);
            cout.width(15);
            cout << argv[i];
        }
        else if (i == 3) {
            cout << argv[i];
        }
    }
    cout << endl;
    cout << endl << "\t\t\tItem has found successfully..." << endl;
    return 0;
}
void searchFood() {
    sqlite3* db;
    int rc;
    int searchID;

    char* zErrMsg = 0;
    showFood();
    const char* data = "Callback function called";
    rc = sqlite3_open("DataBaseSystem.db", &db);
    cout << endl << "\t\t\tSearching an item..." << endl;
    cout << "\t\t\tEnter food's ID: ";
    cin >> searchID;
    system("cls");
    string sql = "SELECT *from FOOD WHERE ID =" + to_string(searchID);

    rc = sqlite3_exec(db, sql.c_str(), searching, (void*)data, &zErrMsg);
    sqlite3_close(db);
}
//For delete
void deleteFood() {
    sqlite3* db;
    int rc;
    int deleteID;

    char* zErrMsg = 0;
    const char* data = "Callback function called";
    showFood();
    rc = sqlite3_open("DataBaseSystem.db", &db);
    cout << endl << "\t\t\tDeleting an item..." << endl;
    cout << "\t\t\tEnter food's ID: ";
    cin >> deleteID;
    string sql = "DELETE from FOOD WHERE ID =" + to_string(deleteID);

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    sqlite3_close(db);
    cout << endl << "\t\t\tOperation ends..." << endl;
}
//Restock function
void restockFood() {
    sqlite3* db;
    int rc;
    int restockID, addMore;

    char* zErrMsg = 0;
    rc = sqlite3_open("DataBaseSystem.db", &db);
    showFood();
    cout << "\t\t\tSearching an item..." << endl;
    cout << "\t\t\tEnter food's ID: ";
    cin >> restockID;
    cout << "\t\t\tEnter the amount to add: ";
    cin >> addMore;
    string sql = " UPDATE FOOD SET QUANTITY = QUANTITY + " + to_string(addMore) + " WHERE ID IN (SELECT ID FROM FOOD WHERE ID = " + to_string(restockID) + ");";

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    sqlite3_close(db);
}
//Buy function
static int buying(void* data, int argc, char** argv, char** ColName) {
    Element* e = new Element;
    e->idll = atoi(argv[0]);
    e->namell = argv[1];
    e->pricell = atof(argv[2]);
    e->qtyll = atoi(argv[3]);
    if (headll == NULL) {
        add_Element(e->idll, e->namell, e->pricell, e->qtyll);
    }
    else {
        insert_End(e->idll, e->namell, e->pricell, e->qtyll);
    }
    return 0;
}

void buyFood(){
    sqlite3 *db;
    int rc,buyID,i=0;
    int searchID;

    char *zErrMsg = 0;
    const char* data = "Buying function called";
    //rc = sqlite3_open("food.db", &db);
    do{
        rc = sqlite3_open("food.db", &db);
        showFood();
        cout<<endl<<"\t\t\tBuying an item..."<<endl;
        cout<<"\t\t\tEnter 0 to STOP"<<endl;
        cout<<"\t\t\tEnter food's ID: ";
        cin>>buyID;
        system("cls");
        string sql = "SELECT *from FOOD WHERE ID ="+to_string(buyID);
        rc = sqlite3_exec(db, sql.c_str(), buying, (void*)data, &zErrMsg);
        sqlite3_close(db);
        in_cart();
    }while(buyID != 0);

}
void add_Element(int new_id, string new_name, float new_price, int new_qty) {
    struct Element* new_element = new Element;
    new_element->idll = new_id;
    new_element->namell = new_name;
    new_element->pricell = new_price;
    new_element->qtyll = new_qty;
    new_element->next = headll;
    headll = new_element;
}
void insert_End(int new_id, string new_name, float new_price, int new_qty) {
    struct Element* newelement = new Element;
    newelement->idll = new_id;
    newelement->namell = new_name;
    newelement->pricell = new_price;
    newelement->qtyll = new_qty;
    newelement->next = NULL;
    //traversal to last node
    struct Element* tmp = headll;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newelement;
}
void in_cart() {
    Element* tmp;
    tmp = headll;
    float total = 0;
    cout<<"\t\t\t\t\t\tIN CART"<<endl<<endl;
    cout << "\t\t\tID      NAME                PRICE(USD)" << endl;
    while (tmp != NULL) {
        cout.setf(ios::left);
        cout.width(24);
        cout << " ";
        cout.setf(ios::left);
        cout.width(8);
        cout << tmp->idll;

        cout.setf(ios::left);
        cout.width(20);
        cout << tmp->namell;

        cout.setf(ios::left);
        cout.width(15);
        cout << tmp->pricell;
        total = total + tmp->pricell;

        cout << endl;
        tmp = tmp->next;
    }
    cout<<"\t\t*******************************************************************"<<endl;
    cout << "\t\t\tTotal: " << total << "$" << endl;
}

void Tito_Main()
{
    int choice;
    char yon;
    do{
        cout << "\t\t\t\tWELCOME TO FOOD SECTION" << endl;
        cout << endl << "\t\t\t1. Add product" << endl;
        cout << endl << "\t\t\t2. Show product" << endl;
        cout << endl << "\t\t\t3. Modify product" << endl;
        cout << endl << "\t\t\t4. Search product" << endl;
        cout << endl << "\t\t\t5. Delete product" << endl;
        cout << endl << "\t\t\t6. Restock product" << endl;
        cout << endl << "\t\t\t7. Buy" << endl;
        cout << endl << "\t\t\t8. Exit" << endl;
        cout << endl << "\t\t\tChoose your option: ";
        cout << "[ ]\b\b";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            insertFoodinDB();
            break;
        case 2:
            showFood();
            break;
        case 3:
            modifyFood();
            break;
        case 4:
            searchFood();
            break;
        case 5:
            deleteFood();
            break;
        case 6:
            restockFood();
            break;
        case 7:
            buyFood();
            break;
        case 8:
            break;
        }
        cout<<"\n\n\t\t\t\tPress 'y' to continue";
        cin>>yon;
        system("cls");
    }while(yon == 'y');
}

