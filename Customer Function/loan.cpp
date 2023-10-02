// #include <iostream>
// using namespace std;
// class Loan{
// public:
//     Loan(double upphaed, double vextir, int afborganir);
//     void displaySchedule();
// private:
//     void pay(int i);
//     double payments();
//     double interest(int i);
//     double Balance(int i);
//     double sumOfInstalments;
//     double sumOfInterest;
//     double total;
//     double principal;
//     double interestRate;
//     int numOfPayments;
// };
// Loan::Loan(double upphaed, double vextir, int afborganir){
//     upphaed = principal;
//     vextir = interestRate;
//     afborganir = numOfPayments;
//     sumOfInstalments = 0.0;
//     sumOfInterest = 0.0;
//     total = 0.0;
// }
// void Loan::pay(int i){
//     sumOfInstalments += payments();
//     sumOfInterest += interest(i);
//     total += payments() + interest(i);
// }
// double Loan::payments()
//     return principal / numOfPayments;
// double Loan::interest(int i)
//     return Balance(i) * (interestRate / 12) / 100;
// double Loan::Balance(int i)
//     return principal - (i - 1) * payments();
// void readData(double principal, double interestRate, int numOfPayments){
//     cout << "Principal: ";
//     cin >> principal;
//     cout << "Interest rate: ";
//     cin >> interestRate;
//     cout << "Number of payments: ";
//     cin >> numOfPayments;
// }
// void Loan::displaySchedule(){
//     cout << "No.\tBalance\tInstalment\tInterest\tTotal\tpayment"<<endl;
//     cout << "----------------------------------------------------------------" << endl;
//     for (int i=1;i<=numOfPayments;i++){
//         cout<<i<<"\t"<<Balance(i)<<"\t"<<payments()<<"\t"<<interest(i)<<"\t"<<(payments()+interest(i));
//         pay(i);
//     }
//     cout << "----------------------------------------------------------------" << endl;
//     cout << sumOfInstalments << sumOfInterest << total;
// }
// int main(){
//     double amount, interestRate, numPayments;
//     readData(amount, interestRate, numPayments);
//     Loan myLoan(amount, interestRate, numPayments);
//     myLoan.displaySchedule();
//     return 0;
// }
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<windows.h>
#include <time.h>
#include <string.h>
#include <ctime>
#include<cmath>
using namespace std;
char load=219;
class link{
protected:
    struct node{
        int pin;
        double balance;
        double balanceriel;
        string id,pass,name,fname,address,phone;
        node *next_add;
    };
    node *head = NULL;
public:
    void menu1();
    void load_data();
    void insert_record();
    void search_record();
    void edit_record();
    void del();
    void show_record();
    void withdraw();
    void saving();
    void transfer();
    void loaded();
    void payment();
};
void link::menu1(){
    p:
    system("cls");
    int choice;
    cout<<"==============================="<<endl;
    cout<<" 1 . Insert New Record  "<<endl;
    cout<<" 2 . Search Record  "<<endl;
    cout<<" 3 . Edit Record  "<<endl;
    cout<<" 4 . Delete Record  "<<endl;
    cout<<" 5 . Show All Record  "<<endl;
    cout<<" 6 . Withdraw Account "<<endl;
    cout<<" 7 . Saving Account "<<endl;
    cout<<" 8 . Transfer  Account "<<endl;
    cout<<" 9 . Payment Another Service "<<endl;
    cout<<" 10 . Exit  "<<endl;
    cout<<"Enter Your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            insert_record();
        }break;
        case 2:{
            head = NULL;
            load_data();
            search_record();
        }break;
        case 3:{
            head = NULL;
            load_data();
            edit_record();
        }break;
        case 4:{
            head = NULL;
            load_data();
            del();
        }break;
        case 5:{
            head = NULL;
            load_data();
            show_record();
        }break;
        case 6:{
            head = NULL;
            load_data();
            withdraw();
        }break;
        case 7:{
            saving();
        }break;
        case 8:{
            transfer();
        }break;
        case 9:{
            head = NULL;
            load_data();
            payment();
        }break;
        case 10:{
            exit(0);
        }break;
        default:{
            cout<<" Invalid Choice ..."<<endl;
        }
    }
    getch();
    goto p;
}
void link::load_data(){
    fstream file;
    int e_pin;
    double e_balance;
    double e_balanceriel;
    string e_id,e_pass,e_name,e_fname,e_address,e_phone;
    file.open("link.txt",ios::in);
    if(file){
        file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance>>e_balanceriel;
        while(!file.eof()){
            node *new_node = new node;
            new_node->id = e_id;
            new_node->pass = e_pass;
            new_node->pin = e_pin;
            new_node->name = e_name;
            new_node->fname = e_fname;
            new_node->address = e_address;
            new_node->phone = e_phone;
            new_node->balance = e_balance;
            new_node->balanceriel = e_balanceriel;
            new_node->next_add = NULL;
            if(head == NULL){
                head = new_node;
            }else{
                node *ptr = head;
                while(ptr->next_add != NULL){
                    ptr = ptr->next_add;
                }
                ptr->next_add = new_node;
            }
            file>>e_id>>e_pass>>e_pin>>e_name>>e_fname>>e_address>>e_phone>>e_balance>>e_balanceriel;
        }
        file.close();
    }
}
void link::insert_record(){
    system("cls");
    fstream file;
    int e_pin;
    double e_balance;
    double e_balanceriel;
    string e_id,e_pass,e_name,e_fname,e_address,e_phone;
    cout<<"===================================\n";
    cout<<"  Create New Account & User Account  "<<endl;
    cout<<"===================================\n";
    cout<<" User ID : ";
    cin>>e_id;
    cout<<" User Password : ";
    cin>>e_pass;
    cout<<" User PIN : ";
    cin>>e_pin;
    cout<<"User Name : ";
    cin>>e_name;
    cout<<"User Father Name : ";
    cin>>e_fname;
    cout<<"User Address : ";
    cin>>e_address;
    cout<<"User Phone Number : ";
    cin>>e_phone;
    cout<<"User Dola Balance : ";
    cin>>e_balance;
    cout<<"User Reil Balance : ";
    cin>>e_balanceriel;
    node *new_node = new node;
    new_node->id = e_id;
    new_node->pass = e_pass;
    new_node->pin = e_pin;
    new_node->name = e_name;
    new_node->fname = e_fname;
    new_node->address = e_address;
    new_node->phone = e_phone;
    new_node->balance = e_balance;
    new_node->balanceriel = e_balanceriel;
    new_node->next_add = NULL;
    if(head == NULL){
        head = new_node;
    }else{
        node *ptr = head;
        while(ptr->next_add != NULL){
            ptr = ptr->next_add;
        }
        ptr->next_add = new_node;
    }
    file.open("link.txt",ios::app|ios::out);
    file<<e_id<<" "<<e_pass<<" "<<e_pin<<" "<<e_name<<" "<<e_fname<<" "<<e_address<<" "<<e_phone<<" "<<e_balance<<" "<<e_balanceriel<<"\n";
    file.close();
    cout<<"Insert Successfully..."<<endl;
}
void link::search_record(){
    system("cls");
    SYSTEMTIME x;
    string e_id;
    int found = 0;
    cout<<"===================================\n";
    cout<<"  2. Search  Record      "<<endl;
    cout<<"===================================\n";
    if(head == NULL){
        cout<<" No record .... \n";
    }else{
        cout<<"\n\n User ID: ";
        cin>>e_id;
        node *ptr = head;
        while( ptr != NULL){
            if(ptr->id == e_id){
                system("cls");
                 system("color 0A");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
                 cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
                 cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
                 cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
                 cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 found++;
            }
            ptr = ptr->next_add;
        }
        if(found == 0){
            cout<<"\n Search not Found...."<<endl;
        }
    }
}
void link::show_record(){
    system("cls");
    SYSTEMTIME x;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  5. Show ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
         cout<<"\n\n\t\t\t No Record...";
    }else{
        node *ptr = head;
        while(ptr != NULL){
            system("color 0A");
            cout<<"\n\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
            cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
            cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
            cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
            cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
            cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
            cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
            cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
            cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
            cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            ptr = ptr->next_add;
        }
    }

}
void link::edit_record(){
    system("cls");
    fstream file,file1;
    string t_id,emp_id,id;
    int emp_pin,pin,found = 0;
    double emp_balance,balance;
    double emp_balanceriel,balancereil;
    string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\t\t\t===================================\n";
                cout<<"\t\t\t   Setting ALL  Record      "<<endl;
                cout<<"\t\t\t===================================\n";
                cout<<"\n\n\t\t\t User New ID :";
                cin>>id;
                cout<<"\n\n\t\t\t User New Password :";
                cin>>pass;
                cout<<"\n\n\t\t\t User New PIN :";
                cin>>pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
                cout<<"\n\n\t\t\t Adit Record Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void link::del(){
    system("cls");
    fstream file,file1;
    string t_id,emp_id;
    int emp_pin;
    double emp_balance;
    double emp_balanceriel;
    string emp_pass,emp_name,emp_fname,emp_address,emp_phone;
    int found = 0;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  4. Delete ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\t\t\t===================================\n";
                cout<<"\t\t\t   Delete ALL  Record      "<<endl;
                cout<<"\t\t\t===================================\n";
                cout<<"\n\n\t\t\t Delete Record Successfully....";
                found++;

            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void link::withdraw(){
    p:
    system("cls");
    fstream file,file1;
    node *ptr ;
    string t_id,emp_id,id;
    int emp_pin,pin,found = 0;
    double emp_balance,balance;
    double emp_balanceriel,balancereil;
    string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
    double withdraw,withdrawReil;
    string again;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\n\n Enter Amount For withdraw Dola Account : ";
                cin>>withdraw;
                cout<<"\n\n Enter Amount For withdraw Reil Account : ";
                cin>>withdrawReil;
                cout<<"Do you want to withdraw money ?(yes/no) : ";
                cin>>again;
                if(again == "yes" || again == "Yes"){
                    if(withdraw <= emp_balance && withdrawReil <= emp_balanceriel){
                         emp_balanceriel -= withdrawReil;
                         emp_balance -= withdraw;
                         cout<<"\n\n\t\t\t You Amount : "<<withdraw<<"  Successfully Withdraw....";
                         cout<<"\n\n\t\t\t You Amount "<<emp_balance<<"  is less ...";
                         cout<<"\n\n\t\t\t You Reil Amount : "<<withdrawReil<<" Successfully Withdraw ...";
                         cout<<"\n\n\t\t\t You Amount "<<emp_balanceriel<<"  is less ...";
                    }else{
                        cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balance<<"  is Less...";
                        cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balanceriel<<"  is Less...";
                    }
                }else if(again == "no" || again == "No" ){
                    break;
                }else{
                    goto p;
                }
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
                cout<<"\n\n\t\t\t Withdraw Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void link::saving(){
    p:
    system("cls");
    node *ptr;
    fstream file,file1;
    string t_id,emp_id,id;
    int emp_pin,pin,found = 0;
    double emp_balance,balance;
    double emp_balanceriel,balancereil;
    string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
    double saving,savingReil;
    string again;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\n\n Enter Amount For withdraw Dola Account : ";
                cin>>saving;
                cout<<"\n\n Enter Amount For withdraw Reil Account : ";
                cin>>savingReil;
                cout<<"Do you want to saving money ?(yes/no) : ";
                cin>>again;
                if(again == "yes" || again == "Yes"){
                    emp_balanceriel += savingReil;
                    emp_balance += saving;
                    cout<<"\n\n\t\t\t Your balance is : "<<emp_balance<<" Saving Successfully ...";
                    cout<<"\n\n\t\t\t Your balance Reil is : "<<emp_balanceriel<<" Saving Successfully ...";
                }else if(again == "no" || again == "No"){
                    break;
                }else{
                    goto p;
                }
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
                cout<<"\n\n\t\t\t Saving Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void link::transfer(){
    p:
    fstream file,file1;
    system("cls");
    node *ptr;
    string r_id,s_id,t_id,id;
    string emp_id;
    int emp_pin,pin,found = 0;
    double emp_balance,balance;
    double emp_balanceriel,balancereil;
    string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
    double amount,amountReil;
    string again;
    cout<<"\n\n\t\t\t Payment Transfer option ";
    cout<<"\n\n Enter User ID for Transection : ";
    cin>>r_id;
    cout<<"\n\n Reciver User ID for Transfer ";
    cin>>s_id;
    cout<<"Enter Transfer Amount : ";
    cin>>amount;
    cout<<"Enter Transfer Amount Reil : ";
    cin>>amountReil;
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(r_id == emp_id){
                cout<<"Do you want to Transfer to another right ?(yes/no) : ";
                cin>>again;
                if(again == "yes" || again == "no"){
                     if(amount <= emp_balance && amountReil <= emp_balanceriel){
                        emp_balanceriel -=amountReil;
                        emp_balance -= amount;
                        cout<<"\n\n\t\t\t You Amount : "<<amount<<"  Successfully Withdraw....";
                        cout<<"\n\n\t\t\t You Amount "<<emp_balance<<"  is less ...";
                        cout<<"\n\n\t\t\t You Reil Amount : "<<amountReil<<" Successfully Withdraw ...";
                        cout<<"\n\n\t\t\t You Amount "<<emp_balanceriel<<"  is less ...";
                     }else{
                         cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balance<<"  is Less...";
                         cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balanceriel<<"  is Less...";
                     }
                }else if(again == "No" || again == "no"){
                    break;
                }else{
                    goto p;
                }
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
                found++;
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(s_id == emp_id){
                emp_balanceriel += amountReil;
                emp_balance += amount;
                cout<<"\n\n\t\t\t Your balance is : "<<emp_balance<<" Saving Successfully ..."<<emp_id;
                cout<<"\n\n\t\t\t Your balance Reil is : "<<emp_balanceriel<<" Saving Successfully ...";
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }

}
void link::payment(){
    p:
    system("cls");
    fstream file,file1;
     node *ptr ;
    string t_id,emp_id,id;
    int emp_pin,pin,found = 0;
    double emp_balance,balance;
    double emp_balanceriel,balancereil;
    string emp_pass,pass,emp_name,name,emp_fname,fname,emp_address,address,emp_phone,phone;
    double withdraw,withdrawReil;
    string service;
    string sel;
    SYSTEMTIME x;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  PAYMENT ANOTHER SERVICE      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        cout<<"\n\n Name : ";
        cin>>emp_name;
        fflush(stdin);
        cout<<"\n\n Service Bill Name : ";
        getline(cin,service);
        cout<<"\n\n Bill Dola Amount : ";
        cin>>withdraw;
        cout<<"\n\n Bill Reil Amount : ";
        cin>>withdrawReil;
        file.open("link.txt",ios::in);
        file1.open("link1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"Do you want to payment another service ?(yes/no) : ";
                cin>>sel;
                if(sel == "yes" || sel == "yes"){
                    emp_balanceriel -= withdrawReil;
                    emp_balance -= withdraw;
                }else if(sel == "no" || sel == "No"){
                    break;
                }else{
                    goto p;
                }
                if(withdraw < emp_balance){
                    balance -= withdraw;
                    cout<<"\n\n\t\t\t You Amount : "<<withdraw<<"  Successfully Withdraw....";
                    cout<<"\n\n\t\t\t You Amount "<<emp_balance<<"  is less ...";
                }else{
                    cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balance<<"  is Less...";
                }
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balancereil = emp_balanceriel;

                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balancereil<<"\n";
                cout<<"\n\n\t\t\t Withdraw Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<" "<<emp_pass<<" "<<emp_pin<<" "<<emp_name<<" "<<emp_fname<<" "<<emp_address<<" "<<emp_phone<<" "<<emp_balance<<" "<<emp_balanceriel<<"\n";
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel;
        }
        file.close();
        file1.close();
        remove("link.txt");
        rename("link1.txt","link.txt");
        cout<<"\n\n\t\t\t Successfully....";
        if(found == 1){
            GetSystemTime(&x);
            file.open("payment.txt",ios::app|ios::out);
            file<<t_id<<" "<<emp_name<<" "<<withdraw<<" "<<withdrawReil<<" "<<x.wHour<<":"<<x.wMinute<<":"<<x.wSecond<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
            file.close();
            cout<<"\n\n\t\t\t "<<emp_name<<"  Bill Payment Successfully...";
        }else{
            cout<<" \n\n Payment Not Successfully..";
        }
    }

}
class pay:public link{
protected:
    struct node{
        int pin;
        long double balance;
        long double balanceriel;
        string id,pass,name,fname,mname,suportname,address,phone;
        string birday,job,plan_load;
        int n;
        node *pre,*next;
    };
    node *head = NULL;3
    node *tail = NULL;
public:
    void menu2();
    void load_data1();
    void information();
    void search();
    void show_Record();
    void update();
    void payback();
    void tableday();
};
void pay::menu2(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t Load Bank Management System    ";
    cout<<"\n\n\t\t\t 1. Information customer Load ";
    cout<<"\n\n\t\t\t 2. Show Record all customer ";
    cout<<"\n\n\t\t\t 3. Search Record all customer ";
    cout<<"\n\n\t\t\t 4. Update Record all customer ";
    cout<<"\n\n\t\t\t 5. Payment Back ";
    cout<<"\n\n\t\t\t 6. Show All Day To Payment ";
    cout<<"\n\n--------------------------------\n";
    cout<<"\n\n 2. Show_Record Balance ";
    cout<<"\n\n 5. Exit  ";
    cout<<"\n\n Please Select option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            information();
        }break;
        case 2:{
            head = NULL;
            load_data1();
            show_Record();
        }break;
        case 3:{
            head = NULL;
            load_data1();
            search();
        }break;
        case 4:{
            head = NULL;
            load_data1();
            update();
        }break;
        case 5:{
            head = NULL;
            load_data1();
            payback();
        }break;
        case 6:{
            tableday();
        }break;
        case 7:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n\t\t\t Invalid choice ...";
        }
    }
    getch();
    goto p;
}
void pay::load_data1(){
    fstream file;
    int pin1;
    long double balance1;
    long double balanceriel1;
    string id1,pass1,name1,fname1,mname1,suportname1,address1,phone1;
    string birday1,job1,plan_load1;
    int n1;
    file.open("load.txt",ios::in);
    if(file){
        file>>id1>>pass1>>pin1>>name1>>fname1>>mname1>>suportname1>>address1>>job1>>birday1>>plan_load1>>phone1>>balance1>>balanceriel1>>n1;
        while(!file.eof()){
            node *new_node = new node;
            new_node->id = id1;
            new_node->pass = pass1;
            new_node->name = name1;
            new_node->fname = fname1;
            new_node->mname = mname1;
            new_node->suportname = suportname1;
            new_node->address = address1;
            new_node->pin = pin1;
            new_node->birday = birday1;
            new_node->job = job1;
            new_node->plan_load = plan_load1;
            new_node->phone = phone1;
            new_node->balance = balance1;
            new_node->balanceriel = balanceriel1;
            new_node->n = n1;
            new_node->pre = NULL;
            new_node->next = NULL;
		    if(head == NULL){
			    head = new_node;
			    tail = new_node;
		    }else{
			    tail -> next = new_node;
			    new_node -> pre = tail;
			    tail = new_node;
		    }
            file>>id1>>pass1>>pin1>>name1>>fname1>>mname1>>suportname1>>address1>>job1>>birday1>>plan_load1>>phone1>>balance1>>balanceriel1>>n1;
        }
        file.close();
    }
}
void pay::information(){
    fstream file;
    int pin1;
    long double balance1;
    long double balanceriel1;
    string id1,pass1,name1,fname1,mname1,suportname1,address1,phone1;
    string birday1,job1,plan_load1;
    int n,n1;
    int year;
    float rate;
    system("cls");
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id1;
    fflush(stdin);
    cout<<"\n\n\t\t Name : ";
    getline(cin,name1);
    cout<<"\n\n Father Name :";
    fflush(stdin);
    getline(cin,fname1);
    cout<<"\n\n Mother Name : ";
    fflush(stdin);
    getline(cin,mname1);
    cout<<"Supporter Name : ";
    fflush(stdin);
    getline(cin,suportname1);
    cout<<"\n\n Address :";
    fflush(stdin);
    getline(cin,address1);
    cout<<"\n\n Job : ";
    fflush(stdin);
    getline(cin,job1);
    cout<<"\n\n Birth Day : ";
    cin>>birday1;
    cout<<"\n\n Plan of load Money :";
    fflush(stdin);
    getline(cin,plan_load1);
    cout<<"\n\n Pin code (5 digit):";
    cin>>pin1;
    cout<<"\n\n Password :";
    cin>>pass1;
    cout<<"\n\n Phone Number :";
    cin>>phone1;
    cout<<"\n\n Current Balance :";
    cin>>balance1;
    cout<<"\n\n Number of year payback :";
    cin>>year;
    if(balance1 >0 && balance1 <=10000){
        rate = 8;
        balance1 = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        balanceriel1 = balance1/(year * 12);
    }else if(balance1 >10000 && balance1 <=50000){
        rate = 7;
        balance1 = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        balanceriel1 = balance1/(year * 12);
    }else if(balance1 >50000 && balance1 <=100000){
        rate = 6;
        balance1 = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        balanceriel1 = balance1/(year * 12);
    }else{
        rate = 5;
        balance1 = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        balanceriel1 = balance1/(year * 12);
    }
    n1 = year *12;
    node *new_node = new node;
    new_node->id = id1;
    new_node->pass = pass1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->mname = mname1;
    new_node->suportname = suportname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->birday = birday1;
    new_node->job = job1;
    new_node->plan_load = plan_load1;
    new_node->phone = phone1;
    new_node->balance = balance1;
    new_node->balanceriel = balanceriel1;
    new_node->n = n1;
    new_node->pre = NULL;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        new_node -> pre = tail;
        tail = new_node;
    }
    file.open("load.txt",ios::app|ios::out);
    file<<id1<<" "<<pass1<<" "<<pin1<<" "<<name1<<" "<<fname1<<" "<<mname1<<" "<<suportname1<<" "<<job1<<" "<<birday1<<" "<<plan_load1<<" "<<address1<<" "<<phone1<<" "<<balance1<<" "<<balanceriel1<<" "<<n1<<"\n";
    file.close();
    cout<<"\n\n Add New User Account create Successfully...";
}
void pay::show_Record(){
    SYSTEMTIME x;
    if(head == NULL){
        cout<<"\n\n\t\t No Record ... ";
    }else{
        node *ptr = head;
        while(ptr != NULL){
            GetSystemTime(&x);
            system("color 0A");
            cout<<"\n\t\t\t\t\t";
            for(int j=0;j<=31;j++)
            cout<<load;
            cout<<"\n";
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            system(" color 0A");
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
            cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
            cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
            cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
            cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
            cout<<"\t\t\t\t\t"<<"    MOTHER NAME : "<< ptr->mname <<endl;
            cout<<"\t\t\t\t\t"<<"    SUPORT NAME : "<< ptr->suportname <<endl;
            cout<<"\t\t\t\t\t"<<"    JOB : "<< ptr->job <<endl;
            cout<<"\t\t\t\t\t"<<"    BIRDAY : "<< ptr->birday <<endl;
            cout<<"\t\t\t\t\t"<<"    PLAN : "<< ptr->plan_load <<endl;
            cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
            cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
            cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
            cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
            cout<<"\t\t\t\t\t"<<"    NUMBER PAYBACK : "<< ptr->n <<endl;
            cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
            ptr = ptr->next;
        }
    }

    cout<<endl;
}
void pay::search(){
    system("cls");
    string  emp_id;
    int count=0;
    SYSTEMTIME x;
    cout<<"\n\n\t\t\t\t Search Record";
    if(head == NULL){
        cout<<"\n\n Linked List is Empty...";
    }else{

        cout<<"\n\n Enter ID to search  : ";
        cin>>emp_id;
        node *ptr = head;
        while(ptr != NULL){
            if(emp_id == ptr ->id){
                GetSystemTime(&x);
                system("color 0A");
                cout<<"\n\t\t\t\t\t";
                for(int j=0;j<=31;j++)
	            cout<<load;
	            cout<<"\n";
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t";
	            for(int j=0;j<=31;j++)
	            cout<<load;
	            cout<<"\n";
	            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	            cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<"    ID : "<< ptr->id <<endl;
                cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< ptr->pass <<endl;
                cout<<"\t\t\t\t\t"<<"    PIN : "<< ptr->pin <<endl;
                cout<<"\t\t\t\t\t"<<"    NAME : "<< ptr->name <<endl;
                cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< ptr->fname <<endl;
                cout<<"\t\t\t\t\t"<<"    MOTHER NAME : "<< ptr->mname <<endl;
                cout<<"\t\t\t\t\t"<<"    SUPORT NAME : "<< ptr->suportname <<endl;
                cout<<"\t\t\t\t\t"<<"    JOB : "<< ptr->job <<endl;
                cout<<"\t\t\t\t\t"<<"    BIRDAY : "<< ptr->birday <<endl;
                cout<<"\t\t\t\t\t"<<"    PLAN : "<< ptr->plan_load <<endl;
                cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
                cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
                cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
                cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->balanceriel <<endl;
                cout<<"\t\t\t\t\t"<<"    NUMBER PAYBACK : "<< ptr->n <<endl;
                cout<<"\t\t\t\t\t"<<"    DATE : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	            cout<<"\t\t\t\t\t";
	            for(int j=0;j<=31;j++)
	            cout<<load;
	            cout<<"\n";
                count++;
                break;
            }
            ptr = ptr -> next;
        }
        if(count == 0)
        cout<<"\n\n ID : "<<emp_id<<" Can't Found...";
    }

}
void pay::update(){
     system("cls");
    fstream file,file1;
    int emp_pin,pin;
    long double emp_balance,balance;
    long double emp_balanceriel,balanceriel;
    string emp_id,t_id,id,emp_pass,pass,emp_name,name,emp_fname,fname,emp_mname,mname,emp_suportname,suportname,emp_address,address,emp_phone,phone;
    string emp_birday,birday,emp_job,job,emp_plan_load,plan_load;
    int emp_n,n;
    int found = 0;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("load.txt",ios::in);
        file1.open("load1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_mname>>emp_suportname>>emp_job>>emp_birday>>emp_plan_load>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel>>emp_n;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\t\t\t===================================\n";
                cout<<"\t\t\t   Setting ALL  Record      "<<endl;
                cout<<"\t\t\t===================================\n";
                cout<<"\n\n\t\t\t User New Password :";
                cin>>emp_pass;
                cout<<"\n\n\t\t\t User New PIN :";
                cin>>emp_pin;

                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                mname = emp_mname;
                suportname = emp_suportname;
                job = emp_job;
                birday = emp_birday;
                plan_load = emp_plan_load;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balanceriel = emp_balanceriel;
                n = emp_n;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<mname<<" "<<suportname<<" "<<job<<" "<<birday<<" "<<plan_load<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balanceriel<<" "<<n<<"\n";
                cout<<"\n\n\t\t\t Adit Record Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<"\t"<<emp_pass<<"\t"<<emp_pin<<"\t"<<emp_name<<"\t"<<emp_fname<<"\t"<<emp_mname<<"\t"<<emp_suportname<<"\t"<<emp_job<<"\t"<<emp_birday<<"\t"<<emp_plan_load<<"\t"<<emp_address<<"\t"<<emp_phone<<"\t"<<emp_balance<<"\t"<<emp_balanceriel<<"\t"<<emp_n<<endl;
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_mname>>emp_suportname>>emp_job>>emp_birday>>emp_plan_load>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel>>emp_n;
        }
        file.close();
        file1.close();
        remove("load.txt");
        rename("load1.txt","load.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void pay::payback(){
     system("cls");
    fstream file,file1;
    int emp_pin,pin;
    long double emp_balance,balance;
    long double emp_balanceriel,balanceriel;
    string emp_id,t_id,id,emp_pass,pass,emp_name,name,emp_fname,fname,emp_mname,mname,emp_suportname,suportname,emp_address,address,emp_phone,phone;
    string emp_birday,birday,emp_job,job,emp_plan_load,plan_load;
    int emp_n,n;
    int found = 0;
    long double withdraw;
    string again;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  3. Setting ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("load.txt",ios::in);
        file1.open("load1.txt",ios::app|ios::out);
        file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_mname>>emp_suportname>>emp_job>>emp_birday>>emp_plan_load>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel>>emp_n;
        while(!file.eof()){
            if(t_id == emp_id){
                cout<<"\t\t\t===================================\n";
                cout<<"\t\t\t   PayBack Money The Load Bank     "<<endl;
                cout<<"\t\t\t===================================\n";
                cout<<"\n\n\t\t\t Current Balance Payback  :";
                cin>>withdraw;
                cout<<"\n\n\t\t\t Do you want to pay balance of load ?(yes/no) : ";
                cin>>again;
                if(withdraw <= emp_balance && withdraw >= emp_balanceriel){
                    emp_balance -= withdraw;
                    emp_n = emp_n -1;
                    cout<<"\n\n\t\t\t Total Payback : "<<withdraw<<" Successful Pay ....";
                    cout<<"\n\n\t\t\t Total Load : "<<emp_balance<<" Thank ......";
                }else{
                     cout<<"\n\n\t\t\t Invalid ....";
                     cout<<"\n\n\t\t\t Total Load : "<<emp_balance<<"\n Thank ......";
                }
                id = emp_id;
                pass = emp_pass;
                pin = emp_pin;
                name = emp_name;
                fname = emp_fname;
                mname = emp_mname;
                suportname = emp_suportname;
                job = emp_job;
                birday = emp_birday;
                plan_load = emp_plan_load;
                address = emp_address;
                phone = emp_phone;
                balance = emp_balance;
                balanceriel = emp_balanceriel;
                n = emp_n;
                file1<<id<<" "<<pass<<" "<<pin<<" "<<name<<" "<<fname<<" "<<mname<<" "<<suportname<<" "<<job<<" "<<birday<<" "<<plan_load<<" "<<address<<" "<<phone<<" "<<balance<<" "<<balanceriel<<" "<<n<<"\n";
                cout<<"\n\n\t\t\t Adit Record Successfully....";
                found++;
            }
            else{
                file1<<emp_id<<"\t"<<emp_pass<<"\t"<<emp_pin<<"\t"<<emp_name<<"\t"<<emp_fname<<"\t"<<emp_mname<<"\t"<<emp_suportname<<"\t"<<emp_job<<"\t"<<emp_birday<<"\t"<<emp_plan_load<<"\t"<<emp_address<<"\t"<<emp_phone<<"\t"<<emp_balance<<"\t"<<emp_balanceriel<<"\t"<<emp_n<<endl;
            }
            file>>emp_id>>emp_pass>>emp_pin>>emp_name>>emp_fname>>emp_mname>>emp_suportname>>emp_job>>emp_birday>>emp_plan_load>>emp_address>>emp_phone>>emp_balance>>emp_balanceriel>>emp_n;
        }
        file.close();
        file1.close();
        remove("load.txt");
        rename("load1.txt","load.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void pay::tableday(){
    system("color 3F");
    int year,day,week;
    int days_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout<<"\n\n Enter Year : ";
    cin>>year;
    if(year%4 == 0)
    days_months[1] = 29;
    day = (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
    system("cls");
    for(int i=0; i<=11; i++){
        cout<<"\n\n\t\t"<<months[i]<<", "<<year;
        cout<<"\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Set\n";
        for(int j=0;j<day;j++){
            cout<<"      ";
        }
        week = day;
        for(int m=1; m<=days_months[i];m++){
            if(m <= 10)
            cout<<"     ";
            else
            cout<<"    ";
            if(week > 6){
                cout<<"\n    "<<m;
                week =0 ;
            }
            else
            cout<<m;
            week++;
        }
        day = week;

    }
}
class manage:public pay{
public:
    void menu();

};
void manage::menu(){
    p:
    system("cls");
    int choice;
    string ch;
    string pin,pass,email;
    cout<<"\n\n\t\t\t Control Panel ";
    cout<<"\n\n 1.Bank Management ";
    cout<<"\n\n 2.ATM Management ";
    cout<<"\n\n 3. Exit ";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            system("cls");
            system("color 0A");
	        cout<<"\n\n\n\n\n\n";
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
            cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int j=0;j<=31;j++)
	        cout<<load;
	        cout<<"\n";
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      |      Detail     |     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	        cout<<"\t\t\t\t\t";
	        for(int i=0;i<=31;i++)
	        cout<<load;
	        cout<<"\n";
            cout<<"\n\n\t\t\t Login Account ";
            cout<<"\n\n\t\t\t Email : ";
            cin>>email;
            cout<<"\n\n\t\t\t Pin code :";
            for(int i=1; i<=5; i++){
                ch = getch();
                pin += ch;
                cout<<"*";
            }
            cout<<"\n\n\t\t\t PassWord : ";
            for(int i=1; i<=5; i++){
                ch = getch();
                pass += ch;
                cout<<"*";
            }
            if(email == "ngimpanha@gmail.com"  && pin == "11111" && pass == "11111"){
                link::menu1();
            }else{
                	system("cls");
                	system("color 0C");
		            cout<<"\n\n\n\n\n\n";
	                cout<<"\t\t\t\t\t";
	                for(int i=0;i<=31;i++)
	                cout<<load;
                    cout<<"\n";
	                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                    cout<<"\t\t\t\t\t"<<load<<"  BANKING MANAGEMENT SYSTEM   "<<load<<endl;
	                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	                cout<<"\t\t\t\t\t";
	                for(int j=0;j<=31;j++)
	                cout<<load;
	                cout<<"\n";
                    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	                cout<<"\t\t\t\t\tPlease Enter Correct ID and PIN\n";
	                cout<<"\t\t\t\t\t Your E-mail,Pin,Password is Wrong";
     	            cout<<"\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     	            _getch();

            }

        }break;
        case 2:{
            pay::menu2();
        }break;
        case 3:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
int main(){
    manage m;
    m.menu();
}





























