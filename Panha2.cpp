class manage:public complate{
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
    cout<<"\n\n 2.LOAD Management ";
    cout<<"\n\n 3.Customer Coplate ";
    cout<<"\n\n 4. Exit ";
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
            complate::man();
        }break;
        case 4:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n Invalid value ... Please Try Again ";
        }
    }
    getch();
    goto p;
}
class staff:public manage{
protected:
    struct node{
        string id;
        string name;
        string position;
        double day_salary;
        double monther_salary;
        int costomer;
        string time;
        string timeStarWork;
        string work;
    };
public:
    void conData();
    void conInsert();
    void conSalary();
    void man1();
};
void staff::conData(){
    if(sqlite3_open("phanha.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS Staff(id VARCHAR(50),name VARCHAR(50),position VARCHAR(50),day_salary DOUBLE,monther_salary DOUBLE,costomer INT,timeStarWork VARCHAR(80),work VARCHAR(80),time VARCHAR(80));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void staff::conInsert(){
        string id;
        string name;
        string position;
        double day_salary;
        double monther_salary;
        int costomer;
        string time;
        string timeStarWork;
        string work;

        cout<<"\n\n Input ID : ";
        fflush(stdin);
        getline(cin,id);

        cout<<"\n\n Input Name : ";
        fflush(stdin);
        getline(cin,name);

        cout<<"\n\n Input Position : ";
        fflush(stdin);
        getline(cin,position);

        cout<<"\n\n Input Day Salary : ";
        cin>>day_salary;

        cout<<"\n\n Input Monther Salary : ";
        cin>>monther_salary;

        costomer = 0;

        cout<<"\n\n Input Time to Work : ";
        fflush(stdin);
        getline(cin,timeStarWork);

        cout<<"\n\n Input Work : ";
        fflush(stdin);
        getline(cin,work);

        cout<<"\n\n Time start Work : ";
        fflush(stdin);
        getline(cin,time);

        result = sqlite3_open("phanha.db",&db);
        string quary = "INSERT INTO Staff(id, name, position, day_salary, monther_salary, costomer, timeStarWork, work, time ) VALUES(?,?,?,?,?,?,?,?,?);" ;
        result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
        sqlite3_bind_text(stmt, 1, id.c_str(), id.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, position.c_str(), position.length(), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 4, day_salary);
        sqlite3_bind_double(stmt, 5, monther_salary);
        sqlite3_bind_int(stmt, 6, costomer);
        sqlite3_bind_text(stmt, 7, timeStarWork.c_str(), timeStarWork.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 8, work.c_str(), work.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 9, time.c_str(), time.length(), SQLITE_TRANSIENT);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);

        if(result != SQLITE_OK){
            cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<" Data Successfully \n";
        }
}
void staff::conSalary(){
    result = sqlite3_open("phanha.db",&db);
    query = "SELECT rowid, * FROM Staff";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<" ERROR "<<sqlite3_errmsg<<endl;
    }else{
        while((result = sqlite3_step(stmt)) == SQLITE_ROW){
            cout<<left<<"\t"<<setw(15)<<sqlite3_column_text(stmt, 0)<< " "
            <<setw(25)<<sqlite3_column_text(stmt, 1)<<" \t"
            <<setw(25)<<sqlite3_column_text(stmt, 2)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 3)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 4)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 5)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 6)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 7)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 8)<<" \t"
            <<setw(15)<<sqlite3_column_text(stmt, 9)<<" \t"<<endl;
        }
        if(result != SQLITE_OK){
            cout<<" Error : "<<sqlite3_errmsg(db)<<endl;
        }
        cout<<"\n--------------------------------------------------------------------------------------------\n";
    }
}
void staff::man1(){
    conData();
    system("cls");
    int option;
    p:
    cout<<"\n\n 1. Insert Information Staff "<<endl;
    cout<<"\n\n 2. Display Information Staff "<<endl;
    cout<<"\n\n Select Option : ";
    cin>>option;
    switch(option){
        case 1:{
            conInsert();
        }break;
        case 2:{
            conSalary();
        }break;
        case 3:{
        }break;
        default:{
            cout<<"\n\n Invalid Choice ..."<<endl;
        }
    }
    goto p;
    getch();

}
class queue:public staff{
protected:
      struct node//  queue linked list
      {
          string id;
          int arr[20];
          string data;
          string name;
          string gender;
          int x,x1,x2;
          node *next;
      };
      string stk[10];//stack array
      node *head = NULL;
      node *tail = NULL;
public:
    void menu3();
    void menu4();
    void color(int color);
    void gotoxy(int x, int y);
    void load_data3();
    void push();
    void display();
    void pop();
    void push1();
    void push2(string searchid,int id,int number);
    void pop1();
    void display1();
};
void queue::color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void queue::gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void queue::push2(string searchid,int id,int number){
    string again;
    p:

    result = sqlite3_open("phanha.db",&db);
    query = "SELECT * FROM Staff";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,0));
        double day_salary = (sqlite3_column_double(stmt,3));
        int costomer = (sqlite3_column_double(stmt,5));
        if(searchid == Id){
                cout<<Id;

            cout<<"\n DO YOU WANT TO SAVING MONEY ?(YES/NO) : ";
            fflush(stdin);
            cin>>again;
            if(again =="YES" || again == "ýes"){
                 costomer += number;
                 day_salary += 3 * number;
                 query = "UPDATE Staff SET day_salary = ?, costomer = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, day_salary);
                 sqlite3_bind_double(stmt, 2, costomer);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu3();
            }else{
                goto p;
            }
        }else if(searchid != Id){
            cout<<"Invalid ..."<<endl;
        }

    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
void queue::push1(){
    system("cls");
    string idl,name;
    int id,option;
    int number;
    p:
    if(m > 9){
        cout<<"\n\n\t\t\t Stuff is full ...";
    }else{
        cout<<"\n\n Name OF Staff "<<endl;
        cout<<"\n\n 1. Phanha     "<<endl;
        cout<<"\n\n 2. Kaa        "<<endl;
        cout<<"\n\n 3. Makara     "<<endl;
        cout<<"\n\n 4.  Visal     "<<endl;
        cout<<"\n\n 5.  Yanut     "<<endl;
        cout<<"\n\n Who do you want to meet with ? : ";
        cin>>option;
        if(option == 1){
            name = "Phanha";
            idl = "e20200836";
            id = 1;
            number = 1;
        }else if(option == 2){
            name = "Kaa";
            idl = "e20200837";
            id = 2;
            number = 1;
        }else if(option == 3){
            name = "Makara";
            idl = "e20200838";
            id = 3;
            number = 1;
        }else if(option == 4){
            name = "Visal";
            idl = "e20200839";
            id = 4;
            number = 1;
        }else if(option == 5){
            name = "Yanut";
            idl = "e20200840";
            id = 5;
            number = 1;
        }else{
            cout<<"\n\n Invalid Choice ..."<<endl;
            goto p;
            getch();
        }
        cout<<idl<<"\t"<<id<<"\t"<<number<<endl;
        push2(idl,id,number);
        stk[++m] = name;
        cout<<"\n\n\t\t\t Name : "<<name<<" Successfully ....";
    }
}
void queue::pop1(){
    system("cls");
    if(m < 0){
        cout<<"\n\n\t\t\t Empty ...";
    }else{
        cout<<"\n\n "<<stk[m--]<<"Delete Successful ...";
    }
}
void queue::display1(){
    system("cls");
    cout<<endl;
    if(m < 0){
        cout<<"\n\n\t\t\t No Stuff ...";
    }else{
        for(int a=m; a>=0; a--){
            cout<<"\n\n\t\t\t Name :  "<<stk[a]<<endl;
        }
    }
}
void queue::load_data3(){
    fstream file;
    string emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    file.open("table.txt",ios::in);
    if(file){
        file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        while(!file.eof()){
            node *new_node = new node;
            new_node->id = emp_id;
            new_node->data = emp_data;
            new_node->name = emp_name;
            new_node->gender = emp_gender;
            new_node->x = emp_x;
            new_node->x1 = emp_x1;
            new_node->x2 = emp_x2;
            new_node->next = NULL;
            if(head == NULL){
                head = new_node;
                tail = new_node;
            }else{
                tail -> next = new_node;
                tail = new_node;
            }
            file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        }
        file.close();
    }
}
void queue::push()
{
    fstream file;
    SYSTEMTIME x;
    system("cls");
    string emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    cout<<"\n\n\t\t\t\t Push Record";
    cout<<"\n\n\t\t\t Enter ID : ";
    cin>>emp_id;
    cout<<"\n\n\t\t\t Your Function : ";
    cin>>emp_data;
    cout<<"\n\n\t\t\t Your Name : ";
    cin>>emp_name;
    cout<<"\n\n\t\t\t Your Gender : ";
    cin>>emp_gender;
    GetSystemTime(&x);
    emp_x = x.wHour;
    emp_x1 = x.wSecond;
    emp_x2 = x.wMilliseconds;
    node *new_node = new node;
    new_node->id = emp_id;
    new_node->data = emp_data;
    new_node->name = emp_name;
    new_node->gender = emp_gender;
    new_node->x = emp_x;
    new_node->x1 = emp_x1;
    new_node->x2 = emp_x2;
    new_node -> next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }else{
        tail -> next = new_node;
        tail = new_node;
    }
    file.open("table.txt",ios::app|ios::out);
    file<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<" \n";
    file.close();
}
void queue::display()
{
    system("cls");
    SYSTEMTIME x;
    int k = 0;
    cout<<"\n\n\t\t\t\tDisplay Record"<<endl;
    if(head == NULL){
        cout<<"\n\n Queue is Empty..."<<endl;
    }else{
        node *ptr = head;
        while(ptr != NULL){
                 GetSystemTime(&x);
                 int n = sizeof(ptr->arr)/sizeof(ptr->arr[0]) - ++i;
                 system("color 0B");
                 cout<<"\n\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"  TABLE PLEASE SITDOWN  :    "<<++k<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<"    ID       : "<< ptr->id <<endl;
                 cout<<"\t\t\t\t\t"<<"    FUNCTION : "<< ptr->data <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME     : "<< ptr->name <<endl;
                 cout<<"\t\t\t\t\t"<<"    GENDER   : "<< ptr->gender <<endl;
                 cout<<"\t\t\t\t\t"<<"   TABLE FREE: "<< n<<endl;
                 cout<<"\t\t\t\t\t"<<"    TIME     : "<< ptr->x<<":"<<ptr->x1<<":"<<ptr->x2<<endl;
                 cout<<"\t\t\t\t\t"<<"    DATE     : "<< x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
                 cout<<load;
                 cout<<"\n";
                 ptr=ptr -> next;
        }
    }
}
void queue::pop(){
    system("cls");
    fstream file,file1;
    string t_id,emp_id;
    string emp_data,emp_name,emp_gender;
    int emp_x,emp_x1,emp_x2;
    int found = 0;
    cout<<"\t\t\t===================================\n";
    cout<<"\t\t\t  4. Delete ALL  Record      "<<endl;
    cout<<"\t\t\t===================================\n";
    if(head == NULL){
        cout<<"\n\n\t\t\t NO Record ...."<<endl;
    }else{
        cout<<"\n\n\t\t\t Employee ID : ";
        cin>>t_id;
        file.open("table.txt",ios::in);
        file1.open("table1.txt",ios::app|ios::out);
        file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        while(!file.eof()){
            if(t_id == emp_id){
                system("color 0C");
                cout<<"\t\t\t\t\t";
                for(int j=0;j<=31;j++)
                cout<<load;
                cout<<"\n";
                cout<<"\t\t\t\t\t"<<load<<"----------------------------  "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"      Delete ALL  Record      "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<" ---------------------------  "<<load<<endl;
                cout<<"\t\t\t\t\t"<<load<<"  Delete Record Successfully.."<<load<<endl;
                cout<<"\t\t\t\t\t";
                for(int j=0;j<=31;j++)
                cout<<load;
                cout<<"\n";
                found++;

            }
            else{
                file1<<emp_id<<" "<<emp_data<<" "<<emp_name<<" "<<emp_gender<<" "<<emp_x<<" "<<emp_x1<<" "<<emp_x2<<"\n";
            }
            file>>emp_id>>emp_data>>emp_name>>emp_gender>>emp_x>>emp_x1>>emp_x2;
        }
        file.close();
        file1.close();
        remove("table.txt");
        rename("table1.txt","table.txt");
        if(found == 0){
            cout<<"\n\n\t\t\t Employee can not Found...";
        }
    }
}
void queue::menu4(){
    staff::conData();
    int choice;
    p:
    system("cls");
    cout<<"\n\n\t\t\t Control Panel ";
    cout<<"\n\n 1. Push Record ";
    cout<<"\n\n 2. Pop Record ";
    cout<<"\n\n 3. Display Record ";
    cout<<"\n\n 4. Back ";
    cout<<"\n\n 5. Staff Information ";
    cout<<"\n\n 6. Exit ";
    cout<<"\n\n Select Option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            push1();
        }break;
        case 2:{
            pop1();
        }break;
        case 3:{
            display1();
        }break;
        case 4:{
            menu3();
        }break;
        case 5:{
            staff::man1();
        }break;
        case 6:{
            exit(0);
        }break;
        default:{
            cout<<"\n\n\t\t\t Invalid ...";
        }
    }
    getch();
    goto p;
}
void queue::menu3(){
    system("cls");
    int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
    int counter = 3;
    char key;
    cout<<"\n\n";
    for(int i=0;;)
    {
        gotoxy(10,5);
        color(Set[0]);
        cout<<"\n1. Menu Stuff ";

        gotoxy(10,6);
        color(Set[1]);
        cout<<"\n2. Login ";

        gotoxy(10,7);
        color(Set[2]);
        cout<<"\n3. Service Back ";

        gotoxy(10,8);
        color(Set[3]);
        cout<<"\n4. Go to Service";

        gotoxy(10,9);
        color(Set[4]);
        cout<<"\n5. Extra_2";

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 5))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 4))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                cout<<"\nMenu 1 is Open";
            }
            if(counter == 2)
            {
                cout<<"Menu 2 is Open";
                push();
            }
            if(counter == 3)
            {
                cout<<"Menu 3 is Open";
                head = NULL;
                load_data3();
                display();
            }
            if(counter == 4)
            {
                cout<<"Menu 4 is Open\n";
                head = NULL;
                load_data3();
                pop();
                menu4();
            }
            if(counter == 5)
            {
                cout<<"Menu 5 is Open";
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if(counter == 1)
        {
            Set[0] = 12;
        }
        if(counter == 2)
        {
            Set[1] = 12;
        }
        if(counter == 3)
        {
            Set[2] = 12;
        }
        if(counter == 4)
        {
            Set[3] = 12;
        }
        if(counter == 5)
        {
            Set[4] = 12;
        }
    }
}
int main(){
    queue q;
    q.menu3();
    sqlite3_close(db);
}


