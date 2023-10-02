#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
//design function
void ccolor(int clr);
void loadingScreen();
void pwellcome();
void cls();
void line(int l);
void tap(int t);
void mainMenu();
//void adminAccount();
void adminChoice();
int b=0;

//Professor part=>Leabheng
class Node
{
public:
    string name;
    int ID;
    string gender;
    string phone_number;
    string address;
    string email;
    string password;
    string department;
    string course;
    Node *next_add;
};
class Linked_List{
public:
    Node *head=NULL;

    void Insert_prof();
    void Search_prof();
    void Count_prof();
    void Update_prof();
    void Delete_prof();
    void Display_prof();
};

//kimhong
class Array_Student{
public:
    int stu_id;
    int num,add,position;
    char stu_name[30];
    char stu_gender[10];
    char stu_mobile[30];
    char stu_email[50];
    char stu_address[30];
    char stu_password[10];
    char stu_department[30];
public:
    void create_stu_list();
    void display_stu_list();
    void add_stu();
    void update_stu();
    void delete_stu();
    void search_stu();
    void sort_stu();
};
//Tola
struct node{
    struct couresinformation{
        int numcoures;
        string namecoures;
        int numCredit;
        int numhours;
        int year;
        string major;
    };
    couresinformation s1;
    node *left;
    node *right;
};
struct Department{
    string major;
    Department * next;
};
struct Stack{
    int n;
    Department *top;
};
node *Created(node *newnode,string major, int year, int numcoures, string namecoures, int numCredit,int numhours);
Stack * createEmptyStack();
void outputcouresinfo(node *root);
void addmajor(Stack *s , string newmajor);
void deletemajor(Stack *s);
void display(Stack*s);

//Mouyhong
void login();
void registration();
void forgot();

//kimhong
int main(){
    loadingScreen();
    cls();
    pwellcome();
    Sleep(300);
    cls();
    Linked_List obj;
    Array_Student Obj;
    int option;
    char adminCS;
    int adminOp;
    int adminOp1;
    int adminOp2;
    int adminOp3;
    int adminOp4;
    int adminOp5;
    int adminOp6;
    int option1;//registration

    do{
        mainMenu();
        cout<<"Enter your option:";
        cin>>option;
        cls();
        switch(option){
        case 1:
            do{
                cls();
                tap(3); cout<<"1. Registration"<<endl;
                tap(3); cout<<"2. Log in"<<endl;
                tap(3); cout<<"3. Main menu"<<endl;
                cout<<"Enter your option: "; cin>>option1;
                cls();
                switch(option1){
                case 1:
                    cls();
                    registration();
                break;
                case 2:
                    //cls();
                    login();
                    if(b==1){
                        cls();
                        admin_choice:
                        adminChoice();
                        cout<<"Enter your option:";cin>>adminOp;
                        cls();
                        switch(adminOp){
                        case 1:
                            a:
                            tap(3); cout<<"1. Set professor information"<<endl;
                            tap(3); cout<<"2. Set Student information"<<endl;
                            tap(3); cout<<"3. Set department information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp1;
                            cls();
                            if(adminOp1==1){
                                cls();
                                obj.Insert_prof();
                                goto admin_choice;
                                cls();
                            }else if(adminOp1==2){
                                cls();
                                Obj.create_stu_list();

                                goto admin_choice;
                                cls();
                            }else if(adminOp1==3){
                                //addmajor();
                            }else{
                               tap(3); cout<<"Invalid choice..."<<endl;
                            }
                        break;
                        case 2:
                            cls();
                            tap(3); cout<<"1. Add professor information"<<endl;
                            tap(3); cout<<"2. Add student information"<<endl;
                            tap(3); cout<<"3. Add department information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp2;
                            cls();
                            if(adminOp2==2){
                                cls();
                                Obj.add_stu();
                                goto admin_choice;
                                cls();
                            }else if(adminOp2==1){
                                cls();
                                obj.Insert_prof();
                                goto admin_choice;
                                cls();

                            }else{
                                tap(3);cout<<"Invalid choice..."<<endl;
                            }
                        break;
                        case 3:
                            cls();
                            tap(3); cout<<"1. Update professor information"<<endl;
                            tap(3); cout<<"2. Update student information"<<endl;
                            tap(3); cout<<"3. Update department information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp3;
                            cls();
                            if(adminOp3==1){
                                cls();
                                obj.Update_prof();
                                goto admin_choice;
                                cls();
                            }else{
                                tap(3);cout<<"Invalid choice..."<<endl;
                            }
                        break;
                        case 4:
                            cls();
                            tap(3); cout<<"1. Delete professor information"<<endl;
                            tap(3); cout<<"2. Delete department information"<<endl;
                            tap(3); cout<<"3. Delete student information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp4;
                            cls();
                            if(adminOp4==1){
                                cls();
                                obj.Delete_prof();
                                goto admin_choice;
                                cls();
                            }else if(adminOp4==2){
                                //deletemajor();
                            }else{
                                tap(3); cout<<"Invalid choice..."<<endl;
                            }
                        break;
                        case 5:
                            cls();
                            tap(3); cout<<"1. View professor information"<<endl;
                            tap(3); cout<<"2. View student information"<<endl;
                            tap(3); cout<<"3. View department information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp5;
                            cls();
                            if(adminOp5==1){
                                cls();
                                obj.Display_prof();
                                goto admin_choice;
                                cls();
                            }else if(adminOp5==2){
                                cls();
                                Obj.display_stu_list();
                                goto admin_choice;
                                cls();
                            }else if(adminOp5==3){
                                //display(Stack*s);
                            }else{
                                tap(3); cout<<"Invalid choice..."<<endl;
                            }
                        break;
                        case 6:
                            cls();
                            tap(3); cout<<"1. Search professor information"<<endl;
                            tap(3); cout<<"2. Search student information"<<endl;
                            tap(3); cout<<"3. Search department information"<<endl;
                            cout<<"Enter your option: "; cin>>adminOp6;
                            cls();
                            if(adminOp6==1){
                                cls();
                                obj.Search_prof();
                                goto admin_choice;
                                cls();
                            }else{
                                tap(3); cout<<"Invalid choice..."<<endl;
                            }
                        }
                break;

                    }else{
                        tap(3); cout<<"Incorrect password...";
                    }
                }

            }while(option1!=3);

        }
    }while(option!=0);


   return 0;
}


void cls(){
    system("cls");
}
//for line
void line(int l){
    for(int i=0;i<l;i++){
        cout<<"\n";
    }
}
//for tap
void tap(int t){
    for(int i=0;i<t;i++){
        cout<<"\t";
    }
}

void ccolor(int clr){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsole TextAttribute(hConsole,clr);
//the above code display colorful background.if you want colorful then you can remove the above comment but not the code, only comment//
}

void pwellcome(){
    ccolor(26);
    char welcome[50] = "W E L C O M";
    char welcome2[50] = "T O  O U R";
    char welcome3[50] = "U N I V E R S I T Y";
    char welcome4[50] = "M A N A G E M E N T  S Y S T E M";
    cout<<"\n\n\n\n\n\t\t\t";
    for(int wlc = 0;wlc<strlen(welcome);wlc++){
        cout<<welcome[wlc];
        Sleep(50);
    }
    ccolor(26);
    cout<<"\n\n\t\t\t\t ";
    for(int wlc2=0; wlc2<strlen(welcome2);wlc2++){
        cout<<welcome2[wlc2];
        Sleep(50);
    }
    ccolor(26);
    cout<<"\n\n\n\t\t\t ";
    for(int wlc3=0;wlc3<strlen(welcome3);wlc3++){
        if(welcome3[wlc3]!='D'){
            cout<<welcome3[wlc3];
        }else{
            cout<<welcome3[wlc3];
        }
        Sleep(50);
    }
    ccolor(26);
    cout<<"\n\n\n\t\t\t\t ";
    for(int wlc3=0;wlc3<strlen(welcome4);wlc3++){
        if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
            cout<<welcome4[wlc3];
        }else{
            cout<<welcome4[wlc3];
        }
        Sleep(50);
    }
    ccolor(26);
}

void loadingScreen(){
    for(int i=15;i<=100;i+=5){

        cls();

        cout<<"\n\n\n\n\n\n\n\t\t\t\t";
        cout<<i<<" % "<<"Loading...\n\n\t\t";
        cout<<" ";
        for(int j=0;j<i;j+=2){
            ccolor(160+j);
            cout<<" ";
            ccolor(26);
        }
        Sleep(100);
        if(i==90 || i==50 || i==96 || i==83){
            Sleep(100);
        }
    }
}

void mainMenu(){
    line(5); tap(3); cout<<">> 1. Admin Panel"; Sleep(400);
    line(2); tap(3); cout<<">> 2. Registration"; Sleep(400);
    line(2); tap(3); cout<<">> 3. Professor Data"; Sleep(400);
    line(2); tap(3); cout<<">> 4. Student Data"; Sleep(400);
    line(2); tap(3); cout<<">> 0. Exit"; Sleep(400);
    line(1);
}
//Professor Part=>heng
void Linked_List::Insert_prof(){
        string n,g,phn,add,em,pass,dep,cou;
        int id;
        cout<<"\nEnter Name: ";
        fflush(stdin);
        getline(cin,n);
        cout<<"\nEnter ID: ";
        cin>>id;
        cout<<"\nEnter Gender: ";
        cin>>g;
        cout<<"\nEnter Phone Number: ";
        cin>>phn;
        cout<<"\nEnter Address: ";
        fflush(stdin);
        getline(cin,add);
        cout<<"\nEnter Email: ";
        cin>>em;
        cout<<"\nEnter Password: ";
        cin>>pass;
        cout<<"\nEnter Department: ";
        fflush(stdin);
        getline(cin,dep);
        cout<<"\nEnter Course: ";
        fflush(stdin);
        getline(cin,cou);
        Node *new_node=new Node;
        new_node ->name=n;
        new_node ->ID=id;
        new_node ->gender=g;
        new_node ->phone_number=phn;
        new_node ->address=add;
        new_node ->email=em;
        new_node ->password=pass;
        new_node ->department=dep;
        new_node ->course=cou;
        new_node -> next_add =NULL;
        if(head==NULL)
        {
            head=new_node;
        }
        else{
            Node *ptr=head;
            while(ptr->next_add != NULL)
            {
                ptr=ptr->next_add;
            }
            ptr->next_add=new_node;
        }
        cout<<"\n\n New Node Inserted Successfully...";
        getch();
        cls();
}

void Linked_List::Search_prof(){
    if(head==NULL){
            cout<<"\n\n Linked List is Empty..";
        }
        else{
            int id,found=0;
            cout<<"\n\n Enter ID For Search: ";
            cin>>id;
            Node *ptr =head;
            while(ptr !=NULL)
            {
                if(id==ptr->ID){
                    cout<<"\n\n Name:"<<ptr->name;
                    cout<<"\n\n ID:"<<ptr->ID;
                    cout<<"\n\n Gender:"<<ptr->gender;
                    cout<<"\n\n Phone Number:"<<ptr->phone_number;
                    cout<<"\n\n Address:"<<ptr->address;
                    cout<<"\n\n Email:"<<ptr->email;
                    cout<<"\n\n Password:"<<ptr->password;
                    cout<<"\n\n Department:"<<ptr->department;
                    cout<<"\n\n Course:"<<ptr->course;
                    found++;
                }
                ptr=ptr->next_add;
            }
            if(found==0){
                cout<<"\n\n Search ID "<<id<<"Can't Found...";
            }
        }
        getch();
        cls();
}

void Linked_List::Count_prof(){
     if(head==NULL){
            cout<<"\n\n Linked List is Empty..";
        }
        else{
            int c=0;
            Node *ptr =head;
            while(ptr !=NULL){
                c++;
                cout<<"\n\n#Name:"<<ptr->name;
                cout<<"\t #Gender:"<<ptr->gender;
                ptr=ptr->next_add;
            }
            cout<<"\n\n Total No. of Professors: "<<c;
        }
        getch();
        cls();
}

void Linked_List::Update_prof(){
    if(head==NULL){
            cout<<"\n\n Linked List is Empty..";
        }
        else{
            int id,found=0;
            cout<<"\n\n Enter ID For Updation: ";
            cin>>id;
            Node *ptr =head;
            while(ptr !=NULL)
            {
                if(id==ptr->ID){
                    cout<<"\nEnter New Name: ";
                    fflush(stdin);
                    getline(cin,ptr->name);
                    cout<<"\nEnter New ID: ";
                    cin>>ptr->ID;
                    cout<<"\nEnter New Gender: ";
                    cin>>ptr->gender;
                    cout<<"\nEnter New Phone Number: ";
                    cin>>ptr->phone_number;
                    cout<<"\nEnter New Address: ";
                    fflush(stdin);
                    getline(cin,ptr->address);
                    cout<<"\nEnter New Email: ";
                    cin>>ptr->email;
                    cout<<"\nEnter New Password: ";
                    cin>>ptr->password;
                    cout<<"\nEnter New Department: ";
                    fflush(stdin);
                    getline(cin,ptr->department);
                    cout<<"\nEnter New Course: ";
                    fflush(stdin);
                    getline(cin,ptr->course);
                    found++;
                }
                ptr=ptr->next_add;
            }
            if(found==0){
                cout<<"\n\n Search ID "<<id<<"Can't Found...";
            }
        }
       getch();
       cls();
}

void Linked_List::Delete_prof(){
     if(head==NULL){
            cout<<"\n\n Linked List is Empty..";
        }
        else{
            int id,found=0;
            cout<<"\n\n Enter ID For Deletion: ";
            cin>>id;
            if(id==head->ID){
                Node *ptr=head;
                head=head->next_add;
                cout<<"\n\n Record Deleted Successfully...";
                found++;
                delete ptr;
            }
            else{
                Node *pre=head;
                Node *ptr=head->next_add;
                while(ptr !=NULL){
                    if(id==ptr->ID){
                        pre->next_add=ptr->next_add;
                        cout<<"\n\n Record Deleted Successfully...";
                        found++;
                        delete ptr;
                        break;
                    }
                    pre=ptr;
                    ptr=ptr->next_add;
                }
            }
            if(found==0){
                cout<<"\n\n Delete ID "<<id<<"Can't Found...";
            }
        }
        getch();
        cls();
}

void Linked_List::Display_prof(){
    if(head==NULL){
            cout<<"\n\n Linked List is Empty..";
        }
        else{
            Node *ptr =head;
            while(ptr !=NULL)
            {
                cout<<"\n\n Name:"<<ptr->name;
                cout<<"\n\n ID:"<<ptr->ID;
                cout<<"\n\n Gender:"<<ptr->gender;
                cout<<"\n\n Phone Number:"<<ptr->phone_number;
                cout<<"\n\n Address:"<<ptr->address;
                cout<<"\n\n Email:"<<ptr->email;
                cout<<"\n\n Password:"<<ptr->password;
                cout<<"\n\n Department:"<<ptr->department;
                cout<<"\n\n Course:"<<ptr->course;
                cout<<"\n***********************************";
                ptr=ptr->next_add;
            }
        }
        getch();
        cls();
}
//Mouyhong=>registration
void login(){
    b=1;
    int a=0;
    string user,pw,u,p;
    cout<<"Enter the user name: ";
    cin>>user;
    cout<<"Enter password: ";
    cin>>pw;
    ifstream read("username.txt");
    while(read>>u>>p)
    {
        if(u==user && p==pw)
        {
            a=1;
            break;
        }
    }
    read.close();
    if(a=1)
    {
        cout<<"Login successfull"<<endl;
    }
    else
    {
        cout<<"Login error."<<endl;
    }
    getch();
    cls();
}
void registration(){
    int a=0;
    string user,pw,u,p;
    system("cls");
    cout<<"Enter username: ";
    cin>>user;
    ofstream write("username.txt",ios::app);
    ifstream read("username.txt");

    while(read>>u>>p)
    {
        if(u==user)
        {
           a=1;
           break;
        }
    }
    if(a==1)
    {
        cout<<"Username is already taken."<<endl;
    }
    else
    {
        cout<<"Enter password: ";
        cin>>pw;
        write<<user<<" "<<pw<<endl;
        cout<<"Registration is successfull."<<endl;
    }
    write.close();
    getch();
    cls();
}

void forgot(){
        int choice;
    system("cls");
    cout<<" 1.Search your account by username\n 2.Search your account by password\n 3.Main menu\n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            int a=0;
            string su,u,p;
            cout<<"Enter your remember username: ";
            cin>>su;
            ifstream read("username.txt");
            while(read>>u>>p)
            {
                if(su==u)
                {
                    a=1;
                    break;
                }
            }
            read.close();
            if(a==1)
            {
                cout<<"Congrats!! account found\nPassword is : "<<p<<endl;
            }
            else
            {
                cout<<"Sorry, account not found"<<endl;
            }
            break;
        }
    case 2:
        {
            int a=0;
            string sp,u,p;
            cout<<"Enter your remember password: ";
            cin>>sp;
            ifstream read("username.txt");

            while(read>>u>>p)
            {
                if(sp==p)
                {
                    a=1;
                    break;
                }
            }
            read.close();
            if(a==1)
            {
               cout<<"Congrats!! account found\nUsername is : "<<u<<endl;
            }
            else
            {
                cout<<"Sorry,account not found"<<endl;
            }
            break;
        }
    case 3:
        {
            cout<<endl;
            main();
            break;
        }
    default:
        {
            cout<<"Wrong choice selection.Press a key to try again!"<<endl;
            forgot();
        }
    }
    getch();
    cls();
}
//tola=>department
node *Created(node *newnode,string major, int year, int numcoures, string namecoures, int numCredit,int numhours){
    if (newnode==NULL){
        newnode = new node;
        newnode->s1.major = major;
        newnode->s1.year = year;
        newnode->s1.numcoures=numcoures;
        newnode->s1.namecoures = namecoures;
        newnode->s1.numCredit = numCredit;
        newnode->s1.numhours = numhours;
        newnode->left = NULL;
        newnode->right = NULL;
    }   if ( major> newnode->s1.major ){
        newnode->right = Created(newnode->right, major, year,numcoures, namecoures, numCredit, numhours);
    }   if ( major< newnode->s1.major){
        newnode->left =Created(newnode->left,major, year,numcoures, namecoures, numCredit, numhours);
    }
    return newnode;
}
void outputcouresinfo(node *root){
      int numcoures;
    if (root!=NULL){
        cout<<"\n";
        cout<<"\n\t\tThe coures for student study for each year:\n ";
        cout<<"Major: "<<root->s1.major<<"\n";
        cout<<"Year: "<<root->s1.year<<"\n";
        cout<<"number of coures: "<<root->s1.numcoures<<"\n";
        for(int j=0;j<numcoures;j=j+1){
        cout<<"Name coures: "<<root->s1.namecoures<<"\n";
        cout<<"Number of credit: "<<root->s1.numCredit<<"\n";
        cout<<"Number of hours: "<<root->s1.numhours<<"\n";
        cout<<"\t";
        }
        outputcouresinfo(root->left);
        outputcouresinfo(root->right);
    }
    getch();
    cls();
}
Stack * createEmptyStack(){
    Stack *s;
    s=new Stack;
    s->n=0;
    s->top=NULL;
    return s;
}
void addmajor(Stack *s , string newmajor){
    Department *newnode;
    newnode= new Department;
    newnode->major= newmajor;
    if(s->n==0){
        newnode->next=NULL;
        s->top=newnode;
        s->n= s->n+1;
    }else{
        newnode->next=s->top;
        s->top=newnode;
        s->n=s->n+1;
    }
    getch();
    cls();
}
void deletemajor(Stack *s){
    if(s->n==0){
        cout<<"Can not delete! List is empty\n";
    }else{
        Department *t;
        t=s->top;
        s->top = s->top->next;
        cout<<"\n\nDelete some majors: "<<t->major<<"\n";
        delete t;
        s->n= s->n-1;
    }
    getch();
    cls();
}
void display(Stack*s){
    string departmentuni;
    Department *newnode;
    newnode = s->top;
    cout<<"\t\t*************************************\n\t\t\tMajor in this department:\n\t\t*************************************\n\t\t";
    while(newnode!=NULL){
        cout<<newnode->major<<"      ";
        newnode = newnode->next;
    }
    cout<<"\n";
    getch();
    cls();
}
//Student part
void Array_Student::create_stu_list(){
    Array_Student stu[1000];
    cout<<"How many student you want to create?=> ";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\t\t****************Student #"<<i+1<<"****************"<<endl;
        cout<<"Enter student ID: "; cin>>stu[i].stu_id;
        fflush(stdin);
        cout<<"Enter student name: ";
        cin.getline(stu[i].stu_name,30);
        cout <<"Enter student gender: ";
        cin >>stu[i].stu_gender;
        cout <<"Enter student mobile: ";
        cin >>stu[i].stu_mobile;
        cout <<"Enter student email: ";
        cin >>stu[i].stu_email;
        cout <<"Enter password: ";
        cin >>stu[i].stu_password;
        fflush(stdin);
        cout <<"Enter student address: ";
        cin.getline(stu[i].stu_address,30);
        cout <<"Enter student department: ";
        cin.getline(stu[i].stu_department,30);
    }
    cout<<"\t\tCreated Successfully..."<<endl;
    getch();
    cls();
}
void Array_Student::display_stu_list(){

    cout<<"\t\t****************Student List****************"<<endl;
    Array_Student stu[1000];
    for(int i=0;i<num;i++){
        cout<<"=>Student "<<i+1<<endl;
        cout<<"ID: "<<stu[i].stu_id<<endl;
        cout<<"name: "<<stu[i].stu_name<<endl;
        cout<<"Gender: "<<stu[i].stu_gender<<endl;
        cout<<"Phone number: "<<stu[i].stu_mobile<<endl;
        cout<<"Email: "<<stu[i].stu_email<<endl;
        cout<<"Password: "<<stu[i].stu_password<<endl;
        cout<<"Address: "<<stu[i].stu_address<<endl;
        cout<<"Department: "<<stu[i].stu_department<<endl;
    }
    cout<<endl;
    getch();
    cls();
}
void Array_Student::add_stu(){
     Array_Student stu[1000];
    cout<<"How many student number do you want to add?=>";
    cin>>add;
    for(int i=num;i<add+num;i++){
        cout<<"Enter student ID: "; cin>>stu[i].stu_id;
        fflush(stdin);
        cout<<"Enter student name: ";
        cin.getline(stu[i].stu_name,30);
        cout <<"Enter student gender: ";
        cin >>stu[i].stu_gender;
        cout <<"Enter student mobile: ";
        cin >>stu[i].stu_mobile;
        cout <<"Enter student email: ";
        cin >>stu[i].stu_email;
        cout <<"Enter password: ";
        cin >>stu[i].stu_password;
        fflush(stdin);
        cout <<"Enter student address: ";
        cin.getline(stu[i].stu_address,30);
        cout <<"Enter student department: ";
        cin.getline(stu[i].stu_department,30);
    }
    num = num + add;
    cout<<"Add successfully..."<<endl;
    getch();
    cls();
}
void adminChoice(){
    line(5); tap(3); cout<<">> 1. Set Information"; Sleep(400);
    line(2); tap(3); cout<<">> 2. Add more Information"; Sleep(400);
    line(2); tap(3); cout<<">> 3. Update Information"; Sleep(400);
    line(2); tap(3); cout<<">> 4. Delete Information"; Sleep(400);
    line(2); tap(3); cout<<">> 5. View all Information"; Sleep(400);
    line(2); tap(3); cout<<">> 6. Search Information"; Sleep(400);
    line(2); tap(3); cout<<">> 0. Turn back"; Sleep(400);
    line(1);
}
