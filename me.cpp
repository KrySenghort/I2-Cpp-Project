// #include<iostream>
// #include<conio.h>
// #include<stdio.h>
// #include<iomanip>
// #include<fstream>
// #include<windows.h>
// #include <time.h>
// #include <string.h>
// #include <ctime>
// using namespace std;
// class link{
// private:
//     struct node{
//         int pin;
//         double balance;
//         double balanceriel;
//         string id,pass,name,fname,address,phone;
//         node *next_add;
//     };
//     node *head = NULL;
// public:
//     void menu();
//     void load_data();
//     void insert_record();
//     void search_record();
//     void edit_record();
//     void del();
//     void show_record();
//     void withdraw();
//     void saving();
//     void transfer();
// };
// void link::menu(){
//     p:
//     system("cls");
//     int choice;
//     cout<<"==============================="<<endl;
//     cout<<" 1 . Insert New Record  "<<endl;
//     cout<<" 2 . Search Record  "<<endl;
//     cout<<" 3 . Edit Record  "<<endl;
//     cout<<" 4 . Delete Record  "<<endl;
//     cout<<" 5 . Show All Record  "<<endl;
//     cout<<" 6 . Withdraw Account "<<endl;
//     cout<<" 7 . Saving Account "<<endl;
//     cout<<" 8 . Transfer  Account "<<endl;
//     cout<<" 9 . Exit  "<<endl;
//     cout<<"Enter Your choice : ";
//     cin>>choice;
//     switch(choice){
//         case 1:{
//             insert_record();
//         }break;
//         case 2:{
//             head = NULL;
//             load_data();
//             search_record();
//         }break;
//         case 3:{
//             head = NULL;
//             load_data();
//             edit_record();
//         }break;
//         case 4:{
//             head = NULL;
//             load_data();
//             del();
//         }break;
//         case 5:{
//             head = NULL;
//             load_data();
//             show_record();
//         }break;
//         case 6:{
//             head = NULL;
//             load_data();
//             withdraw();
//         }break;
//         case 7:{
//             saving();
//         }break;
//         case 8:{
//             transfer();
//         }break;
//         case 9:{
//             exit(0);
//         }break;
//         default:{
//             cout<<" Invalid Choice ..."<<endl;
//         }
//     }
//     getch();
//     goto p;
// }
// void link::load_data(){
//     fstream file;
//     int e_pin;
//     double e_balance;
//     double e_balanceriel;
//     string e_id,e_pass,e_name,e_fname,e_address,e_phone;
//     file.open("link.txt",ios::in);
//     if(file){
//         file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance>>e_balanceriel;
//         while(!file.eof()){
//             node *new_node = new node;
//             new_node->id = e_id;
//             new_node->pass = e_pass;
//             new_node->pin = e_pin;
//             new_node->name = e_name;
//             new_node->fname = e_fname;
//             new_node->address = e_address;
//             new_node->phone = e_phone;
//             new_node->balance = e_balance;
//             new_node->balanceriel = e_balanceriel;
//             new_node->next_add = NULL;
//             if(head == NULL){
//                 head = new_node;
//             }else{
//                 node *ptr = head;
//                 while(ptr->next_add != NULL){
//                     ptr = ptr->next_add;
//                 }
//                 ptr->next_add = new_node;
//             }
//             file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance>>e_balanceriel;
//         }
//         file.close();
//     }
// }
// void link::insert_record(){
//     system("cls");
//     fstream file;
//     int e_pin;
//     double e_balance;
//     double e_balanceriel;
//     string e_id,e_pass,e_name,e_fname,e_address,e_phone;
//     cout<<"===================================\n";
//     cout<<"  Create New Account & User Account  "<<endl;
//     cout<<"===================================\n";
//     cout<<" User ID : ";
//     cin>>e_id;
//     cout<<" User Password : ";
//     cin>>e_pass;
//     cout<<" User PIN : ";
//     cin>>e_pin;
//     cout<<"User Name : ";
//     cin>>e_name;
//     cout<<"User Father Name : ";
//     cin>>e_fname;
//     cout<<"User Address : ";
//     cin>>e_address;
//     cout<<"User Phone Number : ";
//     cin>>e_phone;
//     cout<<"User Dola Balance : ";
//     cin>>e_balance;
//     cout<<"User Reil Balance : ";
//     cin>>e_balanceriel;
//     node *new_node = new node;
//     new_node->id = e_id;
//     new_node->pass = e_pass;
//     new_node->pin = e_pin;
//     new_node->name = e_name;
//     new_node->fname = e_fname;
//     new_node->address = e_address;
//     new_node->phone = e_phone;
//     new_node->balance = e_balance;
//     new_node->balanceriel = e_balanceriel;
//     new_node->next_add = NULL;
//     if(head == NULL){
//         head = new_node;
//     }else{
//         node *ptr = head;
//         while(ptr->next_add != NULL){
//             ptr = ptr->next_add;
//         }
//         ptr->next_add = new_node;
//     }
//     file.open("link.txt",ios::app|ios::out);
//     file<<e_id<<" "<<e_pass<<" "<<e_pin<<" "<<e_name<<" "<<e_fname<<" "<<e_address<<" "<<e_phone<<" "<<e_balance<<" "<<e_balanceriel<<"\n";
//     file.close();
//     cout<<"Insert Successfully..."<<endl;
// }
// void link::search_record(){
//     system("cls");
//     string e_id;
//     int found = 0;
//     cout<<"===================================\n";
//     cout<<"  2. Search  Record      "<<endl;
//     cout<<"===================================\n";
//     if(head == NULL){
//         cout<<" No record .... \n";
//     }else{
//         cout<<"\n\n User ID: ";
//         cin>>e_id;
//         node *ptr = head;
//         while( ptr != NULL){
//             if(ptr->id == e_id){
//                 system("cls");
//                  cout<<"===================================\n";
//                  cout<<"  2. Search  Record      "<<endl;
//                  cout<<"===================================\n";
//                  cout<<"\n User ID : "<<ptr->id;
//                  cout<<"\n User Password : "<<ptr->pass;
//                  cout<<"\n User PIN : "<<ptr->pin;
//                  cout<<"\n User Name :"<<ptr->name;
//                  cout<<"\n User Father Name :"<<ptr->fname;
//                  cout<<"\n User Address :"<<ptr->address;
//                  cout<<"\n User Phone Number :"<<ptr->phone;
//                  cout<<"\n User Dola Balance :"<<ptr->balance;
//                  cout<<"\n User Reil Balance :"<<ptr->balanceriel;
//                  found++;
//             }
//             ptr = ptr->next_add;
//         }
//         if(found == 0){
//             cout<<"\n Search not Found...."<<endl;
//         }
//     }
// }
// void link::show_record(){
//     system("cls");
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  5. Show ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//          cout<<"\n\n\t\t\t No Record...";
//     }else{
//         cout<<"\n\nID\t\tPassword\tPin\t    Name\t Father Name\t Address\tPhone\t\t  Balance($)\t   Balance(៛)";
//         node *ptr = head;
//         while(ptr != NULL){
//             cout<<"\n"<<ptr->id<<"\t"<<ptr->pass<<"\t\t"<<ptr->pin<<"\t    "<<ptr->name<<"\t "<<ptr->fname<<"\t\t"<<ptr->address<<"\t\t"<<ptr->phone<<"\t  "<<ptr->balance<<"    \t\t"<<ptr->balanceriel<<"\n";
//             ptr = ptr->next_add;
//         }
//     }

// }
// void link::edit_record(){
//     system("cls");
//     fstream file,file1;
//     string t_id,emp_id,id;
//     int emp_pin,pin,found = 0;
//     double emp_balance,balance;
//     double emp_balanceriel,balancereil;
//     string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         cout<<"\n\n\t\t\t Employee ID : ";
//         cin>>t_id;
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(t_id == emp_id){
//                 cout<<"\t\t\t===================================\n";
//                 cout<<"\t\t\t   Setting ALL  Record      "<<endl;
//                 cout<<"\t\t\t===================================\n";
//                 cout<<"\n\n\t\t\t User New ID :";
//                 cin>>id;
//                 cout<<"\n\n\t\t\t User New Password :";
//                 cin>>pass;
//                 cout<<"\n\n\t\t\t User New PIN :";
//                 cin>>pin;
//                 name = emp_name;
//                 fname = emp_fname;
//                 address = emp_address;
//                 phone = emp_phone;
//                 balance = emp_balance;
//                 balancereil = emp_balanceriel;
//                 file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
//                 cout<<"\n\n\t\t\t Adit Record Successfully....";
//                 found++;
//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
// }
// void link::del(){
//     system("cls");
//     fstream file,file1;
//     string t_id,emp_id;
//     int emp_pin;
//     double emp_balance;
//     double emp_balanceriel;
//     string emp_pass,emp_name,emp_fname,emp_address,emp_phone;
//     int found = 0;
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  4. Delete ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         cout<<"\n\n\t\t\t Employee ID : ";
//         cin>>t_id;
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(t_id == emp_id){
//                 cout<<"\t\t\t===================================\n";
//                 cout<<"\t\t\t   Delete ALL  Record      "<<endl;
//                 cout<<"\t\t\t===================================\n";
//                 cout<<"\n\n\t\t\t Delete Record Successfully....";
//                 found++;

//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
// }
// void link::withdraw(){
//     system("cls");
//     fstream file,file1;
//     node *ptr ;
//     string t_id,emp_id,id;
//     int emp_pin,pin,found = 0;
//     double emp_balance,balance;
//     double emp_balanceriel,balancereil;
//     string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
//     double withdraw,withdrawReil;
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         cout<<"\n\n\t\t\t Employee ID : ";
//         cin>>t_id;
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(t_id == emp_id){
//                 cout<<"\n\n Enter Amount For withdraw Dola Account : ";
//                 cin>>withdraw;
//                 cout<<"\n\n Enter Amount For withdraw Reil Account : ";
//                 cin>>withdrawReil;
//                 emp_balanceriel -= withdrawReil;
//                 emp_balance -= withdraw;
//                 if(withdraw < balance){
//                     balance -= withdraw;
//                     cout<<"\n\n\t\t\t You Amount : "<<withdraw<<"  Successfully Withdraw....";
//                     cout<<"\n\n\t\t\t You Amount "<<emp_balance<<"  is less ...";
//                 }else{
//                     cout<<"\n\n\t\t\t Your Current Balance  "<<balance<<"  is Less...";
//                 }
//                 id = emp_id;
//                 pass = emp_pass;
//                 pin = emp_pin;
//                 name = emp_name;
//                 fname = emp_fname;
//                 address = emp_address;
//                 phone = emp_phone;
//                 balance = emp_balance;
//                 balancereil = emp_balanceriel;
//                 file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
//                 cout<<"\n\n\t\t\t Withdraw Successfully....";
//                 found++;
//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
// }
// void link::saving(){
//     system("cls");
//     node *ptr;
//     fstream file,file1;
//     string t_id,emp_id,id;
//     int emp_pin,pin,found = 0;
//     double emp_balance,balance;
//     double emp_balanceriel,balancereil;
//     string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
//     double saving,savingReil;
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         cout<<"\n\n\t\t\t Employee ID : ";
//         cin>>t_id;
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(t_id == emp_id){
//                 cout<<"\n\n Enter Amount For withdraw Dola Account : ";
//                 cin>>saving;
//                 cout<<"\n\n Enter Amount For withdraw Reil Account : ";
//                 cin>>savingReil;
//                 emp_balanceriel += savingReil;
//                 emp_balance += saving;
//                 id = emp_id;
//                 pass = emp_pass;
//                 pin = emp_pin;
//                 name = emp_name;
//                 fname = emp_fname;
//                 address = emp_address;
//                 phone = emp_phone;
//                 balance = emp_balance;
//                 balancereil = emp_balanceriel;
//                 file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
//                 cout<<"\n\n\t\t\t Saving Successfully....";
//                 found++;
//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
// }
// void link::transfer(){
//     fstream file,file1;
//     system("cls");
//     node *ptr;
//     string r_id,s_id,t_id,id;
//     string emp_id;
//     int emp_pin,pin,found = 0;
//     double emp_balance,balance;
//     double emp_balanceriel,balancereil;
//     string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
//     double amount,amountReil;
//     cout<<"\n\n\t\t\t Payment Transfer option ";
//     cout<<"\n\n Enter User ID for Transection : ";
//     cin>>r_id;
//     cout<<"\n\n Reciver User ID for Transfer ";
//     cin>>s_id;
//     cout<<"Enter Transfer Amount : ";
//     cin>>amount;
//     cout<<"Enter Transfer Amount Reil : ";
//     cin>>amountReil;
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(r_id == emp_id){
//                 emp_balanceriel -=amountReil;
//                 emp_balance -= amount;
//                 id = emp_id;
//                 pass = emp_pass;
//                 pin = emp_pin;
//                 name = emp_name;
//                 fname = emp_fname;
//                 address = emp_address;
//                 phone = emp_phone;
//                 balance = emp_balance;
//                 balancereil = emp_balanceriel;
//                 file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         file.open("link.txt",ios::in);
//         file1.open("link1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         while(!file.eof()){
//             if(s_id == emp_id){
//                 emp_balanceriel += amountReil;
//                 emp_balance += amount;
//                 id = emp_id;
//                 pass = emp_pass;
//                 pin = emp_pin;
//                 name = emp_name;
//                 fname = emp_fname;
//                 address = emp_address;
//                 phone = emp_phone;
//                 balance = emp_balance;
//                 balancereil = emp_balanceriel;
//                 file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
//             }
//             else{
//                 file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
//             }
//             file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
//         }
//         file.close();
//         file1.close();
//         remove("link.txt");
//         rename("link1.txt","link.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }

// }
// int main(){
//     link l;
//     l.menu();

// }















// #include<iostream>
// #include<conio.h>
// #include<stdio.h>
// #include<iomanip>
// #include<fstream>
// #include<windows.h>
// #include <time.h>
// #include <string.h>
// #include <ctime>
// #include<cmath>
// using namespace std;
// char load = 219;
// int i=0;
// class queue
// {
//   protected:
//       struct node
//       {
//           string id;
//           int arr[20];
//           string data;
//           string name;
//           string gender;
//           int x,x1,x2;
//           node *next;
//       };
//       node *head = NULL;
//       node *tail = NULL;
//   public:
//     void menu3();
//     void load_data3();
//     void push();
//     void display();
//     void pop();
// };
// void queue::load_data3(){
//     fstream file;
//     string emp_id;
//     string emp_data,emp_name,emp_gender;
//     int emp_x,emp_x1,emp_x2;
//     file.open("table.txt",ios::in);
//     if(file){
//         file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
//         while(!file.eof()){
//             node *new_node = new node;
//             new_node->id = emp_id;
//             new_node->data = emp_data;
//             new_node->name = emp_name;
//             new_node->gender = emp_gender;
//             new_node->x = emp_x;
//             new_node->x1 = emp_x1;
//             new_node->x2 = emp_x2;
//             new_node->next = NULL;
//             if(head == NULL){
//                 head = new_node;
//                 tail = new_node;
//             }else{
//                 tail -> next = new_node;
//                 tail = new_node;
//             }
//             file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
//         }
//         file.close();
//     }
// }
// void queue::push()
// {
//     fstream file;
//     system("cls");
//     string emp_id;
//     string emp_data,emp_name,emp_gender;
//     int emp_x,emp_x1,emp_x2;
//     cout<<"\n\n\t\t\t\t Push Record";
//     cout<<"\n\n Enter ID : ";
//     cin>>emp_id;
//     cout<<"\n\n Your Function : ";
//     cin>>emp_data;
//     cout<<"\n\n Your Name : ";
//     cin>>emp_name;
//     cout<<"\n\n Your Gender : ";
//     cin>>emp_gender;
//     cout<<"\n\n Time Hour Second Minutes : ";
//     cin>>emp_x>>emp_x1>>emp_x2;
//     node *new_node = new node;
//     new_node->id = emp_id;
//     new_node->data = emp_data;
//     new_node->name = emp_name;
//     new_node->gender = emp_gender;
//     new_node->x = emp_x;
//     new_node->x1 = emp_x1;
//     new_node->x2 = emp_x2;
//     new_node -> next = NULL;
//     if(head == NULL)
//     {
//         head = new_node;
//         tail = new_node;
//     }else{
//         tail -> next = new_node;
//         tail = new_node;
//     }
//     file.open("table.txt",ios::app|ios::out);
//     file<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<" \n";
//     file.close();
// }
// void queue::display()
// {
//     system("cls");
//     SYSTEMTIME x;
//     int k = 0;
//     cout<<"\n\n\t\t\t\tDisplay Record"<<endl;
//     if(head == NULL){
//         cout<<"\n\n Queue is Empty..."<<endl;
//     }else{
//         node *ptr = head;
//         while(ptr != NULL){
//                  GetSystemTime(&x);
//                  int n = sizeof(ptr->arr)/sizeof(ptr->arr[0]) - ++i;
//                  system("color 0B");
//                  cout<<"\n\t\t\t\t\t";
//                  for(int j=0;j<=31;j++)
//                  cout<<load;
//                  cout<<"\n";
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"  TABLE PLEASE SITDOWN  :    "<<++k<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t";
//                  for(int j=0;j<=31;j++)
//                  cout<<load;
//                  cout<<"\n";
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<"    ID       : "<< ptr->id <<endl;
//                  cout<<"\t\t\t\t\t"<<"    FUNCTION : "<< ptr->data <<endl;
//                  cout<<"\t\t\t\t\t"<<"    NAME     : "<< ptr->name <<endl;
//                  cout<<"\t\t\t\t\t"<<"    GENDER   : "<< ptr->gender <<endl;
//                  cout<<"\t\t\t\t\t"<<"   TABLE FREE: "<< n<<endl;
//                  cout<<"\t\t\t\t\t"<<"    TIME     : "<< ptr->x<<":"<<ptr->x1<<":"<<ptr->x2<<endl;
//                  cout<<"\t\t\t\t\t"<<"    DATE     : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                  cout<<"\t\t\t\t\t";
//                  for(int j=0;j<=31;j++)
//                  cout<<load;
//                  cout<<"\n";
//                  ptr=ptr -> next;
//         }
//     }
// }
// void queue::pop(){
//     system("cls");
//     fstream file,file1;
//     string t_id,emp_id;
//     string emp_data,emp_name,emp_gender;
//     int emp_x,emp_x1,emp_x2;
//     int found = 0;
//     cout<<"\t\t\t===================================\n";
//     cout<<"\t\t\t  4. Delete ALL  Record      "<<endl;
//     cout<<"\t\t\t===================================\n";
//     if(head == NULL){
//         cout<<"\n\n\t\t\t NO Record ...."<<endl;
//     }else{
//         cout<<"\n\n\t\t\t Employee ID : ";
//         cin>>t_id;
//         file.open("table.txt",ios::in);
//         file1.open("table1.txt",ios::app|ios::out);
//         file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
//         while(!file.eof()){
//             if(t_id == emp_id){
//                 system("color 0C");
//                 cout<<"\t\t\t\t\t";
//                 for(int j=0;j<=31;j++)
//                 cout<<load;
//                 cout<<"\n";
//                 cout<<"\t\t\t\t\t"<<load<<"----------------------------  "<<load<<endl;
//                 cout<<"\t\t\t\t\t"<<load<<"      Delete ALL  Record      "<<load<<endl;
//                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
//                 cout<<"\t\t\t\t\t"<<load<<" ---------------------------  "<<load<<endl;
//                 cout<<"\t\t\t\t\t"<<load<<"  Delete Record Successfully.."<<load<<endl;
//                 cout<<"\t\t\t\t\t";
//                 for(int j=0;j<=31;j++)
//                 cout<<load;
//                 cout<<"\n";
//                 found++;

//             }
//             else{
//                 file1<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<"\n";
//             }
//             file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
//         }
//         file.close();
//         file1.close();
//         remove("table.txt");
//         rename("table1.txt","table.txt");
//         if(found == 0){
//             cout<<"\n\n\t\t\t Employee can not Found...";
//         }
//     }
// }
// void queue::menu3(){
//     int choice;
//     q:
//     cout<<"\n\n\t\t\t\tControl Panel";
//     cout<<"\n\n 1.Push Record";
//     cout<<"\n 2. Display Record";
//     cout<<"\n 3. Pop Record";
//     cout<<"\n 4. Exit";
//     cout<<"\n\n Your Choice : ";
//     cin>>choice;
//     switch(choice){
//         case 1:{
//              push();
//         }break;
//         case 2:{
//              head = NULL;
//              load_data3();
//              display();
//         }break;
//         case 3:{
//              pop();
//         }break;
//         case 4:{
//             exit(0);
//         }break;
//         default:{
//             cout<<"\n\n Invalid Value...Please Try Agian...";
//         }
//     }
//     goto q;
//     getch();
// }
// main()
// {
//     queue q;
//     q.menu3();
//     return 0;
// }



#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
int size = 0;
class link_list{
private:
    struct node{
        int data;
        node *next;
    };
    node *head = NULL;
    node *tail = NULL;
public:
    void insert(int &n);
    void diplay();
    void search();
    void update();
    void del();
};
void link_list::insert(int &n){
    node *new_ptr = new node;
    new_ptr->data = n;
    new_ptr->next = NULL;
    size++;
    if(head == NULL){
        head = new_ptr;
        tail = new_ptr;
        new_ptr->next = head;
    }else{
        tail->next = new_ptr;
        tail = new_ptr;
        tail->next = head;
    }
}
void link_list::diplay(){
    system("cls");
    cout<<"\n\n\t\t\t Display Record ";
    int c = 0;
    if(head == NULL){
        cout<<"\n\nCircular is empty...";
    }
    else{
        node *ptr = head;
        while(c != size){
            cout<<"\n\n Value : "<<ptr->data;
            ptr = ptr->next;
            c++;
        }
    }
}
void link_list::search(){
    system("cls");
    int c = 0, n,found=0;
    cout<<"\n\n\t\t\t  Search Record   ";
    if(head == NULL){
        cout<<"\n\n Circular is empty...";
    }else{
        cout<<"\n\n Enter Value : ";
        cin>>n;
        node *ptr = head;
        while( c !=size){
            if(n == ptr->data){
                cout<<"\n\n Value "<<n<<" is found...";
                found++;
                break;
            }
            ptr= ptr->next;
            c++;
        }
    }
    if(found==0){
        cout<<"\n\n Value "<<n<<" can not found...";
    }
}
void link_list::update(){
    system("cls");
    int c = 0, n,found=0;
    cout<<"\n\n\t\t\t  Update Record   ";
    if(head == NULL){
        cout<<"\n\n Circular is empty...";
    }
    else{
        cout<<"\n\n Enter value : ";
        cin>>n;
        node *ptr = head;
        while(c != size){
            if(n == ptr->data){
                cout<<"\n\n New value : ";
                cin>>n;
                ptr->data = n;
                found++;
                break;
                cout<<"\n\n Update value successfully...";
            }
            ptr = ptr->next;
            c++;
        }
    }
    if(found==0){
        cout<<"\n\n Value "<<n<<" Update not successfully...";
    }
}
void link_list::del(){
    system("cls");
    int n,c=1,found=0;
    cout<<"\n\n\t\t\t Delete Record ";
    if(head == NULL){
        cout<<"\n\n Circular is empty...";
    }
    else{
        node *ptr = head;
        cout<<"\n\n Enter value :";
        cin>>n;
        if(size == 1 && n == head->data){
            head = NULL;
            tail = NULL;
            size--;
            cout<<"\n\n Node Delete Successfully... ";
            found++;
            delete ptr;
        }
        else if(n == head->data){//first node
            head = head->next;
            tail->next = head;
            size--;
            cout<<"\n\n Node Delete Successfully... ";
            found++;
            delete ptr;
        }
        else if(n == tail->data){//last node
            while(ptr->next != tail){
                ptr = ptr->next;
            }
            node *pre = tail;
            tail = ptr;
            tail->next = head;
            size--;
            cout<<"\n\n Node Delete Successfully... ";
            found++;
            delete pre;
        }
        else{//position node
            node *pre_ptr = head;
            ptr = head->next;
            while( c != size){
                if(n == ptr->data){
                    pre_ptr->next = ptr->next;
                    size--;
                    cout<<"\n\n Node Delete Successfully... ";
                    found++;
                    delete ptr;
                    break;
                }
                pre_ptr = ptr;
                ptr = ptr->next;
                c++;
            }
        }
    }
    if(found==0){
        cout<<"\n\n Value "<<n<<" Delete not successfully...";
    }
}
int main(){
    link_list l;
    p:
    int choice,n;
    cout<<"\n\n\t\t\t Control Panel";
    cout<<"\n\n 1. Insert Record   ";
    cout<<"\n\n 2. Display Record   ";
    cout<<"\n\n 3. Search Record   ";
    cout<<"\n\n 4. Update Record   ";
    cout<<"\n\n 5. delete Record   ";
    cout<<"\n\n 6. Quiz Program   ";
    cout<<"\n\n Your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            system("cls");
            cout<<"\n\n\n\t\t\t Insert Record ";
            cout<<"\n\n Enter value : ";
            cin>>n;
            l.insert(n);
        }break;
        case 2:{
            l.diplay();
        }break;
        case 3:{
            l.search();
        }break;
        case 4:{
            l.update();
        }break;
        case 5:{
            l.del();
        }break;
        case 6:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid Choice...";
        }
    }
    goto p;
    getch();
    return 0;
}









int choice;
cout<<"W. fddfdf"<<endl;
cout<<"W. ffdfdf"<<endl;
cout<<"Enter your choice: "<<endl;
switch(choice)




