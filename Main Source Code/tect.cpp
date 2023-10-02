#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank{
protected:
    int pin;
    float balance;
    string id,pass,name,fname,address,phone;
public:
    void menu();
    void back_managment();
    void atm_mangment();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
};
void bank::menu(){
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
            cout<<"\n\n\t\t\t Login Account ";
            cout<<"\n\n Email : ";
            cin>>email;
            cout<<"\n\n Pin code :";
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
                back_managment();
            }else{
                cout<<"\n\n Your E-mail , Pin & Password is Wrong ... ";
            }
        }break;
        case 2:{
            atm_mangment();
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
void bank::back_managment(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t Management System ";
    cout<<"\n\n 1. New User  ";
    cout<<"\n\n 2. Already User  ";
    cout<<"\n\n 3. Deposit option ";
    cout<<"\n\n 4 . Withdraw option ";
    cout<<"\n\n 5 . Transfer option ";
    cout<<"\n\n 6 . payment option ";
    cout<<"\n\n 7 . Search User Record ";
    cout<<"\n\n 8 . Edit User Record ";
    cout<<"\n\n 9 . Delete User Record ";
    cout<<"\n\n 10 . Show User Records ";
    cout<<"\n\n 11 . Payment All Records ";
    cout<<"\n\n 12 . Go Back ";
    cout<<"\n\n  Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            new_user();
        }break;
        case 2:{
            already_user();
        }break;
        case 3:{
            deposit();
        }break;
        case 4:{
            withdraw();
        }break;
        case 5:{
            transfer();
        }break;
        case 6:{
        }break;
        case 7:{
        }break;
        case 8:{
        }break;
        case 9:{
        }break;
        case 10:{
        }break;
        case 11:{
        }break;
        case 12:{
            menu();
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
void bank::atm_mangment(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t Management System ";
    cout<<"\n\n 1. User Login & check Balance  ";
    cout<<"\n\n 2. Withdraw Amount  ";
    cout<<"\n\n 3. Account Detailes ";
    cout<<"\n\n 4 . Go Back";
    cout<<"\n\n  Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
        }break;
        case 2:{
        }break;
        case 3:{
        }break;
        case 4:{
            menu();
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
void bank::new_user(){
    p:
    system("cls");
    fstream file;
    int p;
    float b;
    string n,f,pa,a,ph,i;
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id;
    cout<<"\n\n\t\t Name : ";
    cin>>name;
    cout<<"\n\n Father Name :";
    cin>>fname;
    cout<<"\n\n Address :";
    cin>>address;
    cout<<"\n\n Pin code (5 digit):";
    cin>>pin;
    cout<<"\n\n Password :";
    cin>>pass;
    cout<<"\n\n Phone Number :";
    cin>>phone;
    cout<<"\n\n Current Balance :";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        file.close();
    }
    else{
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        while(!file.eof()){
            if(i == id){
                cout<<"\n\n User ID Already Exit...";
                getch();
                goto p;
            }
            file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        file.close();
    }
    cout<<"\n\n Add New User Account create Successfully...";
}
void bank::already_user(){
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"\n\n\t\t\t Already User Account ";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File opening Error... ";
    }else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
                if(t_id == id){
                    system("cls");
                    cout<<"\n\n Already User Account ";
                    cout<<"\n\n User ID : "<<id<<"  Pin Code : "<<pin<<"   Password: "<<pass;
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n can not found ...";
        }
    }
}
void bank::deposit(){
    fstream file,file1;
    string t_id;
    float dep;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\t\t Deposit Amount option ";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File opening Error... ";
    }else{
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n Enter Amount For Deposit : ";
                    cin>>dep;
                    balance += dep;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                    found++;
                    cout<<"\n\n\t\t\t You Amount "<<dep<<"  Successfully Deposit....";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0){
            cout<<"\n\n can not found ...";
        }
    }
}
void bank::withdraw()
{
    fstream file,file1;
    string t_id;
    float withdraw;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\t\t Withdraw Amount option ";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n File opening Error... ";
    }
    else
    {
        cout<<"\n\n User ID : ";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
                if(t_id == id)
                {
                    cout<<"\n\n Enter Amount For withdraw : ";
                    cin>>withdraw;
                    if(withdraw < balance)
                    {
                        balance -= withdraw;
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                        cout<<"\n\n\t\t\t You Amount "<<withdraw<<"  Successfully Withdraw....";
                        cout<<"\n\n\t\t\t You Amount "<<balance<<"  is less ...";
                    }
                    else
                    {
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                        cout<<"\n\n\t\t\t Your Current Balance"<<balance<<"  is Less...";
                    }
                    found++;
                }
                else
                {
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
        {
            cout<<"\n\n can not found ...";
        }

    }
}
void bank::transfer(){
    fstream file,file1;
    system("cls");
    string s_id,r_id;
    float amount;
    int found = 0;
    cout<<"\n\n\t\t\t Payment Transfer option ";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Opening Error...";
    }else{
        cout<<"\n\n Enter User ID for Transection : ";
        cin>>s_id;
        cout<<"\n\n Reciver User ID for Transfer ";
        cin>>r_id;
        cout<<"Enter Transfer Amount : ";
        cin>>amount;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(s_id == id){
                found++;
            }else if(r_id == id){
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 2){

            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(s_id == id ){
                    balance -= amount;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }else if(r_id == id ){
                     balance += amount;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            cout<<"\n\n\t\t\t Transfer Successfully...";

        }else{
            cout<<"\n\n\t\t\t Both Transction User ID's Invalid...";
        }
    }
}
int main(){
    bank obj;
    obj.menu();
}
