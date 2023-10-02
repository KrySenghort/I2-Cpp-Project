#include <iostream>
#include <sqlite3.h>
#include <string>
#include <cctype>
#include <stdlib.h>

using namespace std;

struct cloth{
    string name, brand;
    int id, price, qty;
};
// Retrieve contents of database used by select Data
// argc: hold the number of results,
// azColName: holds each column returned in array,
// argv: holds each value in array

static int CallBack(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("|%-11.10s", argv[i]);
   }
   printf("\n");
   return 0;
}
void CreateTable(){
    sqlite3 *db;
   char *error;
   int rc;
   char *sql;

   rc = sqlite3_open("DataBaseSystem.db", &db);

   if (rc == SQLITE_OK){
        sql = "CREATE TABLE IF NOT EXISTS CLOTHES("  \
          "ID INT PRIMARY KEY     NOT NULL," \
          "NAME           TEXT    NOT NULL," \
          "BRAND          TEXT    NOT NULL," \
          "PRICE          REAL     NOT NULL," \
          "QUANTITY       INT    NOT NULL);";
       rc = sqlite3_exec(db, sql, CallBack, 0, &error);
       if( rc != SQLITE_OK ){
            cout<<"\nCREATE TABLE FAILED...";
            cout<<"SQL error: "<<error;
            sqlite3_close(db);
        }
   }else{
        cout<<"\n\nCREATE OPEN FAILED...";
        cout<<"\nSQL error: "<<error;
        sqlite3_close(db);
   }
}

void insertProduct(int id, string name, string brand, int price, int qty){
    sqlite3 *db;
    sqlite3_stmt * stm;
    string sql;
    char *error;
    int rc;
    rc = sqlite3_open("DataBaseSystem.db", &db);

    if(rc == SQLITE_OK){

        sql = "INSERT INTO CLOTHES(ID, NAME, BRAND, PRICE, QUANTITY) VALUES('" + to_string(id) + "','" + name + "','" + brand + "','" + to_string(price) + "','" + to_string(qty) + "');";

        rc = sqlite3_exec(db, sql.c_str(), CallBack, 0, &error);
        if (rc == SQLITE_OK){
            sqlite3_close(db);
            cout << "\n DATA INSERT SUCCESSFULLY...\n";
        }
        else{
            cout << "\nFAILED TO INSERT DATA...\nSQL error: "<<error;
            cout<<"SQL error: "<<error;
            sqlite3_close(db);
        }
   }else{
        cout << "\nFAILED TO OPEN DATABASE...\nSQL error: "<<error;
        sqlite3_close(db);
   }
}
void DisplayProduct(){
    sqlite3 *db;
   char *error = 0;
   int rc;
   char *sql;

   rc = sqlite3_open("DataBaseSystem.db", &db);

   if (rc == SQLITE_OK){
        sql = "SELECT * from CLOTHES";

        printf("|%-11.10s|%-11.10s|%-11.10s|%-11.10s|%-11.10s|\n", "ID", "NAME", "BRAND", "UNIT-PRICE", "QUANTITY");

       rc = sqlite3_exec(db, sql, CallBack, 0, &error);

       if( rc != SQLITE_OK ) {
          cout<<"SQL error: "<<error;
       } else {
           sqlite3_close(db);
       }
   }else{
       cout<<"\nFAIL TO OPEN DATABASE...\nSQL error: "<<error;
       sqlite3_close(db);
   }
   cout<<"\n\n\t\t";
   system ("PAUSE");
}
void searchProduct(int id){
    sqlite3 *db;
    char* error;
    int rc;
    printf("|%-11.10s|%-11.10s|%-11.10s|%-11.10s|%-11.10s|\n", "ID", "NAME", "BRAND", "UNIT-PRICE", "QUANTITY");
    rc = sqlite3_open("DataBaseSystem.db", &db);

    if(rc == SQLITE_OK){
        string query = "SELECT * FROM CLOTHES WHERE ID = " + to_string(id) + ";";
        rc = sqlite3_exec(db, query.c_str(), CallBack, 0, &error);
        if (rc == SQLITE_OK){
            sqlite3_close(db);
        }else{

            sqlite3_close(db);
            cout<<"\n\n PRODUCT SEARCH UNSUCCESSFULLY...";
        }
    }else{

        sqlite3_close(db);
    }
}
void modifyProduct(int id, string ColChoice, string new_data){
    sqlite3 *db;
    char* error;
    int rc;

    sqlite3_open("DataBaseSystem.db", &db);

    if (rc == SQLITE_OK){
        string query = "UPDATE CLOTHES SET " + ColChoice + " = " + "'" + new_data + "'" + " WHERE ID = " + to_string(id) + ";";
        rc = sqlite3_exec(db, query.c_str(), CallBack, 0, &error);

        if (rc == SQLITE_OK){
            sqlite3_close(db);
            cout<<"\n\t PRODUCT MODIFY SUCCESSFULLY...\n\n";
        }else{
            cout<<"SQL error: "<<error;
            sqlite3_close(db);
            cout<<"\n\n PRODUCT MODIFY UNSUCCESSFULLY...\n\n";
        }
    }else{
            cout<<"SQL error: "<<error;
            cout<<"\n\n OPEN UNSUCCESSFULLY...\n\n";
            sqlite3_close(db);
        }
}
void deleteProduct(int id){
    sqlite3 *db;
    char* error;
    int rc;
    rc = sqlite3_open("DataBaseSystem.db", &db);

    if(rc == SQLITE_OK){
        string query = "DELETE FROM CLOTHES WHERE ID = " + to_string(id) + ";";
        rc = sqlite3_exec(db, query.c_str(), CallBack, 0, &error);
        if (rc == SQLITE_OK){
            sqlite3_close(db);
        }else{
            cout<<"SQL error: "<<error;
            sqlite3_close(db);
            cout<<"\n\n PRODUCT DELETE UNSUCCESSFULLY...";
        }
    }else{
        cout<<"SQL error: "<<error;
        cout<<"\n\n OPEN UNSUCCESSFULLY...\n\n";
        sqlite3_close(db);
    }
}
void restockCloth(int restockCloth, int ClothID){
    sqlite3 *db;
    char *error;
    int rc;

    rc = sqlite3_open("DataBaseSystem.db", &db);

    if (rc == SQLITE_OK){
        string query = "UPDATE CLOTHES SET QUANTITY = QUANTITY + " + to_string(restockCloth) + " WHERE ID = " + to_string(ClothID) + ";";
        rc = sqlite3_exec(db, query.c_str(), CallBack, 0, &error);
        if(rc == SQLITE_OK){
            cout<< "\n\n\t\tPRODUCTS RESTOCK SUCCESS...";
            sqlite3_close(db);
        }else{
            cout<<"SQL error: "<<error;
            sqlite3_close(db);
        }
    }else{
        cout<<"SQL error: "<<error;
        sqlite3_close(db);
    }
}

struct StackListNode{
    int data;
    struct StackListNode *link;
}*top = NULL;
int pop(){
        struct StackListNode*temp;
        temp = top;
        int val = temp->data;
        top = top->link;
        free(temp);
        temp = NULL;
        cout<<"\n\nThe ID of the Recently Added Product: "<<val<<"\n\n";
        searchProduct(val);
        deleteProduct(val);
        return val; // return the value that have been delete
}
void push(int data){
        struct StackListNode* newNode;
        newNode = (struct StackListNode*) malloc(sizeof(newNode));
        newNode->data = data;
        newNode->link = NULL;
        newNode->link = top;
        top = newNode;
}

struct BST_Node {
   int data;
   struct BST_Node *leftChild, *rightChild;
}*root = NULL;
void BTS_InsertCloth(int data) {
   struct BST_Node *tempNode = (struct BST_Node*) malloc(sizeof(BST_Node));
   struct BST_Node *current, *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {
         parent = current;

         if(data < parent->data) {
            current = current->leftChild;
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }
         else {
            current = current->rightChild;

            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
struct BST_Node* BTS_SearchCloth(int data){
   struct BST_Node *current = root;
   while(current->data != data){
      if(current != NULL) {

         if(current->data > data){
            current = current->leftChild;
         }
         else {
            current = current->rightChild;
         }
         if(current == NULL){
            return NULL;
         }
      }
   }
   cout<<"ID PRODUCT FOUND : " << current->data<<"\n\n";
   searchProduct(current->data);
   cout<<"\n\n\t\t";
   system ("PAUSE");
   return current;
}

void AddMenu(){
        system("CLS");
        CreateTable();
        struct cloth c1;

        sqlite3 *db;
        char *error = 0;
        sqlite3_stmt *stm;

        int rc = sqlite3_open("DataBaseSystem.db", &db);
        char *sql = "SELECT ID FROM CLOTHES";
        rc = sqlite3_prepare_v2(db, sql, -1, &stm, 0);

        int readCode = 0, a;

        cout<<"\n\t\t||WELCOME TO CLOTHES ADD MENU||\n\n";
        cout<<"\nEnter ID of the Product = ";
        cin>>c1.id;

        while((readCode = sqlite3_step(stm)) == SQLITE_ROW) {
            a = sqlite3_column_int(stm, 0);
            while(c1.id == a){
                cout<<"YOU HAVE ENTER EXISTED ID...\nENTER ID AGAIN : ";
                cin>>c1.id;
                }
        }

        cout<<"\nEnter Name of the Product = ";
        cin.sync();
        getline(cin, c1.name);
        cout<<"\nEnter Brand Name of the Product = ";
        cin.sync();
        getline(cin, c1.brand);
        cout<<"\nEnter Unit Price of the Product = ";
        cin>>c1.price;
        cout<<"\nEnter Quantity of the product = ";
        cin>>c1.qty;
        insertProduct(c1.id, c1.name, c1.brand, c1.price, c1.qty);
        sqlite3_finalize(stm);
        sqlite3_close(db);
        DisplayProduct();
}
void ModifyMenu(){
    system("CLS");
    int id, choice;
    string ColChoice, new_data;

    cout<<"\n\t\t||WELCOME TO CLOTHES MODIFY MENU||\n\n";
    DisplayProduct();
    cout<<"\n\nEnter ID Product to Modify: ";
    cin>>id;
    cout<<"\n\t\t>>>DATA SELECTED>>>\n";
    searchProduct(id);
    cout<<"\n\n[1]. NAME";
    cout<<"\n[2]. BRAND";
    cout<<"\n[3]. PRICE";
    cout<<"\n[4]. QUANTITY";
    cout<<"\n\n\t\tEnter Choice you want to Modify: [ ]\b\b";
    cin>>choice;
    switch(choice){
        case 1:
            ColChoice = "Name";
            cout<<"\nEnter NEW Name = ";
            cin.sync();
            getline(cin, new_data);
            modifyProduct(id, ColChoice, new_data);
            searchProduct(id);
            cout<<"\n\n\t\t";
            system ("PAUSE");
            break;
        case 2:
            ColChoice = "BRAND";
            cout<<"\nEnter NEW Brand = ";
            cin.sync();
            getline(cin, new_data);
            modifyProduct(id, ColChoice, new_data);
            searchProduct(id);
            cout<<"\n\n\t\t";
            system ("PAUSE");
            break;
        case 3:
            ColChoice = "PRICE";
            cout<<"\nEnter NEW Price = ";
            cin.sync();
            getline(cin, new_data);
            modifyProduct(id, ColChoice, new_data);
            searchProduct(id);
            cout<<"\n\n\t\t";
            system ("PAUSE");
            break;
        case 4:
            ColChoice = "QUANTITY";
            cout<<"\nEnter NEW Quantity = ";
            cin.sync();
            getline(cin, new_data);
            modifyProduct(id, ColChoice, new_data);
            searchProduct(id);
            cout<<"\n\n\t\t";
            system ("PAUSE");
            break;

        default :
            cout<<"\n\n\t\tYOU HAVE ENTER WRONG CHOICE...";
            break;
    }
}
void SearchMenu(){
    system("CLS");
    struct BTS_Node* t1;
    sqlite3 *db;
    sqlite3_stmt *res;
    char *error;

    int rc = sqlite3_open("DataBaseSystem.db", &db);
    char *sql = "SELECT ID FROM CLOTHES";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    int readCode = 0, a;

    while((readCode = sqlite3_step(res)) == SQLITE_ROW) {
        a = sqlite3_column_int(res, 0);
        BTS_InsertCloth(a);
    }

    cout<<"\n\t\t||WELCOME TO CLOTHES SEARCH MENU||\n\n";
    int ID;
    cout<<"Enter ID Product to SEARCH: ";
    cin>>ID;

    cout<<"\n";
    BTS_SearchCloth(ID);

    cout<<"\n\n\t\tPRODUCT SEARCH SUCCESSFULLY...";
}
void DeleteMenu(){
    system("CLS");
    int id, choice;
    cout<<"\n\t\t||WELCOME TO CLOTHES DELETE MENU||\n\n";
    DisplayProduct();
    cout<<"\n[1].DELETE PRODUCT BY ID ";
    cout<<"\n[2].DELETE THE RECENTLY ADDED";
    cout<<"\n\nYOUR CHOICE : [ ]\b\b";
    cin>>choice;
    switch(choice){
        case 1:{
            system("CLS");
            DisplayProduct();
            cout<<"\nENTER ID TO DELETE : ";
            cin>>id;
            deleteProduct(id);
            cout<<"\n\n\t\tPRODUCT DELETE SUCCESSFULLY";
                }
        case 2:{
            system("CLS");
            struct StackListNode S1;
            cout<<"\n\t<<<THE RECENTLY ADDED>>>";
            sqlite3 *db;
            char *errror = 0;
            sqlite3_stmt *stm;

            int rc = sqlite3_open("DataBaseSystem.db", &db);
            char *sql = "SELECT ID FROM CLOTHES";
            rc = sqlite3_prepare_v2(db, sql, -1, &stm, 0);

            int readCode = 0, a;

            while((readCode = sqlite3_step(stm)) == SQLITE_ROW) {
                a = sqlite3_column_int(stm, 0);
                push(a);
            }
            pop();
            sqlite3_finalize(stm);
            sqlite3_close(db);
            cout<<"\n\n\t\t";
            system ("PAUSE");
            }
    }
}
void KIMHOUNG_main(){
    int again1, choice;
    do{
    system("CLS");
    cout<<"\t\t\t||WELCOME TO CLOTH ADMIN MENU||";
    cout<<"\n\n[1]. ADD PRODUCTS";
    cout<<"\n[2]. MODIFY PRODUCTS";
    cout<<"\n[3]. SEARCH PRODUCTS";
    cout<<"\n[4]. DELETE PRODUCTS";
    cout<<"\n[5]. SHOW ALL PRODUCTS";
    cout<<"\n[6]. RESTOCK";
    cout<<"\n[7]. EXIT";
    cout<<"\n\n\t\t YOUR CHOICE : [ ]\b\b";
    cin>>choice;
    switch(choice){
        case 1:
            AddMenu();
            break;
        case 2:
            ModifyMenu();
            break;
        case 3:
            SearchMenu();
            break;

        case 4:
            DeleteMenu();
            break;
        case 5:{
            system("CLS");
            cout<<"\n\t\t||WELCOME TO CLOTHES DISPLAY MENU||\n\n";
            DisplayProduct();
            cout<<"\n\t\tTHE END OF THE RECORD...\n";
            }
            break;
        case 6:
            system("CLS");
            int ID;
            int Restock;
            cout<<"\n\t\t||WELCOME TO RESTOCK MENU||\n\n";
            DisplayProduct();
            cout<<"\n\nENTER ID OF PRODUCT TO RESTOCK : ";
            cin>>ID;
            cout<<"\nENTER AMOUNT OF RESTOCK : ";
            cin>>Restock;
            cout<<"\n";
            restockCloth(Restock, ID);
            cout<<"\n\n";
            DisplayProduct();
            break;
        case 7:
            cout<<"\n\n\t\tTHANK YOU FOR USING OUR PROGRAM....";
            exit(0);
        default :
            cout<<"\n\n\t\tYOU HAVE ENTER WRONG CHOICE...";
        }
    }while(choice != 7);
    cout<<"\n\n\t\tTHANK YOU FOR USING OUR PROGRAM....(=* ~ *=) \n\n";
}

