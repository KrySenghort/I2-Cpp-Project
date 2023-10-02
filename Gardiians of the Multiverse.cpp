#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sqlite3.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
//dashboard functions
//void admin();
void receptionist();
void customer();
void register1();
void signUp();
//booking part
void view_booking();
void update_booking_detail();
void delete_booking();
//sqlite declaration
sqlite3 *db;
sqlite3_stmt * stmt;
int compare(char username[20],char password[20]);
//queue implementation for finding available room
struct element{
    int data_out;
    int room_num;
    element *next;
};
struct Queue{
    int n;
    element *Rear;
    element *Front;
};
Queue *CreatAnEmptyQueue(){
    Queue *q;
    q = new Queue;
    q->n = 0;
    q->Front = NULL;
    q->Rear = NULL;
    return q;
}
void enqueue(Queue *q,int data,int room){
    element *e;
    e = new element;
    e->data_out = data;
    e->room_num = room;
    e->next = NULL;
    if ( q->n==0 ){
        q->Front = e;
        q->Rear = e;
        q->n = q->n + 1;
    } else {
        q->Rear->next = e;
        q->Rear = e;
        q->n = q->n + 1;
    }
}
//function to sort data from the biggest to smallest
void sorting(Queue *l6) {
    element *tmd, *index;
    tmd = l6->Front;
    index = NULL;
    int temp;
    while (tmd != NULL) {
        index = tmd->next;
        while (index != NULL) {
            if (tmd->data_out < index->data_out) {
                temp = tmd->data_out;
                tmd->data_out = index->data_out;
                index->data_out = temp;
            }
            index = index->next;
        }
        tmd = tmd->next;
    }
}
void dequeue( Queue *q){
    if ( q->n==0 ){
        cout<<" Data underflow ";
    } else {
        element *t;
        t = q->Front;
        q->Front = q->Front->next;
        delete t;
        q->n = q->n -1;
    }
}
void display(Queue *q){
    element *t;
    t = q->Front;
    while ( t!=NULL ){
        cout <<setw(5)<<"Room: "<<t->room_num <<endl;
        t = t->next;
    }
    cout<<"\n";
}
//function to pop up room
 void search1( Queue *l,  int corrent_date ){
    element *e;
    e = l->Front;
    while ( e!=NULL ){
        if ( corrent_date < e->data_out ){
            dequeue(l);
        }
        e = e->next;
    }
}
//function to find available room
void search_room();
//function for reservation
void bookAroom();
//linked list implementation for searching guest present
struct element1{
    int id;
    string name,address,contactNum,gender,nationality;
    element1 *next;
};
struct list{
    int n;
    element1 *head;
    element1 *tail;
};
list *creatAnEmptyList(){
    list *li;
    li = new list;
    li->n = 0;
    li->tail = NULL;
    li->head = NULL;
    return li;
}
void addToBeingOfList(list *ls, int guest_id, string name, string address1, string contact , string gender , string nation){
    element1 *e;
    e = new element1;
    e->id = guest_id;
    e->name = name;
    e->address = address1;
    e->contactNum = contact;
    e->gender = gender;
    e->nationality = nation;
    if (ls->n == 0) {
        ls->head = e;
        ls->tail = e;
        e->next = NULL;
    } else {
        e->next = ls->head;
        ls->head = e;
    }
    ls->n = ls->n + 1;
}
void searchGuestInList( list* l,string name ){
    int found=0;
    element1 *t;
    t = l->head;
    while ( t!=NULL ){
        if ( t->name==name ){
            found = 1;
            cout<<setw(60)<<"Found!!! "<<endl;
            cout<<setw(60)<<"Here's information of "<<name<<endl;
            cout<<setw(60)<<"GUEST'ID: "<<t->id<<endl;
            cout<<setw(60)<<"GUEST'name: "<<t->name<<endl;
            cout<<setw(60)<<"GUEST'ADDRESS: "<<t->address<<endl;
            cout<<setw(60)<<"GUEST'GEDDER: "<<t->gender<<endl;
            cout<<setw(60)<<"GUEST'NATIONALITY: "<<t->nationality<<endl;
            break;
        }
        t = t->next;
    }
    if (!found){
        cout<<setw(60)<<"Guest not found!!!!"<<endl;
    }

}
void displayList(list *ls){
    element1 *t;
    t = ls->head;
    while (t!=NULL){
        cout<<t->id<<" "<<t->name<<" "<<t->address<<" "<<t->contactNum<<" "<<t->gender<<" "<<t->nationality<<endl;
        t = t->next;
    }
    cout<<endl;
}
void search_guest();
//vathanak
main(){
    int choice;
    cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
    cout<<setw(115)<<"-                              WELCOME TO OUR HOTEL                                -"<<endl;
    cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
    cout<<setw(80)<<"1.Login for admin"<<endl;
    cout<<setw(87)<<"2.Login for receptionist"<<endl;
    cout<<setw(80)<<"3.Customer portal"<<endl;
    cout<<setw(85)<<"Enter your choice: ";
    cin>>choice;
    getchar();
    //if ( choice==1 ){
        //admin();
    //}
     if ( choice==2 ){
        receptionist();
    }else if ( choice==3 ){
        customer();
    }
}
void receptionist(){
    int num,choice1;
    char usernam[20],password[20];
    cout<<setw(80)<<"\nPlease enter your username: ";
    cin.getline(usernam,20);
    cout<<setw(80)<<"\nPlease enter your password: ";
    cin.getline(password,20);
    num = compare(usernam,password);
    if ( num==1 ){
        cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
        cout<<setw(115)<<"-                              WELCOME TO RECEPTIONIST PORTAL                                -"<<endl;
        cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
        cout<<setw(80)<<"<1>.View all booking detail"<<endl;
        cout<<setw(80)<<"<2>.Cencel booking "<<endl;
        cout<<setw(80)<<"<3>.Update booking detail"<<endl;
        cout<<setw(80)<<"<4>.Room booking"<<endl;
        cout<<setw(80)<<"<5>.Search Guest"<<endl;
        cout<<setw(80)<<"<6>.Check room available"<<endl;
        cout<<setw(80)<<"Enter your choice: ";
        cin>>choice1;
        getchar();
            if ( choice1==1 ){
                view_booking();
            } else if ( choice1==2 ) {
                delete_booking();
            } else if ( choice1==3 ){
                update_booking_detail();
            } else if ( choice1==4 ){
                bookAroom();
            } else if ( choice1==5 ){
                search_guest();
            } else if ( choice1==6 ){
                search_room();
            }

    }
    else {
        cout<<setw(80)<<"Sorry something went wrong(:"<<endl;
    }
}
//moi
//function for receptionist login
int compare( char username[20], char password [20]){
    int rc;
    int found =0;
    rc = sqlite3_open("user_info.db", &db);
    //char username[20] = "LOGAN";
    //char password[20]= "LOGAN007";
    char *str = username;
    const char *search_name = str;
    char *ptr = password;
    const char *search_password = ptr;
    string query = "SELECT NAME,PASSWORD FROM INFORMATION";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
         const unsigned char* database_names = sqlite3_column_text(stmt, 0);
         const unsigned char* password = sqlite3_column_text(stmt,1);
         const char *attrName=NULL,*attrpass=NULL;;
         attrName = (const char*) password;
         attrpass = (const char*) database_names;
        if ((strcmp(attrpass, search_name) == 0)&&(strcmp(attrName,search_password)==0)) {
            found = 1;
            break;
        }
    }
    cout<<found;
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return found;
}
//lish
void view_booking(){
    sqlite3_open("booking.db",&db);
    string sql = "SELECT * FROM book";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    cout<<setw(150)<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(115)<<"-                                                                                  BOOKING INFO                                -"<<endl;
    cout<<setw(150)<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(40)<<"BOOKING ID"<<setw(20)<<"ROOM NUMBER"<<setw(20)<<"DATE IN"<<setw(20)<<"DATE OUT"<<setw(20)<<"STATUS"<<endl;
    cout<<setw(150)<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
            int bookingid  = sqlite3_column_int(stmt,0);
            int roomno  = sqlite3_column_int(stmt,1);
            int datein  = sqlite3_column_int(stmt,2);
            int dateout  = sqlite3_column_int(stmt,3);
            const unsigned char* status = sqlite3_column_text(stmt,4);
            cout<<setw(35)<<bookingid<<setw(20)<<roomno<<setw(20)<<datein<<setw(20)<<dateout<<setw(37)<<status<<endl;

    }
    cout<<setw(150)<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
//vathanak
void delete_booking(){
    int id;
    cout<<setw(80)<<"Enter the booking id you want to delete: ";
    cin>>id;
    getchar();
    sqlite3_open("booking.db",&db);
    string query1 = "DELETE FROM book WHERE bookingid =?";
    int result = sqlite3_prepare_v2(db, query1.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt,1,id);
    if ( result==SQLITE_OK ){
        cout<<setw(80)<<"Booking Deleted!!!"<<endl;
    } else {
        cout<<setw(80)<<"failed to delete(:"<<sqlite3_errmsg(db)<<endl;
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
//kimlang
void update_booking_detail(){
    int id1,new_room_num,n_datein,n_dateout;
    string status1;
    cout<<setw(80)<<"Enter the booking id you want to update information: ";
    cin>>id1;
    getchar();
    cout<<setw(80)<<"Enter new room number: ";
    cin>>new_room_num;
    cout<<setw(80)<<"Enter new date of arrival: ";
    cin>>n_datein;
    cout<<setw(80)<<"Enter new date of departure: ";
    cin>>n_dateout;
    getchar();
    cout<<setw(80)<<"Status for notation: ";
    getline(cin,status1);
    sqlite3_open("booking.db",&db);
    string query2 = " UPDATE book SET roomno=?, datein=?,dateout=?,status=? WHERE bookingid=?;";
    int result = sqlite3_prepare_v2(db, query2.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt,5,id1);
    sqlite3_bind_int(stmt,1,new_room_num);
    sqlite3_bind_int(stmt,2,n_datein);
    sqlite3_bind_int(stmt,3,n_dateout);
    sqlite3_bind_text(stmt,4,status1.c_str(),status1.length(),SQLITE_TRANSIENT);
    if ( result==SQLITE_OK ){
        cout<<setw(80)<<"Date updated!!"<<endl;
    } else {
        cout<<setw(80)<<"Failed to update information(: "<<sqlite3_errmsg(db)<<endl;
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
//moi
//function to check available room
void search_room(){
    int day;
    cout<<setw(80)<<"Please enter the current day: ";
    cin>>day;
    Queue *p;
    p = CreatAnEmptyQueue();
    sqlite3_open("booking.db",&db);
    string sql = "SELECT * FROM book";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
     while (sqlite3_step(stmt) == SQLITE_ROW){
        int roomno  = sqlite3_column_int(stmt,1);
        int dateout  = sqlite3_column_int(stmt,3);
        enqueue(p,dateout,roomno);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    sorting(p);
    search1(p,day);
    cout<<"Number of room that available now"<<endl;
    cout<<"=================================="<<endl;
    display(p);
}
//function to collect guest information
//kimlang and lish
void bookAroom(){
        int id;
        int bookid,roomn,datein,dateout1;
        string name,gender,nationalty;
        string address,status,status2;
        string contactno;
        cout<<setw(80)<<"Please enter the booking detail first!!!\n\n";
        cout<<setw(60)<<"Booing ID: ";
        cin>>bookid;
        cout<<setw(60)<<"Enter the room number: ";
        cin>>roomn;
        cout<<setw(60)<<"Enter the date of arrival: ";
        cin>>datein;
        cout<<setw(60)<<"Enter the date departure: ";
        cin>>dateout1;
        getchar();
        cout<<setw(60)<<"Please enter Guest's name: ";
        getline(cin,name);
        cout<<setw(60)<<"Any status: ";
        getline(cin,status2);
        if ( sqlite3_open("booking1.db",&db)==SQLITE_OK ){
            string query = "INSERT INTO book1 (bookingid,guestname,roomn,datein,dateout,status) VALUES (?, ?, ?, ?, ,? ,?);";
            int resule = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
            sqlite3_bind_int(stmt,0,bookid);
            sqlite3_bind_text(stmt,1, name.c_str(), name.length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(stmt,2,datein);
            sqlite3_bind_int(stmt,3,dateout1);
            sqlite3_bind_text(stmt,4,status2.c_str(),status2.length(), SQLITE_TRANSIENT);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            //if ( resule!=SQLITE_OK ){
             //   cout<<setw(60)<<"Failed to complete booking detail!!!"<<sqlite3_errmsg(db)<<endl;
            //}
        }
        cout<<setw(70)<<"Collecting information of the Guest!!\n\n";
        cout<<setw(60)<<"Enter Guest's ID: ";
        cin>>id;
        getchar();
        cout<<setw(60)<<"Enter Guest's address: ";
        getline(cin,address);
        cout<<setw(60)<<"Enter contact number: ";
        getline(cin,contactno);
        cout<<setw(60)<<"Enter Guest's Gender: ";
        getline(cin,gender);
        cout<<setw(60)<<"Enter Guest's Nationality: ";
        getline(cin,nationalty);
        cout<<setw(60)<<"Any special request: ";
        getline(cin,status);
        if (sqlite3_open("customer.db", &db) == SQLITE_OK){
            string sql = "INSERT INTO customer_info (customerid,name, address, contactno, gender, nationalty,status) VALUES (?, ?, ?, ?, ?, ?, ?);";
            int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
            sqlite3_bind_int(stmt,1,id);
            sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 3, address.c_str(),  address.length(),  SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 4, contactno.c_str(), contactno.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 5, gender.c_str(), gender.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 6, nationalty.c_str(), nationalty.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 7, status.c_str(), status.length(), SQLITE_TRANSIENT);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
        if (rc != SQLITE_OK){
            cout<<setw(60)<<endl<<"Failed to save guest information!!! "<<sqlite3_errmsg(db)<<endl;
        } else {
            cout<<setw(60)<<endl<<"Guest information saved!!!"<<endl;
        }
    }
}
void search_guest(){
    string guest_name;
    cout<<setw(60)<<"Enter name of guest you would like to search: ";
    getline(cin,guest_name);
    list *l5;
    l5 = creatAnEmptyList();
    sqlite3_open("customer.db",&db);
    string sql1 = "SELECT * FROM customer_info";
    sqlite3_prepare_v2(db, sql1.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        int id = sqlite3_column_int(stmt,0);
        string name = (const char *) (sqlite3_column_text(stmt,1));
        string address = (const char*) (sqlite3_column_text(stmt,2));
        string contacN = (const char* ) (sqlite3_column_text(stmt,3));
        string gender = (const char* ) (sqlite3_column_text(stmt,4));
        string nationality = (const char* ) (sqlite3_column_text(stmt,5));
        addToBeingOfList(l5,id,name,address,contacN,gender,nationality);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
   searchGuestInList(l5,guest_name);
}
void customer(){
        int c;
        cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
        cout<<setw(115)<<"-                              WELCOME TO RECEPTIONIST PORTAL                                -"<<endl;
        cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
        cout<<setw(115)<<"------------------------------------------------------------------------------------"<<endl;
        cout<<setw(80)<<"<1>.Login with your account"<<endl;
        cout<<setw(80)<<"<2>.Register "<<endl;
        cout<<setw(80)<<"Enter your operation: ";
        cin>>c;
        if ( c==1 ){
            signUp();
        } else if ( c==2 ){
            register1();
        }
}
void register1(){
    string full_name,gmail,gender,password;
    int age;
    cout<<setw(80)<<"\nPLEAS ENTER YOUR INFORMATION!!!\n\n";
    cout<<setw(60)<<"Pleas enter your full name: ";
    getline(cin,full_name);
    cout<<setw(60)<<"Pleas enter your gmail: ";
    getline(cin,gmail);
    cout<<setw(60)<<"Pleas enter your age: ";
    cin>>age;
    getchar();
    cout<<setw(60)<<"Pleas enter your gender: ";
    getline(cin,gender);
    cout<<setw(60)<<"Pleas enter password for next login: ";
    getline(cin,password);
    sqlite3_open("guest_info.db",&db);
    string command1 = "INSERT INTO info (name,gmail,age,gender,password) VALUES (?, ?, ?, ?, ?);";
    int c =sqlite3_prepare_v2(db,command1.c_str(),-1,&stmt,NULL);
        sqlite3_bind_text(stmt, 1, full_name.c_str(), full_name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, gmail.c_str(), gmail.length(), SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt,3,age);
        sqlite3_bind_text(stmt, 4, gender.c_str(), gender.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, password.c_str(), password.length(), SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    if ( c==SQLITE_OK ){
            cout<<setw(60)<<"YOU ARE SUCCESSFULLY SIGN UP YOUR USERNAME IS: "<<full_name<<endl;
        } else {
            cout<<setw(60)<<"SORRY SOMTHING WENT WRONG (: "<<endl;
        }
}
void signUp(){
    int found=0;
    string username,password1;
    cout<<setw(60)<<"ENTER YOUR USERNAM: ";
    getline(cin,username);
    cout<<setw(60)<<"ENTER YOUR PASSWORD: ";
    getline(cin,password1);
    sqlite3_open("guest_info.db",&db);
    string sql8 = "SELECT name,password FROM info";
    sqlite3_prepare_v2(db, sql8.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
            string username4 = ( const char *)( sqlite3_column_text(stmt,0));
            string password4 = ( const char *)( sqlite3_column_text(stmt,1));
    if ( username==username4 && password1==password4 ){
            found =1;
            break;
        }
    }
    if ( !found ){
        cout<<setw(60)<<"SUCCESSFULLY LOGIN!!!!"<<endl;
    } else {
        cout<<setw(60)<<"SORRY YOUR USERNAME DOES NOT EXIT PLEAS REGISTER FIRST!!!"<<endl;
    }
}









































