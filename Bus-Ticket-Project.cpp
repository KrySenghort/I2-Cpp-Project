#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
//Bunra
class Booking
{
private:
    struct Node
    {
        int id;
        string name,price,quality;
        Node *next_add;
    };

public:
    Node *head=NULL;

    void menu();
    void insert();
    void search();
    void update();
    void del();
    void sort();
    void show();


};
void Booking::menu()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t===============================================";
    cout<<"\n\n\t\t========Manu and information of ticket===========";
    cout<<"\n\n\t\t===============================================";
    cout<<"\n\n 1.Insert New Record";
    cout<<"\n\n 2. Search Record ";
    cout<<"\n\n 3. Update Record";
    cout<<"\n\n 4. Delete Record";
    cout<<"\n\n 5. Show all Record";
    cout<<"\n\n 6. Exit";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            sort();
            show();
            break;
        case 6:
            exit(0);
        default:
            cout<<"\n\n Invalid Choice.. Please Try Again......";
    }
    getch();
    goto p;
}
void Booking::insert()
{
    system("cls");
    cout<<"\n\n\t\t================================================";
    cout<<"\n\n\t\t========Manu and information of ticket=============";
    cout<<"\n\n\t\t================================================";
    Node *new_node = new Node;
    cout<<"\n\n Items ID : ";
    cin>>new_node ->id;
    cout<<"\n\n Name : ";
    cin>>new_node->name;
    cout<<"\n\n Price :";
    cin>>new_node ->price;
    cout<<"\n\n Quality : ";
    cin>>new_node->quality;
    new_node->next_add =NULL;
    if(head ==NULL)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while(ptr -> next_add !=NULL)
        {
            ptr =ptr -> next_add;
        }
        ptr->next_add = new Node;
    }
    cout<<"\n\n\t\t New Item Insert Successfully.....";

}
void Booking:: search()
{
    int t_id, found =0;
    system("cls");
    cout<<"\n\n\t\t================================================";
    cout<<"\n\n\t\t========Manu and information of ticket===========";
    cout<<"\n\n\t\t================================================";
    if(head == NULL)
    {
        cout<<"\n\n Listed is Empty......";
    }
    else
    {
        cout<<"\n\n Items ID : ";
        cin>>t_id;
        Node *ptr = head;
        while(ptr !=NULL)
        {
            if(t_id== ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t================================================";
                cout<<"\n\n\t\t========Manu and information of ticket===========";
                cout<<"\n\n\t\t================================================";
                cout<<"\n\n Item : "<<ptr->id;
                cout<<"\n\n Item Name: "<<ptr->name;
                cout<<"Price  : "<<ptr->price;
                cout<<"Quality  : "<<ptr->quality;
                found++;
            }
            ptr =ptr->next_add;
        }
        if(found ==0)
        {
            cout<<"\n\n Book ID is Invalid.....";
        }
    }
}
void Booking:: update()
{
    system("cls");
    int t_id, found =0;
    cout<<"\n\n\t\t================================================";
    cout<<"\n\n\t\t========Manu and information of ticket===============";
    cout<<"\n\n\t\t================================================";
    if(head==NULL)
    {
        cout<<"\n\n  listed is Empty.....";
    }else
    {
        cout<<"\n\n Item ID : ";
        cin>>t_id;
        Node *ptr = head;
        while(ptr !=NULL){

            if(t_id==ptr->id)
            {
                system("cls");
                cout<<"\n\n\t\t================================================";
                cout<<"\n\n\t\t========Manu and information of ticket===============";
                cout<<"\n\n\t\t================================================";
                cout<<"\n\n Item ID : ";
                cin>>ptr->id;
                cout<<"\n\n Item Name: ";
                cin>>ptr->name;
                cout<<"Price  : ";
                cin>>ptr->price;
                cout<<"Quality  : ";
                cin>>ptr->quality;
                found++;
                cout<<"\n\n\t\t\tUpdated Item Successfully.....";
            }
            ptr=ptr ->next_add;

        }
        if(found==0)
        {
            cout<<"\n\n Item ID is Invalid.... ";
        }

    }
}
void Booking:: del()
{
    system("cls");
    int t_id, found =0;
    cout<<"\n\n\t\t================================================";
    cout<<"\n\n\t\t========Manu and information of ticket===========";
    cout<<"\n\n\t\t================================================";
    if(head==NULL)
    {
        cout<<"\n\n  list is Empty.....";
    }else
    {
        cout<<"\n\n Item ID : ";
        cin>>t_id;
        if(t_id==head ->id)
        {
            Node *ptr = head;
            head = head ->next_add;
            delete ptr;
            cout<<"\n\n Delete Items Successfully......";
            found++;
        }
        else
        {
            Node *pre = head;
            Node *ptr=head;
            while(ptr !=NULL)
            {
                if(t_id ==ptr ->id)
                {
                    pre ->next_add = ptr->next_add;
                    delete ptr;
                    cout<<"\n\n Delete Item Successfully.....";
                    found++;
                    break;
                }
                pre =ptr;
                ptr =ptr ->next_add;
            }
        }
        if(found ==0)
        {
            cout<<"\n\n Item ID is Invalid....";
        }
    }

}
void Booking::sort()
{
    if(head==NULL)
    {
        cout<<"\n\n  listed is Emtpy....";
        getch();
        menu();
    }

    int count=0, t_id;
    string t_name,t_price,t_quality;
    Node *ptr = head;
    while(ptr !=NULL)
    {
        count++;
        ptr =ptr ->next_add;
    }
    for(int i=1;i<=count;i++)
    {
        Node *ptr = head;
        for(int j=1;j<count;j++)
        {
            if((ptr->id)> (ptr->next_add ->id))
            {

                t_id=ptr->id;
                t_name =ptr ->name;
                t_price=ptr ->price;
                t_quality = ptr -> quality;

                ptr ->id=ptr->next_add->id;
                ptr ->name=ptr->next_add->name;
                ptr ->price=ptr->next_add->price;
                ptr ->quality=ptr->next_add->quality;

                ptr->next_add->id=t_id;
                ptr->next_add->name=t_name;
                ptr->next_add->price=t_price;
                ptr->next_add->quality=t_quality;
            }
            ptr= ptr ->next_add;
        }

    }
}
void Booking::show()
{
    system("cls");
    cout<<"\n\n\t\t================================================";
    cout<<"\n\n\t\t==========Manu and information of ticket=============";
    cout<<"\n\n\t\t================================================";
    Node *ptr = head;
    while(ptr !=NULL)
    {
        cout<<"\n\n Item ID : "<<ptr->id;
        cout<<"\n\n Item Name: "<<ptr->name;
        cout<<"\n\n Price : "<<ptr->price;
        cout<<"\n\n Quality : "<<ptr->quality;
        cout<<"\n\n\n =================================";
        ptr =ptr->next_add;
    }

}

int k=7,r=0,flag=0;
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct date
{
    int mm,dd,yy;
};

ofstream fout;
ifstream fin;
class ticket
{
    int itemno;
    char name[25];
    date d;

public:
    void add()
    {
        cout<<"\n\n\tTicket No: ";
        cin>>itemno;
        cout<<"\n\n\tName of the Movie: ";
        cin>>name;
        cout<<"\n\n\tReleasing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }

    void show()
    {
        cout<<"\n\tTicket No: ";
        cout<<itemno;
        cout<<"\n\n\tName of the Movie: ";
        cout<<name;
        cout<<"\n\n\tReleasing Date : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }

    void report()
    {
        gotoxy(3,k);
        cout<<itemno;
        gotoxy(13,k);

        cout<<name;
    }

    int retno()
    {
        return(itemno);

    }

};


class amount: public ticket
{
    float price,qty,netamt;
public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt()
    {
        return(netamt);
    }
}amt;


void amount::calculate()
{
    netamt=qty*price;
}

void amount::add()
{
    ticket::add();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    calculate();
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}



void amount::show()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    ticket::show();
    cout<<"\n\n\tNet Amount: ";
    cout<<netamt;
    fin.close();
}

void amount::report()
{
    ticket::report();
    gotoxy(23,k);
    cout<<price;
    gotoxy(33,k);
    cout<<qty;
    gotoxy(64,k);
    cout<<netamt;
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<" TICKET DETAILS ";
        gotoxy(3,5);
        cout<<"NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"PRICE";
        gotoxy(33,5);
        cout<<"QUANTITY";
        gotoxy(36,5);
        cout<<"NET AMOUNT";
    }
}

void amount::pay()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                       :"<<price;
    cout<<"\n\t\tQUANTITY                    :"<<qty;
    cout<<"\n\n\t\tNET AMOUNT\t             :$"<<netamt;
    cout<<"\n\n\t\t*********************************************";
}
//Bunra
//Piseth
class Passenger
{
public:
    string Pessenger_Name;
    string Flight_Name;
    Passenger *next_val;
    Passenger(const string a, string b, Passenger* p = NULL)
    {
        this->Pessenger_Name = a;
        this->Flight_Name = b;
        this->next_val = p;
    }
};
class classTicket
{
private:
    Passenger *headval, *tailval;
public:
    classTicket();
    ~classTicket();
    void Ticket_reservation();
    void cancel_Ticket();
    void check_Ticket();
    void display();
};
classTicket::classTicket()
{
    headval = tailval = NULL;
}
classTicket::~classTicket()
{
    Passenger* P1 = headval, *q1 = headval;
    while (P1 != NULL)
    {
        q1 = headval->next_val;
        delete P1;
        P1 = q1;
    }
}
void classTicket::Ticket_reservation()
{
    string Pessenger_Name, Flight_Name;
    cout << "passenger name::" << endl;
    cin >> Pessenger_Name;
    cout << "flight name::" << endl;
    cin >> Flight_Name;
    if (headval == NULL)
    {
        headval = tailval = new Passenger(Pessenger_Name, Flight_Name);
        cout << "ticket reserved" << endl;
        return;
    }
    else
    {
        Passenger *P1 = headval;
        while (P1->next_val)
        {
            if (Pessenger_Name < P1->Pessenger_Name)
                break;
            else
                P1 = P1->next_val;
        }
        P1->next_val = new Passenger(Pessenger_Name, Flight_Name, P1->next_val);
        cout << "" << endl;
        return;
    }
}
void classTicket::cancel_Ticket()
{
    string Pessenger_Name, Flight_Name;
    cout << "passenger name:" << endl;
    cin >> Pessenger_Name;
    cout << "flight name:" << endl;
    cin >> Flight_Name;
    Passenger *P1 = headval, *q1 = headval;
    if ((Pessenger_Name == Pessenger_Name) && (P1->Flight_Name == Flight_Name))
    {
        headval = headval->next_val;
        cout << "ticket cancelled" << endl;
        delete P1;
        return;
    }
    P1 = headval->next_val;
    while (P1)
    {
        if ((P1->Pessenger_Name == Pessenger_Name) && (P1->Flight_Name == Flight_Name))
        {
            q1->next_val = P1->next_val;
            delete P1;
            cout << "could not cancelled the ticket!" << endl;
            return;
        }
        else
        {
            q1 = P1;
            P1 = P1->next_val;
        }
    }
    cout << "" << endl;
    return;
}
void classTicket::check_Ticket()
{
    string Pessenger_Name;
    cout << "passenger name" << endl;
    cin >> Pessenger_Name;
    Passenger* P1 = headval;
    while (P1 != NULL)
    {
        if (P1->Pessenger_Name == Pessenger_Name)
        {
            cout << "passenger name:" << P1->Pessenger_Name << endl;
            cout << " flight name" << P1->Flight_Name << endl;
            return;
        }
        else
            P1 = P1->next_val;
    }
    cout << "ticket checked" << endl;
    return;
}
void classTicket::display()
{
    Passenger* P1 = headval;
    while (P1 != NULL)
    {
        cout << "display the passenger" << P1->Pessenger_Name << endl;
        cout << " Flight Name:" << P1->Flight_Name << endl;
        P1 = P1->next_val;
    }
}
//Piseth
//Davin
class bus{
private:
    struct Element
    {
        int b_seats,b_num;
        string b_name,d_name;
        Element *next_data;
    };
public:
    Element *head=NULL;
    void AddBusRecord();
    void ViewBusesDetail();
    void UpdateBusDetail();
    void DeleteBusDetail();
};
void bus::AddBusRecord()
{
    system("cls");
    cout<<"\n\t\t=========================\n\n";
    cout<<"\n\t\t  Bus booking system \n\n";
    cout<<"\n\t\t=========================\n\n";
    Element *new_data = new Element;
    cout<<"\n\n Enter bus number : ";
    cin>>new_data ->b_num;
    cout<<"\n\n Enter bus name : ";
    cin>>new_data ->b_name;
    cout<<"\n\n Total seats : ";
    cin>>new_data ->b_seats;
    cout<<"\n\n Enter bus Driver's name : ";
    cin>>new_data ->d_name;
    new_data -> next_data = NULL;
    if(head == NULL)
    {
        head = new_data;
    }else
    {
        Element *usa = head;
        while (usa -> next_data != NULL)
        {
            usa = usa -> next_data;
        }
        usa -> next_data = new_data;
    }
    cout<<"\n\n\t\t New Bus Insert Successfully.....";
}
void bus::ViewBusesDetail()
{
    system("cls");
    cout<<"\n\t\t=========================\n\n";
    cout<<"\n\t\t  Bus booking system \n\n";
    cout<<"\n\t\t=========================\n\n";
    Element *usa = head;
    while(usa !=NULL)
    {
        cout<<"\n\n Bus number : "<<usa->b_num;
        cout<<"\n\n Bus name :  "<<usa->b_name;
        cout<<"\n\n Total seats : "<<usa->b_seats;
        cout<<"\n\n Bus Driver's name : "<<usa->d_name;
        cout<<"\n\n\n =================================";
        usa =usa->next_data;
    }
}
void bus::UpdateBusDetail() {
    system("cls");
    int t_b_num,found=0;
    cout<<"\n\t\t=========================\n\n";
    cout<<"\n\t\t  Bus booking system \n\n";
    cout<<"\n\t\t=========================\n\n";
    if(head==NULL){
        cout<<"\n\n Linked list is Empty....";
    }else{
        cout<<"\n\n Bus number : ";
        cin>>t_b_num;
        Element *usa = head;
        while (usa != NULL){
            if(t_b_num == usa -> b_num)
            {
                system("cls");
                cout<<"\n\t\t=========================\n\n";
                cout<<"\n\t\t  Bus booking system \n\n";
                cout<<"\n\t\t=========================\n\n";
                cout<<"\n\n Enter bus number : ";
                cin>>usa ->b_num;
                cout<<"\n\n Enter bus name : ";
                cin>>usa ->b_name;
                cout<<"\n\n Total seats : ";
                cin>>usa ->b_seats;
                cout<<"\n\n Enter bus Driver's name : ";
                cin>>usa ->d_name;
                found++;
                cout<<"\n\n\t\tUpdate Bus Record successfully !";
            }
            usa = usa -> next_data;
        }
        if(found==0){
            cout<<"\n\n Bus number is Invalid.....";
        }
    }
}
void bus::DeleteBusDetail() {
    system("cls");
    int t_b_num, found=0;
    cout<<"\n\t\t=========================\n\n";
    cout<<"\n\t\t  Bus booking system \n\n";
    cout<<"\n\t\t=========================\n\n";
    if(head==NULL){
        cout<<"\n\n Linked list is Empty....";
    }
    else
    {
        cout<<"\n\n Book ID : ";
        cin>>t_b_num;
        if(t_b_num == head -> b_num)
        {
            Element *usa = head;
            head = head -> next_data;
            delete usa;
            cout<<"\n\n Delete Bus Successfully....";
        }
        else
        {
            Element *pop = head;
            Element *usa = head;
            while(usa != NULL)
            {
                if(t_b_num == usa -> b_num)
                {
                    pop -> next_data = usa -> next_data;
                    delete usa;
                    cout<<"\n\n Delete Bus Successfully.....";
                    found++;
                    break;
                }
                pop = usa;
                usa = usa -> next_data;
            }
            if(found == 0)
            {
                cout<<"\n\n Bus number is Invalid.....";
            }
        }
    }
}
//Davin
int main(){
    system("CLS");
    classTicket t1;
    bus obj;
    p:
    int op;
    int choice;

    do{
        cout<<"\n==================================================================\n";
        cout<<"\n==================================================================\n";
        cout<<"\n==========\tWELCOME TO GENERAL BOOKING SYSTEM\t==========\n";
        cout<<"\n==================================================================\n";
        cout<<"\n==================================================================\n";
        cout<<"<1> MOVIE BOOKING SYSTEM "<<endl;
        cout<<"<2> BUS BOOKING SYSTEM "<<endl;
        cout<<"<3> AIRLINE BOOKING SYSTEM "<<endl;
        cout<<"<4> EXIT"<<endl;
        cout<<"Press <1> for MOVIE BOOKING SYSTEM "<<endl;
        cout<<"Press <2> for BUS BOOKING SYSTEM "<<endl;
        cout<<"Press <3> for AIRLINE BOOKING SYSTE "<<endl;
        cout<<"Press <4> for EXIT"<<endl;
        cout<<"Choose 1-4: ";
        cin>>op;
        switch(op){
            case 1:{
                system("CLS");
                int a;
                cout<<"\n<1> LOG IN AS ADMIN"<<endl;
                cout<<"<2> WELCOME TO ONLINE TICKET VOLLEYBALL"<<endl;
                cout<<"Press <1> for LOG IN AS ADMIN"<<endl;
                cout<<"Press <2> for WELCOME TO ONLINE TICKET VOLLEYBALL"<<endl;
                cout<<"Choose from 1-2";
                cin>>a;
                if(a==1){
                    gotoxy(40,4);
                    cout<<"==================================\n\n";
                    gotoxy(40,5);
                    cout<<"\tUSER PANEL - LOGIN ";
                    gotoxy(40,6);
                    cout<<"==================================\n\n";
                    string username=" ";
                    string password=" ";
                    bool loginSucess= false;

                    do
                    {
                        gotoxy(40,10);
                        cout<<"\nEnter Username: ";
                        cin>> username;
                        gotoxy(40,12);
                        cout<<"\nEnter Password: ";
                        cin>> password;
                        if(username=="admin" && password=="admin")
                        {
                            cout<<"\n You're 'sucessfully logged in\n\n" ;
                            loginSucess = true;
                        }else
                        {
                            cout<<" Incorrect username and password\n";
                            cout<<" Please try to login again";
                        }
                    } while(!loginSucess);

                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout<<setprecision(2);
                    fstream tmp("temp.dat",ios::binary|ios::out);
                    menu:
                    system("cls");
                    gotoxy(25,2);
                    cout<<"==============================\n\n";
                    gotoxy(25,3);
                    cout<<"MOVIE TICKET MANAGEMENT SYSTEM ";
                    gotoxy(25,4);
                    cout<<"==============================\n\n";

                    cout<<"\n\t\t1.CART REPORT \n\n";

                    cout<<"\n\t\t2.ADD/REMOVE/EDIT Ticket\n\n";

                    cout<<"\n\t\t3.SHOW TICKET DETAILS\n\n";

                    cout<<"\n\t\t4.EXIT\n\n";

                    cout<<"\n\t\tPlease Enter Required Option: ";
                    int ch,ff;
                    float gtotal;
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                        ss:
                            system("cls");
                            gotoxy(25,2);
                            cout<<"CART DETAILS";
                            gotoxy(25,3);
                            cout<<"================\n\n";
                            cout<<"\n\t\t1.All Ticketa\n\n";
                            cout<<"\t\t2.BACK TO MAIN MENU\n\n";
                            cout<<"\t\tPlease Enter Required Option: ";
                            int cho;
                            cin>>cho;
                            if(cho==1)
                            {
                                system("cls");
                                gotoxy(30,3);
                                cout<<" CART DETAILS ";
                                gotoxy(3,5);
                                cout<<"NO";
                                gotoxy(13,5);
                                cout<<"NAME";
                                gotoxy(23,5);
                                cout<<"PRICE";
                                gotoxy(33,5);
                                cout<<"QUANTITY";
                                gotoxy(64,5);
                                cout<<"NET AMOUNT";

                                fin.open("itemstore.dat",ios::binary);
                                if(!fin)
                                {
                                    cout<<"\n\nFile Not Found...";
                                    goto menu;
                                }
                                fin.seekg(0);
                                gtotal=0;
                                while(!fin.eof())
                                {
                                    fin.read((char*)&amt,sizeof(amt));
                                    if(!fin.eof())
                                    {
                                        amt.report();
                                        gtotal+=amt.retnetamt();
                                        ff=0;
                                    }
                                    if(ff!=0)
                                        gtotal=0;
                                }
                                gotoxy(17,k);
                                cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
                                getch();
                                fin.close();
                            }
                            if(cho==2)
                            {
                                goto menu;
                            }
                            goto ss;
                        case 2:
                        db:
                            system("cls");
                            gotoxy(25,2);
                            cout<<"============\n\n";
                            gotoxy(25,3);
                            cout<<"MAIN SECTION";
                            gotoxy(25,4);
                            cout<<"============\n\n";
                            cout<<"\n\t\t1.ADD TICKET DETAILS\n\n";
                            cout<<"\t\t2.EDIT TICKET DETAILS\n\n";
                            cout<<"\t\t3.DELETE TICKET DETAILS\n\n";
                            cout<<"\t\t4.BACK TO MAIN MENU";
                            int apc;
                            cin>>apc;
                            switch(apc)
                            {
                                case 1:
                                    fout.open("itemstore.dat",ios::binary|ios::app);
                                    amt.add();
                                    cout<<"\n\t\tTicket Added Successfully!";
                                    getch();
                                    goto db;

                                case 2:
                                    int ino;
                                    flag=0;
                                    cout<<"\n\n\tENTER TICKET NUMBER TO BE EDITED :";
                                    cin>>ino;
                                    fin.open("itemstore.dat",ios::binary);
                                    fout.open("itemstore.dat",ios::binary|ios::app);
                                    if(!fin)
                                    {
                                        cout<<"\n\nFile Not Found...";
                                        goto menu;
                                    }
                                    fin.seekg(0);
                                    r=0;
                                    while(!fin.eof())
                                    {
                                        fin.read((char*)&amt,sizeof(amt));
                                        if(!fin.eof())
                                        {
                                            int x=amt.ticket::retno();
                                            if(x==ino)
                                            {
                                                flag=1;
                                                fout.seekp(r*sizeof(amt));
                                                system("cls");
                                                cout<<"\n\t\tCURRENT DETAILS ARE\n";
                                                amt.show();
                                                cout<<"\n\n\t\tENTER NEW DETAILS\n";
                                                amt.add();
                                                cout<<"\n\t\tTICKET DETAILS EDITED";
                                            }
                                        }r++;
                                    }
                                    if(flag==0)
                                    {
                                        cout<<"\n\t\tTicket No does not exist...Please Retry!";
                                        getch();
                                        goto db;
                                    }
                                    fin.close();
                                    getch();
                                    goto db;

                                case 3:
                                    flag=0;
                                    cout<<"\n\n\tEnter Ticket Number to be deleted :";
                                    cin>>ino;
                                    fin.open("itemstore.dat",ios::binary);
                                    if(!fin)
                                    {
                                        cout<<"\n\nFile Not Found...";
                                        goto menu;
                                    }

                                    fin.seekg(0);
                                    while(fin.read((char*)&amt, sizeof(amt)))
                                    {
                                        int x=amt.ticket::retno();
                                        if(x!=ino)
                                            tmp.write((char*)&amt,sizeof(amt));
                                        else
                                        {
                                            flag=1;
                                        }
                                    }
                                    fin.close();
                                    tmp.close();
                                    fout.seekp(0);
                                    tmp.open("temp.dat",ios::binary|ios::in);
                                    if(!tmp)
                                    {
                                        cout<<"Error in File";
                                        goto db;
                                    }
                                    while(tmp.read((char*)&amt,sizeof(amt)))
                                        fout.write((char*)&amt,sizeof(amt));
                                    tmp.close();
                                    fout.close();
                                    if(flag==1)
                                        cout<<"\n\t\tTicket Succesfully Deleted";
                                    else if (flag==0)
                                        cout<<"\n\t\tTicket does not Exist! Please Retry";
                                    getch();
                                    goto db;

                                case 4:

                                    goto menu;
                                default: cout<<"\n\n\t\tYou Choose Wrong Choice!!! Retry";
                                    getch();
                                    goto db;
                            }

                        case 3:
                            system("cls");
                            flag=0;
                            int ino;
                            cout<<"\n\n\t\tENTER TICKET NUMBER:";
                            cin>>ino;
                            fin.open("itemstore.dat",ios::binary);
                            if(!fin)
                            {
                                cout<<"\n\nFile Not Found...\nProgram Terminated!";
                                goto menu;
                            }
                            fin.seekg(0);
                            while(fin.read((char*)&amt,sizeof(amt)))
                            {
                                int x=amt.ticket::retno();
                                if(x==ino)
                                {
                                    amt.pay();
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0)
                                cout<<"\n\t\tTicket does not exist....Please Retry!";
                            getch();
                            fin.close();
                            goto menu;

                        case 4:
                            system("cls");
                            gotoxy(20,20);
                            cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
                            char yn;
                            cin>>yn;
                            if((yn=='Y')||(yn=='y'))
                            {
                                system("cls");
                                gotoxy(40,4);
                                cout<<"==============================\n\n";
                                gotoxy(40,5);
                                cout<<"THANK YOU FOR USING OUR SYSTEM ";
                                gotoxy(40,6);
                                cout<<"==============================\n\n";
                                getch();
                                exit(0);
                            }
                            else if((yn=='N')||(yn=='n'))
                                goto menu;
                            else
                            {
                                goto menu;
                            }

                        default:
                            cout<<"\n\n\t\tWrong Choice....Please Retry!";
                            getch();
                            goto menu;
                    }
                }else if(a==2){
                    int i;
                    cout<<"\n\n\t\t\t==========Welcome to online ticket volleyball ================== ";
                    cout<<"\n\t We have 3 type of ticket : ";
                    cout<<"\n\n1. Type A VIP place with 250 $ !!! ";
                    cout<<"\n\n2. Type B with 150 $!!! ";
                    cout<<"\n\n2. Type C with 99 $ !!!";
                    cout<<"\n\n Order and check list in here : ";
                    cout<<"\n\t\t Before go to order please press 123 :";
                    cin>>i;

                    if (i==123){
                        Booking service;
                        service.menu();
                    }
                    else{
                        cout<<"\nwrong press number meaning that you don't want order ticket !!!! \n Please  login again !!!!\n";

                    }



                }
            }break;
            case 2:{
                cout<<"\n\t\t==============================\n\n";
                cout<<"\n\t\t Welcome to Bus booking system \n\n";
                cout<<"\n\t\t==============================\n\n";
                while(1)
                {
                    cout<<"\n\n ***MAIN MENU***\n\n";
                    cout<<"\n\t\t1.Add Bus Record\n\n";
                    cout<<"\n\t\t2.View Buses Detail\n\n";
                    cout<<"\n\t\t3.Update Bus Detail\n\n";
                    cout<<"\n\t\t4.Delete Bus Detail\n\n";
                    cout<<"\n\t\t5.Booking Record\n\n";
                    cout<<"\n\t\t6.Search Booking Record\n\n";
                    cout<<"\n\t\t7.Update Booking Record\n\n";
                    cout<<"\n\t\t8.Delete Booking Record\n\n";
                    cout<<"\n\t\t9.Show All Booking Record\n\n";
                    cout<<"\n\t\t10.Exit\n\n";
                    cout << "\n\t\t\tEnter your choice:-> ";
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                            obj.AddBusRecord();
                            break;
                        case 2:
                            obj.ViewBusesDetail();
                            break;
                        case 3:
                            obj.UpdateBusDetail();
                            break;
                        case 4:
                            obj.DeleteBusDetail();
                            break;
                        case 5:

                            break;
                        case 6:

                            break;
                        case 7:

                            break;
                        case 8:

                            break;
                        case 9:

                            break;
                        case 10:
                            cout<<"\n\n\t\tTHANK YOU FOR USING THE SOFTWARE";
                            exit(0);
                        default:
                            cout<<"\nYOU ENTERED WRONG CHOICE..";
                            cout<<"\nPRESS ANY KEY TO TRY AGAIN";
                            break;
                    }
                    getch();
                    goto p;
                }
            }break;
            case 3:{
                system("CLS");
                while (true)
                {
                    cout<<"\n==================================================================\n";
                    cout<<"\n==================================================================\n";
                    cout << "\n===============\tAIRLINE RESERVATION TICKET\t==================" << endl;
                    cout<<"\n==================================================================\n";
                    cout<<"\n==================================================================\n";
                    cout << "ENTER YOUR CHOICE:" << endl;
                    cout << "1.For Ticket_Reservation" << endl;
                    cout << "2.For Cancel_Ticket" << endl;
                    cout << "3.For Check_Ticket" << endl;
                    cout << "4.For Display_Ticket" << endl;
                    cout << "5.For End Program" << endl;
                    cout << endl;
                    int f;
                    cin >> f;
                    switch (f)
                    {
                        case 1:
                            t1.Ticket_reservation();
                            break;
                        case 2:
                            t1.cancel_Ticket();
                            break;
                        case 3:
                            t1.check_Ticket();
                            break;
                        case 4:
                            t1.display();
                            break;
                        case 5:
                            return 0;
                        default:
                            cout << "end" << endl;
                            break;
                    }
                }

            }break;

        }
    }while(op!=4);

}


