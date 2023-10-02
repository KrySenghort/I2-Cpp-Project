#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include<sqlite3.h>
#include<cstring>
#include<fstream>
using namespace std;
struct Books {
    int code;
    int qty;
    float price;
    string name_book;
    string name_author;
   struct Books *next;
};
struct Books* front = NULL;
struct Books* rear = NULL;
struct Books* temp;
void Insert() {
    struct Books book;
    int code;
    float price;
    string name_book;
    string name_author;
    int n,i;
    system("cls");
    cout<<"\n\n\t\t***********************"<<endl;
    cout<<"\t\t*    Add New Book     *"<<endl;
    cout<<"\t\t***********************"<<endl;
    fstream file;
                    file.open("Bookshop.bin",ios::app| ios::binary);

                    cout<<">>>>>>>.Enter Item:";cin>>n;
                    if(!file)
                    {
                         cout<<"file error!";
                         exit(0);
                    }
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    for(i=0;i<n;i++){
                        cout<<"........Item#"<<i+1<<endl;
                        cout<<"Code ID: ";cin>>code;
                        cout<<"Name Books: ";cin>>name_book;
                        cout<<"Author Name: ";cin>>name_author;
                        cout<<"Price Book: ";cin>>price;
                        file.write((char*)&book,sizeof(book));
                    }
                cout<<"write success!"<<endl;
                file.close();
   if (rear == NULL) {
      rear = (struct Books *)calloc(n,sizeof(struct Books));
      rear->next = NULL;
      rear->code = code;
      rear->price= price;
      rear->name_book= name_book;
      rear->name_author= name_author;
      front = rear;
   } else {
      temp=(struct Books *)calloc(n,sizeof(struct Books));
      rear->next = temp;
      temp->code = code;
      temp->price= price;
      temp->name_book= name_book;
      temp->name_author= name_author;
      temp->next = NULL;
      rear = temp;
   }
}
void Delete() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Element deleted from record is : "<<front->code<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Element deleted from record is : "<<front->code<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void Display() {
   temp = front;
   struct Books book;
   fstream file;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Record is empty"<<endl;
      return;
   }
   file.open("Bookshop.bin",ios::in| ios::binary);
   system("cls");
   cout<<setw(15)<<"CODE"<<setw(15)<<" PRICE"<<setw(15)<<"NAME_BOOK"<<setw(15)<<"NAME_AUTHOR"<<endl;
   while(file.read((char*)&book,sizeof(book)))
                {
                    while (temp != NULL) {
                        cout<<setw(15)<<temp->code<<setw(15)<<temp->price<<"$"<<setw(15)<<temp->name_book<<setw(15)<<temp->name_author<<endl;
                        temp = temp->next;
                     }
                }
                file.close();
}
bool IsloggedIn()
{
    string username, password, un, pw;

    cout << "Enter username :";
    cin >> username;

    cout << "Enter password :";
    cin >> password;
    ifstream read("data\\" + username + ".txt");

    getline(read, un);
    getline(read, pw);


    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//
struct Customer{
    int code;
    long phone_number;
    char name_book[50];
    char name[50];
    int age;
    int n;
    Customer *next;
};
Customer *top;

class stack{

public:
    void push(int code,char name[],char name_book[], int age,long phone_number);
    void pop();
    void display();
};

void stack :: push(int code,char name[],char name_book[], int age,long phone_number)
{
    struct Customer *newCustomer=new Customer;

    newCustomer->code=code;
    newCustomer->age=age;
    newCustomer->phone_number=phone_number;
    strcpy(newCustomer->name_book,name_book);
    strcpy(newCustomer->name,name);

    newCustomer->next=top;
    top=newCustomer;
}
void stack ::pop()
{
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<top->name_book<<" is removed."<<endl;
    top=top->next;
}
void stack:: display()
{
if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct Customer *temp=top;
    while(temp!=NULL){
        cout<<temp->code<<setw(15)<<temp->name_book<<setw(15)<<temp->name<<setw(15)<<temp->age<<setw(15)<<temp->phone_number<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
//
static  callbackSelect(void *NotUsed, int argc, char**value,char **colName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s =%s\n",colName[i],value[i]);
    }
    printf("\n");
    return 0;
}
void information_employee(){
    sqlite3 *db;
    char *zErrMsg=0;
    int rc;
    char *sqlCreate, *sqlIn, *sqlSelect, *sqlUpdate,*sqlDelete;
    const char*data="Callback funtion called";

    /* Opened Database */
    rc=sqlite3_open("test3.db",&db);
    /* Create SQL statement*/
    sqlCreate="CREATE TABLE mydatabasce(" \
    "ID INT PRIMARY KEY    NOT NULL,"\
    "NAME           TEXT   NOT NULL,"\
    "SEX            TEXT   NOT NULL,"\
    "AGE            INT    NOT NULL,"\
    "DATE_OF_BIRTH  TEXT   NOT NULL,"\
    "PLACE_OF_BIRTH TEXT   NOT NULL,"\
    "EMAIL_ADDRESS  TEXT   NOT NULL,"\
    "ADDRESS        TEXT   NOT NULL,"\
    "PHONE_NUMBER   TEXT   NOT NULL,"\
    "SALARY         REAL );";

    rc=sqlite3_exec(db,sqlCreate,NULL,0,&zErrMsg);

    /* Create SQL statement*/
    sqlIn="INSERT INTO mydatabasce(ID,NAME,SEX,AGE,DATE_OF_BIRTH,PLACE_OF_BIRTH,EMAIL_ADDRESS,ADDRESS,PHONE_NUMBER,SALARY)" \
              "VALUES (2, 'Ratana','Female', 19,'13/05/2003','Kratie province','ratana609@gmail.com', 'Kratie','023784397', 400.00);"\
              "INSERT INTO mydatabasce(ID,NAME,SEX,AGE,DATE_OF_BIRTH,PLACE_OF_BIRTH,EMAIL_ADDRESS,ADDRESS,PHONE_NUMBER,SALARY)" \
              "VALUES (4, 'Lakhna','Female', 19,'12/01/2003','Kampong Speu province','chlakhna702@gmail.com', 'Kampong Speu','0975385019', 400.00);";
    /*Execute SQL statement*/
    rc=sqlite3_exec(db,sqlIn,NULL,0,&zErrMsg);

       /*Create SQL statement*/
    sqlSelect="SELECT* from mydatabasce";

    /*Execute SQL statement*/
    rc=sqlite3_exec(db,sqlSelect,callbackSelect,(void*)data,&zErrMsg);

        /* Create merged SQL statement*/
    sqlDelete="DELETE from mydatabasce where ID=0;"\
               "SELECT * from mydatabasce";
    /* Execute SQL statement*/
    rc=sqlite3_exec(db,sqlDelete,NULL,(void*)data,&zErrMsg);

       /* Create merged SQL statement */
   sqlUpdate = "UPDATE mydatabasce set SALARY =500.00 where ID=1; " \
         "SELECT * from mydatabasce";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sqlUpdate,NULL, (void*)data, &zErrMsg);

    sqlite3_close(db);

}


//
int main()
{
    cout<<"\n\n\t\t########################\n";
    cout<<"\t\t#     Admin Log In     #\n";
    cout<<"\t\t########################\n";
    string un;
   string pw;
   cout<<"Enter Username: ";cin>>un;
   cout<<"\nEnter Password: ";
   string password ="book2003";
   int length = pw.length();
   int i;
   string input;
   bool ok = true;
   cin>>input;
    if(input.length() != password.length()){
       ok = false;
        }
        else{
            for(i=0; i<length; i++){
                if(input[i] != password[i]){
                    ok = true;
                    break;
                }
            }
        }

        if(ok){
            cout<<"Logged in Successfully!";
            system("cls");
   cout<<"\n\n\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>"<<endl;
   cout<<"\t\t<<< WELCOM TO NaNa BOOKSHOP >>>"<<endl;
   cout<<"\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>\n"<<endl;
do{
   cout<<"************************************************************************\n\n";
   int op;
   cout<<"1. [Book Records]";
   cout<<"\n2. [Customer Records]";
   cout<<"\n3. [Information Employee]";
   cout<<"\n4. [Edite Records]";
   cout<<"\n........Enter your choice : ";cin>>op;
   cout<<"------------------------------------------------------------------------\n\n";
   switch(op){

       case 1:{
           int ch;
           system("cls");
           cout<<"\n\n\t\t<<<<<<<<<<<>>>>>>>>>>>>>"<<endl;
           cout<<"\t\t<<<   BOOK RECORDS   >>>"<<endl;
           cout<<"\t\t<<<<<<<<<<<<>>>>>>>>>>>>\n"<<endl;
           cout<<"1) [Add New Books]"<<endl;
           cout<<"2) [Show Books]"<<endl;
           cout<<"3) [Delete]"<<endl;
           cout<<"4) [Exit]"<<endl;
           cout<<"........Enter your choice : ";
           cin>>ch;
           switch (ch) {
                 case 1: Insert();
                 break;
                 case 2: Display();
                 break;
                 case 3:Delete();
                 break;
                 case 4: cout<<"Exit"<<endl;
                 break;
                 default: cout<<"Invalid choice"<<endl;
        }break;
    }
        case 2:
           {
            int n;
            stack s;
            char ch;
            system("cls");
            cout<<"ENTER CHOICE\n"<<"1.Customer Insert\n"<<"2.Customer Display \n"<<"3.Customer Delete\n";
            cout<<"Make a choice: ";
            cin>>n;
            switch(n){
                   case 1:
                   Customer n;
                   cout<<"Enter kind of Books to be insert : \n";
                   cout<<"Code ID: ";
                   cin>>n.code;
                   cout<<"Your age: ";
                   cin>>n.age;
                   cout<<"Name Books: ";
                   std::cin.ignore(1);
                   cin.getline(n.name_book,50);
                   cout<<"Customer Name: ";
                   std::cin.ignore(1);
                   cin.getline(n.name,50);
                   s.push(n.code,n.name,n.name_book,n.age,n.phone_number);
                   break;
                   case 2 :
                   s.display();
                   break;
                   case 3 :
                   s.pop();
                   break;
                   default :
                   cout<<"Invalid Choice\n";
              }
           }break;
       case 3:
           {
               information_employee();
           }

       }
     cout<<"Want to be continue press enter...\n";
    }while(getch()==13);
  }else{
            cout<<"Invalid Password";
        }
   return 0;
}


