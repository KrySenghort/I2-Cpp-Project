#include<iostream>
#include<istream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <dos.h>
#include "sqlite3.h"
using namespace std;
sqlite3 *db;
sqlite3_stmt *stmt;
int result,age;
string query, name, email, gender;
//use sqlite
//Kimleng Hong
void connection();
void insertd();
void deleted();
void updated();
void retrieve();
void retrieveOrderByName();
void retrieveByAge();
void students();
void teachers();
void createInsertTeacher();
void insertteacher();
void ShowTeacher();
void UpdateTeacher();
void DeleteTeacher();
void library();
void insertBook();
void addHistory();
void displayH();
void searchhistory();
void updatehistory();
void deletehistory();
//void revealb(struct bookh);
void addMaths();
void addLanguage();
void showMenuLibrary();
void showBook();
void updateBook();
void searchBook();
void deleteBook();
void LogIn();
void login();
void forgot();
void registr();
void ContactSchool();
void Loading();
int ch;
int found=0;
int ch1, total = 0;
int addhistory;
struct Book{
    int id;
    string nameh;
    int year;
}b[100];
struct node{
    string lastName;
    char genderm;
    int phoneNumber;
    int studentID;
    node *left , *right;
};
node *root = NULL;
int ID , choice2 ,phNUM , srchNUM;
string fname , lname ;
char genderm;
node *AddStudentInfo(node *root , int studentID , string lname ,char genderm , int phoneNumber);
void displayIn0rder(node *root);
void searchStudent(node *root , int ID);
fstream input;
class Node{
public:
        int roll_no;
        string name;
        float marks,per;
        Node *next_add;
};
// Hok kimleang
class Linked_List{
    public:
        Node *head = NULL;
        void Insert(){
            fstream insertcontact;
            insertcontact.open("Insertcontact.txt", ios::app | ios::out);
            int r;
            string n;
            float m;
            cout<<"\n\t>> Enter ID   : ";
            cin>>r;
            cout<<"\t>> Enter Name : ";
            getline(cin, n);
            getline(cin, n);
            cout<<"\t>> Enter Phone: ";
            cin>>m;
            Node *new_node = new Node;
            new_node -> roll_no = r;
            new_node -> name = n;
            new_node-> marks = m;
            new_node -> next_add = NULL;
            insertcontact<<"\n\t\tID"<<setw(20)<<"\tNAME"<<setw(20)<<"PHONE";
            insertcontact<<"\n\t\t"<< new_node -> roll_no<<"\t"<<setw(20)<<new_node -> name<<setw(20)<<new_node-> marks;
            insertcontact.close();
            if(head == NULL){
                head = new_node;
            }
            else{
                Node *ptr = head;
                while(ptr -> next_add != NULL){
                    ptr =ptr -> next_add;
                }
                ptr -> next_add = new_node;
            }
            cout<<"\n\t\t Inserted Successfully..."<<endl;
        }
        void Search(){
            if(head == NULL){
                cout<<"\n\n Linked List is Empty...";
            }
            else{
                int r;
                cout<<"\n\n\t >>> Enter ID For Updation : ";
                cin>>r;
                Node *ptr =head;
                while(ptr != NULL){
                    if(r == ptr -> roll_no){
                        cout<<"\n\t>>===================<<";
                        cout<<"\n\t>>   DATA IS FOUND   <<";
                        cout<<"\n\t>>===================<<";
                        cout<<"\n\t  ID   : "<<ptr -> roll_no;
                        cout<<"\n\t  Name : "<<ptr ->name;
                        cout<<"\n\t  Phone: "<<ptr -> marks;
                        cout<<"\n\t>>===================<<";

                        found++;

                    }
                    ptr = ptr -> next_add;

                }
                if(found == 0)
                {
                    cout<<"\n\n Search ID No."<<r<< "Can't Found...";
                }


            }
        }
        void count()
        {
            if(head == NULL)
            {
                cout<<"\n\n Linked List is Empty...";
            }
            else
            {
                int c=0;
                Node *ptr = head;
                while(ptr != NULL)
                {
                    c++;
                    ptr = ptr -> next_add;
                }
                cout<<"\n\t\t ====================";
                cout<<"\n\t\t >>Total members : "<<c;
                cout<<"\n\t\t ===================="<<endl;
            }
        }
        void Update(){
            if(head == NULL){
                cout<<"\n\n Linked List is Empty...";
            }
            else{
                int r;
                cout<<"\n\n Enter ID For Updation : ";
                cin>>r;
                Node *ptr =head;
                while(ptr != NULL){
                    if(r == ptr -> roll_no){
                         cout<<"\nEnter New ID No. : ";
                         cin>>ptr -> roll_no;
                         cout<<"Enter Name  : ";
                         fflush(stdin);
                         getline(cin,ptr -> name);
                         cout<<"Enter Phone : ";
                         cin>>ptr -> marks;
                         cout<<"\n\n\n Record Updated Successfully...";
                         found++;
                    }
                    ptr = ptr -> next_add;
                }
                if(found == 0){
                    cout<<"\n\n Update ID No."<<r<< "Can't Found...";
                }
            }
        }
         void Del(){
            if(head == NULL){
                cout<<"\n\n Linked List is Empty...";
            }
            else{
                int r, found=0;
                cout<<"\n\n Enter ID No. For Deleltion : ";
                cin>>r;
                if(r == head -> roll_no){
                    Node *ptr =head;
                    head =head -> next_add;
                    cout<<"\n\n Record Deleted Successfully...";
                    found++;
                    delete ptr;
                }
                else{
                    Node *pre =head;
                    Node *ptr = head -> next_add;
                    while(ptr != NULL){
                        if(r = ptr -> roll_no){
                            pre -> next_add =ptr -> next_add;
                            cout<<"\n\n Record Deleted Successfully...";
                            found++;
                            delete ptr;
                            break;
                        }
                        pre =ptr;
                        ptr = ptr -> next_add;
                    }
                }
                if(found == 0){
                    cout<<"\n\n\t >>> Delete ID "<<r<< "Can't Found...";
                }
            }
        }
        void Show(){
            if(head == NULL)
            {
                cout<<"\n\n Linked List is Empty...";
            }
            else
            {
                cout<<"\n\t\t================================================";
                cout<<"\n\t\t>>>         WELCOME TO CONTACT TABLE         <<<";
                cout<<"\n\t\t------------------------------------------------";
                cout<<"\n\t\tID"<<setw(20)<<"NAME"<<setw(20)<<"PHONE";
                Node *ptr =head;
                while(ptr != NULL)
                {
                    cout<<"\n\t\t"<<ptr -> roll_no<<setw(20)<<ptr ->name<<setw(20)<<ptr -> marks;
                    ptr = ptr -> next_add;

                }
                cout<<"\n\t\t================================================";
            }
        }
};
// the end for hok kinleang

// hong kimleang
int main()
{

    sqlite3_open("demo.db",&db);
    connection();
    Loading();
    system("cls");
    cout<<"\t==================================================="<<endl;
    cout<<"\t======WELCOME TO UNIVERSITY MANAGEMENT SYSTEM======"<<endl;
    cout<<"\t---------------------------------------------------"<<endl;
    cout<<"\t\t1. Students management system"<<endl<<"\t\t2. Library management system"<<endl<<"\t\t3. Teacher management system"<<endl;
    cout<<"\t\t4. Contact information\n\t\t5. Exit";
    cout<<"\n\t==================================================="<<endl;
    cout<<"\n\t>>>ENTER YOUR CHOICE: ";
    cin>>ch;
    if(ch>=1 && ch<5)
        LogIn();
    else if(ch==5){
        Loading();
        cout<<"\n\t\tThanks for using this program\n\t\tThis program is created by CFG Group\n\n";
    }else{
        system("cls");
        cout<<"\n\t\t==============================";
        cout<<"\n\t\t\tInvalid choice!\n";
        main();
    }
    sqlite3_close(db);
    return 0;
}
void connection(){
    if(sqlite3_open("demo7.db", &db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS user(name VARCHAR(80) ,gender VARCHAR(10), age INT, email VARCHAR(80));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(result != SQLITE_OK){
            cout<<"\nError: "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<endl;
        }
    }
}
void insertd(){
    cout<<"\n\t\t===============================";
    cout<<"\n\t\tstudent's name  : ";
    getline(cin, name);
    getline(cin, name);
    cout<<"\t\tstudent's gender: ";
    cin>>gender;
    cout<<"\t\tstudent's age   : ";
    cin>>age;
    getchar();
    cout<<"\t\tstudent's email: ";
    getline(cin, email);
    query = "INSERT INTO user(name,gender, age, email) VALUES(?, ?,?,?);";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, gender.c_str(), gender.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_text(stmt, 4, email.c_str(), email.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if(result != SQLITE_OK){
        cout<<"Error : "<<sqlite3_errmsg(db)<<endl;
    }
    else{
        cout<<"\n\n\t\t>>>>>>Data inserted\n\n";
    }
}
void retrieve(){
    query = "SELECT rowid,*FROM user";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<"\nError : "<<sqlite3_errmsg(db)<<endl;
    }
    else{
         cout<<"\n\t=================================================================================";
        cout<<"\n"<<left<<"\t"<<setw(15)<<"ID"
            <<setw(15)<<"Name"<<setw(15)<<"Gender"<<setw(15)<<"Age"<<setw(15)<<"Email";
        cout<<"\n\t=================================================================================\n"<<endl;
        while(result = sqlite3_step(stmt) == SQLITE_ROW){
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<<setw(15)<<sqlite3_column_text(stmt, 1)<<setw(15)<<sqlite3_column_text(stmt, 2)<<setw(15)<<sqlite3_column_text(stmt, 3)
            <<setw(15)<<sqlite3_column_text(stmt, 4)<<endl;
        }
        cout<<"\n\t=================================================================================\n"<<endl;
    }
}
void retrieveOrderByName(){
    query = "SELECT rowid,*FROM user ORDER BY name DESC";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){

        cout<<"\nError : "<<sqlite3_errmsg(db)<<endl;
    }
    else{
         cout<<"\n\t=================================================================================";
        cout<<"\n"<<left<<"\t"<<setw(15)<<"ID"
            <<setw(15)<<"Name"<<setw(15)<<"Gender"<<setw(15)<<"Age"<<setw(15)<<"Email";
        cout<<"\n\t=================================================================================\n"<<endl;
        while(result = sqlite3_step(stmt) == SQLITE_ROW){
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<<setw(15)<<sqlite3_column_text(stmt, 1)<<setw(15)<<sqlite3_column_text(stmt, 2)<<setw(15)<<sqlite3_column_text(stmt, 3)
            <<setw(15)<<sqlite3_column_text(stmt, 4)<<endl;
        }
        cout<<"\n\t=================================================================================\n"<<endl;
    }
}
void retrieveByAge(){
    query = "SELECT rowid,*FROM user ORDER BY age";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){

        cout<<"\nError : "<<sqlite3_errmsg(db)<<endl;
    }else{
         cout<<"\n\t=================================================================================";
        cout<<"\n"<<left<<"\t"<<setw(15)<<"ID"
            <<setw(15)<<"Name"<<setw(15)<<"Gender"<<setw(15)<<"Age"<<setw(15)<<"Email";
        cout<<"\n\t=================================================================================\n"<<endl;
        while(result = sqlite3_step(stmt) == SQLITE_ROW){
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<<setw(15)<<sqlite3_column_text(stmt, 1)<<setw(15)<<sqlite3_column_text(stmt, 2)<<setw(15)<<sqlite3_column_text(stmt, 3)
            <<setw(15)<<sqlite3_column_text(stmt, 4)<<endl;

        }
        cout<<"\n\t=================================================================================\n"<<endl;
    }
}
void deleted(){
    int id;
    cout<<"\n\t\t>=====================<";
    cout<<"\n\t\tEnter ID to delete: ";
    cin>>id;
    getchar();
    query = "DELETE FROM user WHERE rowid = ?";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if( result == SQLITE_OK){
        cout<<"\n\t\t>>>Data deleted successfully"<<endl<<endl;
    }else{
        cout<<"\n\t\tfail delete?"<<sqlite3_errmsg(db)<<endl;
    }
}
void updated(){
    int id;
    cout<<"\n ENTER ID TO UPDATE: "; cin>>id;
    getchar();
    cout<<"ENTER NEW NAME: ";
    getline(cin, name);
    cout<<"ENTER NEW GENDER: ";
    cin>>gender;
    cout<<"ENTER NEW AGE: ";
    cin>>age;
    getchar();
    cout<<"ENTER NEW EMAIL: ";
    getline(cin, email);

    query = "UPDATE user SET name = ?, gender =?, age = ?, email= ? WHERE rowid = ?;";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, gender.c_str(), gender.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_text(stmt, 4, email.c_str(), email.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result == SQLITE_OK){
        cout<<"\nUpdated successfully"<<endl;
    }else{

        cout<<"\nFailed: "<<sqlite3_errmsg(db)<<endl;
    }

}
// the end for Hong kimleng

//Ngeav bonat
void LogIn(){
    lo1:
    int choice;
        cout<<"\n\t\t**********************************************************************\n";
        cout<<"\t\t                      Welcome to login page                               ";
        cout<<"\n\t\t*******************        MENU        *******************************";
        cout<<"\n\t\t > 1.LOGIN"<<endl;
        cout<<"\t\t > 2.REGISTER"<<endl;
        cout<<"\t\t > 3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"\t\t > 4.Exit to menu"<<endl;
        cout<<"\t\t**********************************************************************";
        cout<<"\n\t\t >> Enter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                login();
                break;
            case 2:
                registr();
                break;
            case 3:
                forgot();
                break;
            case 4:
                main();
                break;
            default:
                system("cls");
                cout<<"You've made a mistake , give it a try again\n"<<endl;
                goto lo1;
        }

}

void login()
{
    int count;
    string user,pass,u,p;
    system("cls");
    cout<<"\n\t\t====================================";
    cout<<"\n\t\t please enter the following details"<<endl;
    cout<<"\t\t >> USERNAME :";
    cin>>user;
    cout<<"\t\t >> PASSWORD :";
    cin>>pass;
    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
        cin.get();
        cin.get();
        if(ch==1)
            students();
        else if(ch==2)
            library();
        else if(ch==3)
            teachers();
        else if(ch==4){
            ContactSchool();
        }
        else{
           cout<<"\nInvalid choice"<<endl;
           main();
        }
    }
    else
    {
        cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        LogIn();
    }
}
void registr(){
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        LogIn();
}
void forgot(){
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch){
                case 1:{
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
void Loading(){
    cout<<"\n\n";
    cout << "\n\n\n\t\t\t\t\t|  Loading data  |\n\t\t\t\t\t";
    for (int a = 1; a < 10; a++)
    {
        Sleep(500);
        cout << "**";
    }
    cout << "\n\n\t\tAccess Aborted...\n\n";
}
//the end for ng bonat
// hong kimleng
void students(){
    int stch;
    Loading();
    t1:
    cout<<"\t\t**********************************************************\n";
    cout<<"\t\t===========WELCOME TO STUDENT MANAGEMENT SYSTEM==========="<<endl;
    cout<<"";
    cout<<"\n\t\t*****************        MENU    *************************\n";
    cout<<"\t\t\t>>>>  1.Insert info"<<endl;
    cout<<"\n\t\t\t>>>>  2.Show info"<<endl;
    cout<<"\n\t\t\t>>>>  3.Update info"<<endl;
    cout<<"\n\t\t\t>>>>  4.Delete info"<<endl;
    cout<<"\n\t\t\t>>>>  5.Exit to menu"<<endl;
    cout<<"\n\t\t---------------------------------------------------------";
    cout<<"\n\t\t========================================================="<<endl;
    cout<<"\n\t\t>>>Enter your choice :";
    cin>>stch;
    switch(stch){
        case 1:{
            insertd();
            break;
        }
        case 2:{
            retrieve();
            break;
        }
        case 3:{
            updated();
            break;
        }
        case 4:{
            deleted();
            break;
        }
        case 5:
            main();
            break;
        default:
            cout<<"\nInvalid choice!\nPlease try again!\n";
            break;
    }
    goto t1;
}
// the end for hong kimleng
int count = 0;
//for Meach seaklav
void teachers(){
        cout<<"\n\t===========================================";
        cout<<"\n\t   WELCOME TO TEACHERS SYSTEM MANAGEMENT";
        cout<<"\n\t===========================================";
        cout<<"\n\t    1]. Insert teacher's info";
        cout<<"\n\t    2]. Show info of teachers";
        cout<<"\n\t    3]. Search data in the list";
        cout<<"\n\t    4]. Update data in the list";
        cout<<"\n\t    5]. Exit to menu";
        cout<<"\n\t===========================================";
        cout<<"\n>>>>ENTER YOUR CHOICE: ";
        cin >> choice2;
        switch(choice2){
            case 1:{
                cout<<"\n=======>>ENTER INFORMATIONS OF TEACHERS<<=======\n";
                cout<<"\n\t\t\t\t>=====================<";
                cout << "\n\t\t\t\t==>Teacher "<<endl;
                cout << "\t\t\t\tEnter the ID : ";
                cin >> ID;
                cout << "\t\t\t\tEnter name   : ";
                cin >> lname;
                cout << "\t\t\t\tEnter gender : ";
                cin >> genderm;
                cout << "\t\t\t\tEnter phone  : ";
                cin >> phNUM;
                root = AddStudentInfo(root , ID , lname ,genderm , phNUM);
                break;
            }
            case 2:
                displayIn0rder(root);
                break;
            case 3:
                cout << "\nEnter Teacher's ID : ";
                cin >> srchNUM;
                searchStudent(root , srchNUM);
                break;
            case 4:
                exit(0);
                break;
            case 5:
                main();
                break;
            default:
                cout<<"\n\t\t\t\t>> Invalid choice!..."<<endl;
        }
        teachers();
}
node *AddStudentInfo(node *root , int studentID , string lname , char genderm , int phoneNumber){
    input.open("inputstudent.txt", ios::app);
    if (root == NULL){
        root = new node;
        root -> studentID = studentID;
        root -> lastName = lname;
        root  -> genderm = genderm;
        root -> phoneNumber = phoneNumber;
        root -> left = root -> right = nullptr;
        input<<"\nStudent's ID\t: "<<root -> studentID<<"\n"<<"Student's name\t: "<<root -> lastName<<"\n"<<"Student's gender: "<<root  -> genderm<<"\n"<<"Student's phone\t: "<<root -> phoneNumber<<endl<<endl;
        return root;
    }
    else
    {
        if (studentID < root -> studentID)
        {
            root -> left = AddStudentInfo(root -> left , studentID , lname , genderm, phoneNumber);
        }
        else if (studentID > root -> studentID)
        {
            root -> right = AddStudentInfo(root -> right , studentID , lname , genderm , phoneNumber);
        }
    }
    input.close();
    return root;
}

// eab pisey
void displayIn0rder(node *root)
{
    fstream file, dis;
	file.open("inputstudent.txt",ios::in);
	dis.open("displaystudent.txt",ios::in);
	if(file.is_open()){
		string line;
		while(getline(file, line)){
			cout<< line <<endl;
		}
		file.close();
	}
   /* if (root == nullptr)
    {
        return ;
    }
    else{
        displayIn0rder(root -> left);
        cout << "\nTeacher's ID     : " << root -> studentID;
        cout << "\nTeacher's name   : " << root -> lastName;
        cout << "\nTeacher's gender : " << root -> genderm;
        cout << "\nTeacher's phone  : \n" << root -> phoneNumber;
        displayIn0rder(root -> right);
    }*/
}
void searchStudent(node *root , int ID)
{
    int Count;
    fstream file1;
	file1.open("inputstudent.txt",ios::in);
    if (root -> studentID > ID)
    {
        searchStudent(root -> left , ID);
    }
    else if (root -> studentID < ID)
    {
        searchStudent(root -> right , ID);
    }
    else
    {
        cout << "\n\t\tTeacher's ID     : " << root -> studentID;
        cout << "\n\t\tTeacher's name   : " << root -> lastName;
        cout << "\n\t\tTeacher's gender : " << root -> genderm;
        cout << "\n\t\tTeacher's phone  : " << root -> phoneNumber;
	}
        file1.close();
        cout << "\n\t\tTeacher's ID     : " << root -> studentID;
        cout << "\n\t\tTeacher's name   : " << root -> lastName;
        cout << "\n\t\tTeacher's gender : " << root -> genderm;
        cout << "\n\t\tTeacher's phone  : " << root -> phoneNumber;
    file1.close();
}


void createInsertTeacher(){
/*int PHteacher, IDteacher;
    string NAteacher;
    char Geteacher;
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<">> Name   : ";
    getline(cin, NAteacher);
    getline(cin, NAteacher);
    cout<<">> Gender : ";
    cin>>Geteacher;
    cout<<">> ID     : ";
    cin>>IDteacher;
    cout<<">> Phone  : ";
    cin>>PHteacher;
    temp->nameteacher = NAteacher;
    temp->genderteacher = Geteacher;
    temp->idteacher = IDteacher;
    temp->phoneteacher = PHteacher;
    temp->next = NULL;
    temp->pre = NULL;
    count++;*/
}
void insertteacher(){
    /*
    cout<<"\n\t\t\t\t>=====================<";
    cout << "\n\t\t\t\t==>Teacher "<<endl;
    cout << "\t\t\t\tEnter the ID : ";
    cin >> ID;
    cout << "\t\t\t\tEnter name   : ";
    cin >> lname;
    cout << "\t\t\t\tEnter gender : ";
    cin >> gender;
    cout << "\t\t\t\tEnter phone  : ";
    cin >> phNUM;
    root = AddStudentInfo(root , ID , lname ,gender , phNUM);
    */
}

void ShowTeacher(){
    /*struct node *temp1;
    temp1 = root;
    if(temp1 == NULL){
        cout<<"\nList is empty"<<endl;
    }
    while(temp1 !=NULL){
        cout<<"Name : "<<temp1->nameteacher<<endl<<"Gender : "<<temp1->genderteacher<<endl<<"ID : "<<temp1->genderteacher<<endl<<"Phone : "<<temp1->phoneteacher<<endl<<endl;
        temp1 = temp1->next;
    }
*/
}
void UpdateTeacher(){
}
void DeleteTeacher(){
}




/*void revealb(struct bookh b1[]){
    cout<<"\n\t\t\t\t ID   : "<<b1.id;
    cout<<"\n\t\t\t\t Name : "<<b1.nameh;
    cout<<"\n\t\t\t\t Year : "<<b1.year<<endl;
}*/
// eab pisey
void library(){
    int c,j;
    cout<<"\n\t\t\t\t>>=========================<<";
    cout<<"\n\t\t\t\t]>   GATEGORIES OF BOOKS   [<";
    cout<<"\n\t\t\t\t>>=========================<<";
    cout<<"\n\t\t\t\t]>    1**  HISTORY  **     <[";
    cout<<"\n\t\t\t\t]>    2**  MATHS    **     <[";
    cout<<"\n\t\t\t\t]>    3**  LANGUADE **     <[";
    cout<<"\n\t\t\t\t]>    4**  EXIT MENU**     <[";
    cout<<"\n\t\t\t\t>>-------------------------<<";
    cout<<"\n\t\t\t\t=============================";
    cout<<"\n\t\t\t\t>> Enter Your Choice: "; // Taking the action input
    cin >> c;
    switch(c){
        case 1:{
            w:
            showMenuLibrary();
            cout<<"\n\t\t\t\t>> Enter your choice : ";
            cin>>ch1;
            if(ch1 == 1){
                addHistory();
            }else if(ch1 == 2){
                 displayH();
            }else if(ch1 == 3){

            }else if(ch1 == 4){
                 searchhistory();
            }else if(ch1 == 5){
                // deletehistory();
            }else if(ch1 == 6){
                library();
            }
            goto w;
            break;
        }
        case 2:{
            addMaths();
            //showBook();
            break;
        }
        case 3:{
            addLanguage();
           // updateBook();
            break;

        }
        case 4:{
            main();
            //searchBook();
            break;
        }
        default:{
            cout<<"\n\t\t\t\t >> Invalid choice!....Please try again!..."<<endl;
            library();
        }
    }
}
void showMenuLibrary(){

    cout << "\n\t\t\t\t\t-----------------------------------" << endl;
    cout << "\t\t\t\t\t>>   LIBRARY MANAGEMENT SYSTEM   <<" << endl;
    cout << "\t\t\t\t\t-----------------------------------" << endl;
    cout << "\t\t\t\t\t 1. Add New Books " << endl;
    cout << "\t\t\t\t\t 2. Display Type Books" << endl;
    cout << "\t\t\t\t\t 3. Update Data" << endl;
    cout << "\t\t\t\t\t 4. Search Book" << endl;
    cout << "\t\t\t\t\t 5. Delete Book" << endl;
    cout << "\t\t\t\t\t 6. Exit" << endl;
    cout << "\t\t\t\t\t..................................." << endl;
    cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
    cout << "\t\t\t\t\t..................................." << endl;
}
// the end for ngeav bonat
/*if(ch1 > 6){
        cout<<"\n\t\t\t\t Invalid choice!...Please try again!";
        getch();
        goto w;
    }
}*/
       // showMenuLibrary();





void addHistory(){
    cout<<"\n\t\t\t\t How many book for addition?: ";
    cin>>addhistory;
    cout<<"\n\t\t\t\t>******************************<";
    cout<<"\n\t\t\t\t>   WELCOME TO HISTORY STORE   <";
    cout<<"\n\t\t\t\t>==============================<";
    for(int j=total; j<addhistory+total; j++){
        cout<<"\n\t\t\t\tEnter ID   : ";
        cin>>b[j].id;
        cout<<"\t\t\t\tEnter Name : ";
        fflush(stdin);
        getline(cin, b[j].nameh);
        cout<<"\t\t\t\tEnter Year : ";
        cin>>b[j].year;
        cout<<"\n\t\t\t\t>==============================<"<<endl;
    }
    total = total + addhistory;
   // revealb(b);
   // cout<<"\n\t\t\t\t Add another?(1/0): ";
  //  cin>>w;
   // if(w == 1){
        //addHistory();
    //revealb(b);
   // }
    //displayH();
}
void displayH(){
    if(total != 0){
        cout<<"\n\t\t\t\t>======================<";
        cout<<"\n\t\t\t\t  INFORMATION OF STORE";
        cout<<"\n\t\t\t\t>======================<";
        for(int i=0; i< total; i++){
            cout<<"\n\t\t\t\t ID   : "<<b[i].id;
            cout<<"\n\t\t\t\t Name : "<<b[i].nameh;
            cout<<"\n\t\t\t\t Year : "<<b[i].year;
            cout<<"\n\t\t\t\t>======================<\n";
        }
    }
    else{
        cout<<"\n\t\t\t\t >>> List is empty!..."<<endl;
    }
}

void updatehistory(){
    int idss;
    if(total != 0){
        cout<<"\n\t\t\t\t>======================<\n";
        cout<<"\n\t\t\t\t Enter id to update: ";
        cin>>idss;
        cout<<"\n\t\t\t\t>======================<\n";
        for(int l=0; l<total; l++){
            if(idss == b[l].id){
                cout<<"\n\t\t\t\t ID   : "<<b[l].id;
                cout<<"\n\t\t\t\t Name : "<<b[l].nameh;
                cout<<"\n\t\t\t\t Year : "<<b[l].year;
                cout<<"\n\t\t\t\t>======================<\n";
                cout<<"\n\t\t\t\t Enter new data!....";
                cout<<"\n\t\t\t\t ID   : "<<b[l].id;
                cout<<"\n\t\t\t\t Name : "<<b[l].nameh;
                cout<<"\n\t\t\t\t Year : "<<b[l].year;
                //cout<<"\n\t\t\t\t>======================<\n";
                break;
            }else if(l == total-1){
                cout<<"\n\t\t\t\t Can not found!...."<<endl;
            }
            cout<<"\n\t\t\t\t>======================<\n";
        }
    }else{
        cout<<"\n\t\t\t\t List is empty!..."<<endl;
    }

}
void searchhistory(){
    if(total != 0){
        int ids;
        cout<<"\n\t\t\t\t>======================<\n";
        cout<<"\n\t\t\t\t Enter ID to search: ";
        cin>>ids;
        cout<<"\n\t\t\t\t>======================<";
        cout<<"\n\t\t\t\t  INFORMATION OF STORE";
        cout<<"\n\t\t\t\t>======================<\n";
        for(int l=0; l<total; l++){
            if(ids == b[l].id){
                cout<<"\n\t\t\t\t ID   : "<<b[l].id;
                cout<<"\n\t\t\t\t Name : "<<b[l].nameh;
                cout<<"\n\t\t\t\t Year : "<<b[l].year;
                break;
            }else if(l == total-1){
                cout<<"\n\t\t\t\t Can not found!...."<<endl;

            }
            cout<<"\n\t\t\t\t>======================<\n";
        }
    }
    else {
        cout<<"\n\t\t\t\t List is empty!..."<<endl;
    }
}
void deletehistory(){
   /* int hh, b;
    int dd;
    if(total != 0){
        cout<<"\n\t\t\t\t>===========================<\n";
        cout<<"\n\t\t\t\t 1. Delete all History books";
        cout<<"\n\t\t\t\t 2. Delete with id";
        cout<<"\n\t\t\t\t>===========================<\n";
        cout<<"\n\t\t\t\t>> Enter a number : ";
        cin>>hh;
        if(hh == 1){
            total = 0;
            cout<<"\n\t\t\t\t Data this block is deleted!...."<<endl;
        }else if(hh == 2){
            cout<<"\n\t\t\t\t Enter id to delete: ";
            cin>>dd;
            for(int i=0; i<total; i++){
                if(dd == b[i].id){
                    for(int b=i; b<total; b++){
                        b[b].nameh = b[b+1].nameh;
                        b[b].year = b[b+1].year;
                        total--;
                        break;
                    }
                }if(i == total-1){
                    cout<<"\n\t\t\t\t Not found!..."<<endl;
                }
            }
        }

    }else{
        cout<<"\n\t\t\t\t List is empty!..."<<endl;
    }
*/
}
void addMaths(){}
void addLanguage(){
}
void showBook(){
}
void updateBook(){}
void searchBook(){}
void deleteBook(){
}
// for den sokunpidur
void ContactSchool(){
    Linked_List obj;
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t>===========================<";
    cout<<"\n\t\t|      CONTACT TABLE        |";
    cout<<"\n\t\t>>=========================<<";
    cout<<"\n\t\t|| 1 >> Insert contact     ||";
    cout<<"\n\t\t|| 2 >> Search contact     ||";
    cout<<"\n\t\t|| 3 >> Count members      ||";
    cout<<"\n\t\t|| 4 >> Update contact     ||";
    cout<<"\n\t\t|| 5 >> Delete contact     ||";
    cout<<"\n\t\t|| 6 >> Show All contact   ||";
    cout<<"\n\t\t|| 7 >> Exit               ||";
    cout<<"\n\t\t>>=========================<<";
    cout<<"\n\n\t\t>> Your Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        int chh, k;
        cout<<"\n\t>=======================<";
        cout<<"\n\t Enter number to add: "; cin>>chh;
        cout<<"\n\t>>>>========================<<<<";
        cout<<"\n\t    WELCOME TO CONTACT CHART";
        for(k=0; k<chh; k++){
            cout<<"\n\t================================"<<endl;
            cout<<"\t\t >>>> "<<k+1<<" contact "<<endl;
            cout<<"\t================================"<<endl;
            obj.Insert();
        }
        break;
    case 2:
        system("cls");
        obj.Search();
        break;
    case 3:
        system("cls");
        obj.count();
        break;
    case 4:
        system("cls");
        obj.Update();
        break;
    case 5:
        system("cls");
        obj.Del();
        break;
    case 6:
        system("cls");
        obj.Show();
        break;
    case 7:
        main();
        exit(0);
    default:
        cout<<"\n\n\n Invalid choice...please Try Again...";
    }
    getch();
    goto p;
}
//the end for him


