class pay:public link{
protected:
    struct node{
        int pin;
        double balance;
        double payment,credit;
        string id,pass,name,fname,mname,suportname,address,phone;
        string job,plan_load;
        int n;
        node *pre,*next;
    };
    node *head = NULL;
    node *tail = NULL;
public:
    void menu2();
    void load_data1();
    void information();
    void insertInformation(int pin1,string id1,string pass1,string name1,string fname1,string mname1,string suportname1,string address1,string phone1,string job1,string plan_load1,double balance1,double payment1,double credit,int n1);
    void load_in();
    void show_Record();
    void search();
    void payment();
    void deleteInformation();

};
void pay::menu2(){
    load_data1();
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
    cout<<"\n\n Please Select option : ";
    cin>>choice;
    switch(choice){
        case 1:{
            information();
        }break;
        case 2:{
            show_Record();
        }break;
        case 3:{
            load_in();
            search();
        }break;
        case 4:{
            payment();
        }break;
        case 5:{
            deleteInformation();
        }break;
        case 6:{
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
     if(sqlite3_open("itc.db",&db) == SQLITE_OK){
        result = sqlite3_prepare_v2(db,"CREATE TABLE IF NOT EXISTS banana(pin INT,id VARCHAR(50),pass VARCHAR(50), name VARCHAR(50), father VARCHAR(50), mother VARCHAR(50),support VARCHAR(50),address VARCHAR(50) , phone VARCHAR(50), job VARCHAR(50),plan VARCHAR(50) ,balance DOUBLE,payment DOUBLE,credit DOUBLE,time INT );", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        ;
        if(result != SQLITE_OK){
                cout<<" Error : "<<sqlite3_errmsg(db)<<"\n";
        }
    }
}
void pay::information(){
    int pin;
    string id,pass,name,father,mother,address,phone,job,plan;
    double balance,balance1,payment,credit;
    string support;
    int year,time;
    float rate;
    cout<<"\n\n Input PIN : ";
    cin>>pin;

    cout<<"\n\n Input ID : ";
    fflush(stdin);
    getline(cin,id);

    cout<<"\n\n Input PASSWORD : ";
    fflush(stdin);
    getline(cin,pass);

    cout<<"\n\n Input NAME : ";
    fflush(stdin);
    getline(cin,name);

    cout<<"\n\n Input FATHER NAME : ";
    fflush(stdin);
    getline(cin,father);

    cout<<"\n\n Input Mother Name : ";
    fflush(stdin);
    getline(cin,mother);

    cout<<"\n\n Input Support Name : ";
    fflush(stdin);
    getline(cin,support);

    cout<<"\n\n Input ADDRESS : ";
    fflush(stdin);
    getline(cin,address);

    cout<<"\n\n Input PHONE NUMBER : ";
    fflush(stdin);
    getline(cin,phone);

    cout<<"\n\n Input JOB : ";
    fflush(stdin);
    getline(cin,job);

    cout<<"\n\n Input PLAN : ";
    fflush(stdin);
    getline(cin,plan);

    cout<<"\n\n Input BALANCE DOLA : ";
    cin>>balance1;

    cout<<"\n\n Number of year payback :";
    cin>>year;

    if(balance1 >0 && balance1 <=10000){
        rate = 8;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else if(balance1 >10000 && balance1 <=50000){
        rate = 7;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else if(balance1 >50000 && balance1 <=100000){
        rate = 6;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }else{
        rate = 5;
        balance = balance1 *pow((1 + rate/(100*year *12)),year *12 *year);
        payment = balance/(year * 12);
    }
    credit = balance - balance1;
    time = year *12;

    string quary = "INSERT INTO banana(pin, id, pass, name, father, mother, support,address, phone, job, plan, balance, payment, credit, time) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);" ;
    result = sqlite3_prepare_v2(db, quary.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, pin);
    sqlite3_bind_text(stmt, 2, id.c_str(), id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pass.c_str(), pass.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, name.c_str(), name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, father.c_str(), father.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, mother.c_str(), mother.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, support.c_str(), support.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, address.c_str(), address.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 9, phone.c_str(), phone.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 10, job.c_str(), job.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 11, plan.c_str(), plan.length(), SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 12, balance);
    sqlite3_bind_double(stmt, 13, payment);
    sqlite3_bind_double(stmt, 14, credit);
    sqlite3_bind_int(stmt, 15, time);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result != SQLITE_OK){
        cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<" Data Successfully \n";
    }
}
void pay::load_in(){
    result = sqlite3_open("itc.db",&db);
    query = "SELECT * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        int pin = (sqlite3_column_int(stmt,0));
        string id = (const char *) (sqlite3_column_text(stmt,1));
        string pass = (const char*) (sqlite3_column_text(stmt,2));
        string name = (const char* ) (sqlite3_column_text(stmt,3));
        string father = (const char* ) (sqlite3_column_text(stmt,4));
        string mother = (const char* ) (sqlite3_column_text(stmt,5));
        string support = (const char* ) (sqlite3_column_text(stmt,6));
        string address = (const char* ) (sqlite3_column_text(stmt,7));
        string phone = (const char* ) (sqlite3_column_text(stmt,8));
        string job = (const char* ) (sqlite3_column_text(stmt,9));
        string plan = (const char* ) (sqlite3_column_text(stmt,10));
        double balance = (sqlite3_column_double(stmt,11));
        double payment = (sqlite3_column_double(stmt,12));
        double credit = (sqlite3_column_double(stmt,13));
        double time = (sqlite3_column_double(stmt,14));
        insertInformation(pin,id,pass,name,father,mother,support,address,phone,job,plan,balance,payment,credit,time);

    }
    sqlite3_finalize(stmt);
}
void pay::insertInformation(int pin1,string id1,string pass1,string name1,string fname1,string mname1,string suportname1,string address1,string phone1,string job1,string plan_load1,double balance1,double payment1,double credit,int n1){
    node *new_node = new node;
    new_node->id = id1;
    new_node->pass = pass1;
    new_node->name = name1;
    new_node->fname = fname1;
    new_node->mname = mname1;
    new_node->suportname = suportname1;
    new_node->address = address1;
    new_node->pin = pin1;
    new_node->job = job1;
    new_node->plan_load = plan_load1;
    new_node->phone = phone1;
    new_node->balance = balance1;
    new_node->payment = payment1;
    new_node->credit = credit ;
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
}
void pay::show_Record(){
    system("cls");
    SYSTEMTIME x;
    sqlite3_open("itc.db",&db);
    query = "SELECT rowid, * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK){
        cout<<" ERROR "<<sqlite3_errmsg<<endl;
    }else{
        while((result = sqlite3_step(stmt)) == SQLITE_ROW){
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
                 cout<<"\t\t\t\t\t"<<"    POSITION : "<< sqlite3_column_text(stmt, 0) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PIN : "<< sqlite3_column_text(stmt, 1) <<endl;
                 cout<<"\t\t\t\t\t"<<"    ID : "<< sqlite3_column_text(stmt, 2) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PASSWORD : "<< sqlite3_column_text(stmt, 3) <<endl;
                 cout<<"\t\t\t\t\t"<<"    NAME : "<< sqlite3_column_text(stmt, 4) <<endl;
                 cout<<"\t\t\t\t\t"<<"    FATHER NAME : "<< sqlite3_column_text(stmt, 5) <<endl;
                 cout<<"\t\t\t\t\t"<<"    MOTHER NAME : "<< sqlite3_column_text(stmt, 6) <<endl;
                 cout<<"\t\t\t\t\t"<<"    SUPORT NAME : "<< sqlite3_column_text(stmt, 7) <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< sqlite3_column_text(stmt, 8) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE : "<< sqlite3_column_text(stmt, 9) <<endl;
                 cout<<"\t\t\t\t\t"<<"    JOB : "<< sqlite3_column_text(stmt, 10) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PLAN : "<< sqlite3_column_text(stmt, 11)<<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< sqlite3_column_text(stmt, 12) <<endl;
                 cout<<"\t\t\t\t\t"<<"    CREDIT : "<< sqlite3_column_text(stmt, 14) <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< sqlite3_column_text(stmt, 13) <<endl;
                 cout<<"\t\t\t\t\t"<<"    NUMBER PAYBACK : "<< sqlite3_column_text(stmt, 15) <<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
                 cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	             cout<<"\t\t\t\t\t";
                 for(int j=0;j<=31;j++)
	             cout<<load;
	             cout<<"\n";
        }
        if(result != SQLITE_OK){
            cout<<" Error : "<<sqlite3_errmsg(db)<<endl;
        }else{
            cout<<"\n\n Search Successfully ... "<<endl;
        }
        cout<<"\n--------------------------------------------------------------------------------------------\n";
    }
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
                 cout<<"\t\t\t\t\t"<<"    PLAN : "<< ptr->plan_load <<endl;
                 cout<<"\t\t\t\t\t"<<"    ADDRESS : "<< ptr->address <<endl;
                 cout<<"\t\t\t\t\t"<<"    PHONE NUMBER : "<< ptr->phone <<endl;
                 cout<<"\t\t\t\t\t"<<"    BALANCE : "<< ptr->balance <<endl;
                 cout<<"\t\t\t\t\t"<<"    CREDIT : "<< ptr->credit <<endl;
                 cout<<"\t\t\t\t\t"<<"    PAYMENT : "<< ptr->payment <<endl;
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
void pay::payment(){
    string searchid;
    int id;
    const int timhe = 1 ;
    double withdarwDOLA;
    string again;
    p:
    cout<<"\n\n Enter ID FOR SEARCH :";
    cin>>searchid;

    result = sqlite3_open("itc.db",&db);
    query = "SELECT * FROM banana";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW){
        string Id = (const char *) (sqlite3_column_text(stmt,1));
        double balance = (sqlite3_column_double(stmt,11));
        double payment = (sqlite3_column_double(stmt,12));
        int time = (sqlite3_column_int(stmt,14));
        if(searchid == Id){
            cout<<"\n\n Input Position of ID :";
            cin>>id;

            cout<<"\n\n Currant DOLA BALANCE : ";
            cin>>withdarwDOLA;

            cout<<"\n\n DO YOU WANT TO WITHDRAW MONEY ?(YES/NP) : ";
            fflush(stdin);
            cin>>again;
            if(again == "YES" || again == "yes"){
                 if(withdarwDOLA >= payment){
                    balance -= withdarwDOLA;
                    time -= timhe;
                 }else{
                     cout<<"\n\n Payment is not Successfully "<<endl;
                     exit(0);
                 }
                 query = "UPDATE banana SET balance = ?, time = ? WHERE rowid = ?;";
                 result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
                 sqlite3_bind_double(stmt, 1, balance);
                 sqlite3_bind_int(stmt, 2, time);
                 sqlite3_bind_int(stmt, 3, id);

                 if(result != SQLITE_OK){
                     cout<<"ERROR : "<<sqlite3_errmsg(db)<<endl;
                 }else{
                     cout<<"Successfully "<<endl;
                 }
            }else if(again == "NO" || again == "no"){
                menu2();
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
void pay::deleteInformation(){
    int id;
    string again;
    SYSTEMTIME x;
    p:
    cout<<"\n Enter the [POSITION] of ID : ";
    cin>>id;
    getchar();
    GetSystemTime(&x);
    system("color 0B");
    cout<<"\n\t\t\t\t\t";
    for(int j=0;j<=36;j++)
    cout<<load;
    cout<<"\n";
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"  DO YOU WANT TO DELETE THAT [ID]  "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"           (YES/NO)                "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t"<<load<<"                                   "<<load<<endl;
    cout<<"\t\t\t\t\t";
    for(int j=0;j<=36;j++)
    cout<<load;
    cout<<"\n";
    cin>>again;
    if( again == "YES"){
        result = sqlite3_open("itc.db",&db);
        query = "DELETE FROM banana WHERE rowid = ?";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_bind_int(stmt, 1,id);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result == SQLITE_OK){
            cout<<" Delete Successfully ....\n";
        }else{
            cout<<" ERROR : "<<sqlite3_errmsg(db)<<endl;
        }
        cout<<"\t\t\t\t"<<load<<" Time : "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
    }else if(again == "NO"){
        cout<<"\n\n I DON'T WANT .....\n";
    }else{
        goto p;
    }
}
