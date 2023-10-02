#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include<cctype>
#include<stdlib.h>
#include<sqlite3.h>

using namespace std;
 static  callbackSelect(void *NotUsed, int argc, char**value,char **colName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s =%s\n",colName[i],value[i]);
    }
    printf("\n");
    return 0;
}


class BankAccount {



private:
    int acc;
	char name[50];
	int deposit1;
	char type;
    string pinNum;
    char accType;
    double balance;
    double amount;

public:


    BankAccount(){

        balance = 0.0;
        amount = 0.0;
    }

    void create_BankAccount();
	void show_BankAccount() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
    void again();
    void welcome();
    void pinNumber();
    void accountType();
    void balanceChecking();
    void balanceSavings();
    void deposit();
    void withdraw();
    void display();
    void write_account();
    void display_sp(int);
    void modify_account(int);
    void delete_account(int);
    void display_all();
    void deposit_withdraw(int, int);
    void infromation();

};
void   BankAccount:: again()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t                        _                              "<<endl;
    cout<<"\t\t\t\t\t                 | |    ___     ___     _ ___ ___     ___ "<<endl;
    cout<<"\t\t\t\t\t    \\ \\ /\\ / /  / _ \\  | |   / |   / _ \\   | '_  '_  \\   / _ \\"<<endl;

    cout<<"\t\t\t\t\t     \\ v  v /  | ___/  | |  | (__   | (_) |  | | | | | |  | ___/  "<<endl;

    cout<<"\t\t\t\t\t      \\_/\\_/    \\___|  |_|   \\___|   \\___/   |_| |_| |_|   \\___|  "<<endl;
}
void BankAccount::welcome()
{
    cout<<endl;
    cout<<"========================================================================="<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"****************     B A N K   M A N A G E M E N T      *****************"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"***************************   S Y S T E M   *****************************"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"PROJECT : BANK MANAGEMENT"<<endl;
    cout<<"MADE BY : CHHON CHAINA CHOU VANDY LONG CHANNLEAP         "<<endl;
    cout<<endl;
    cout<<"----         PROJECT OF CARLOS HILADO MEMORIAL STATE UNIVERSITY      ----"<<endl;
    cout<<"========================================================================="<<endl;
    cin.get();
}
void BankAccount::pinNumber()
{
    cout << "-------------------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t        ATM TRANSACTION" << endl;
    cout << "--------------------------------------------------------------------------------------------------------";

    cout << "\n\t\t\t        ENTER PIN NUMBER: \n" <<endl;
    cout << "\t\t\t\t      ";
    for(int i = 0; i <= 3; i++) {

        char ch;
        cout << setw(1);
        ch = _getch();
        while(ch != 13){
            pinNum.push_back(ch);
            cout << '*';
            ch = _getch();
        }


        if(pinNum == "1234") {
            cout << "\n\n\t\t\t   Welcome to your account!" << endl;

            display();


            while(!(cin >> pinNum)) {

                cin.clear();

                while (cin.get() != '\n')
                    continue;

                cout << "\n\t\t\t   Please enter a numeric Pin:  ";
            }


        } else if (i >= 4) {
            cout << "\n\t\t\t   You account is Locked!\n";
            cout << "\t\t\t   You have reached the limit of tries." << endl;

        } else {
            cout << "\n\t\t\t   Invalid Pin Number \n";
            cout << "\t\t\t   Enter Pin Number Again: \n";
            cout << "\t\t\t\t   ";
            cin >> pinNum;
        }
    }
}


void BankAccount::accountType(){
    cout << "\n\t\t\t Select Account Type:\n";
    cout << "\t\t\t Checking 'C' or Savings 'S': ";
    cin >> accType;


    if(accType == 'C' || accType == 'c') {
        cout << "\t\t\t================================" << endl << endl;
        cout << "\t\t\t\tChecking Account" << endl << endl;
        cout << "\t\t\t================================" << endl << endl;

    } else if (accType == 'S' || accType == 's') {
        cout << "\t\t\t================================" << endl << endl;
        cout << "\t\t\t\tSavings Account" <<endl << endl;
        cout << "\t\t\t================================" << endl << endl;
    } else {
        cout << "\t\t\tInvalid Account Type.\n";
        cout << "\t\t\tSelect Account Type: 'C' or 'S': ";



        cin >> accType;
    }
}
void BankAccount::deposit(){
    cout << "\n\t\t\t\t    DEPOSIT\n";
    cout << "\t\t\t   Enter Deposit Amount $";
    cin >> amount;
    cout << "\n\t\t\t========Deposit Receipt========" << endl << endl;
    cout << setprecision(2) << fixed; //round decimal 2 places
    cout << "\t\t\t Amount Deposited = $" << amount << endl << endl;
    balance += amount;
    cout << "\t\t\t New balance $" << balance << endl << endl;
    cout << "\t\t\t===============================" << endl;
}
void BankAccount::withdraw(){
    cout << "\n\t\t\t\t    WITHDRAW\n";
    cout << "\t\t\t   Enter Withdraw Amount $";
    cin >> amount;
    cout << "\n\t\t\t=======Withdraw Receipt==========" << endl << endl;
    cout << "\t\t\t Amount withdrawn = $" << amount << endl << endl;
    balance -= amount;
    cout << "\t\t\t New balance $" << balance << endl <<endl;
    cout << "\t\t\t=================================" << endl;
}


void BankAccount::balanceChecking() {
    cout <<"\n\t\t\t=====Checking Account Balance=====";
    cout << "\n\t\t\t Checking Account # xxxxxxxx4567\n";
    //balance = 10000;
    cout << "\n\t\t\t Balance = $" << balance << endl;
    cout <<"\n\t\t\t==================================" << endl;
}


void BankAccount::balanceSavings() {
    cout << "\n\t\t\t=====Savings Account Balance=====";
    cout << "\n\t\t\t Savings Account # xxxxxxxx8901\n";

    cout << "\n\t\t\t Balance = $" << balance << endl;
    cout << "\n\t\t\t=================================" << endl;
}

void BankAccount::create_BankAccount()
{
	cout<<"\nEnter The BankAccount No. :";
	cin>>acc;
	cout<<"\n\nEnter The Name of The BankAccount Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The BankAccount(Current(C)/Saving(S)): ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=10000 for current ) : ";
	cin>>deposit1;
	cout<<"\n\n\nBankAccount Created..";
}
void BankAccount::show_BankAccount() const{
	cout<<"\nAccount No. : "<<acc;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit1;
}
void BankAccount::modify(){
	cout<<"\nBankAccount No. : "<<acc;
	cout<<"\nModify BankAccount Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of BankAccount : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit1;
}
void BankAccount::dep(int x){
	deposit1+=x;
}
void BankAccount::draw(int x){
	deposit1-=x;
}
void BankAccount::report() const{
	cout<<acc<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit1<<endl;
}
int BankAccount::retacno() const{
	return acc;
}
int BankAccount::retdeposit() const{
	return deposit1;
}
char BankAccount::rettype() const{
	return type;
}
void BankAccount::display(){
    int options = 1;
    int num;
    while( options != 0 ) {
        cout << "\n\t\t\t  1. Select Account Type\n";
        cout <<  "\t\t\t   2.Again\n  ";
        cout <<"\t\t\t\    3.AccounType\n";
		cout << "\t\t\t    4. Deposit\n";
        cout << "\t\t\t    5. Withdraw\n";
        cout << "\t\t\t    6. Checking Account Balance\n";
        cout << "\t\t\t    7. Savings Account Balance\n";
        cout << "\t\t\t    8. New Account\n";
		cout <<"\t\t\t     9. DEPOSIT AMOUNT\n";
		cout <<"\t\t\t     10. WITHDRAW AMOUNT\n";
		cout <<"\t\t\t     11. BALANCE ENQUIRY\n";
		cout <<"\t\t\t     12. ALL ACCOUNT HOLDER LIST\n";
		cout <<"\t\t\t     13. CLOSE AN ACCOUNT\n";
		cout <<"\t\t\t     14.Information\n";
		cout <<"\t\t\t     15. EXIT\n";

        cout <<"\n\t\t\t\t\t";
        cin >> options;


        switch (options) {

            case 0:again();
            case 1:welcome();
            case 2: pinNumber();
                break;
            case 3: accountType();
                break;
            case 4: deposit();
                break;
            case 5: withdraw();
                break;


            case 6: balanceChecking();
                break;
            case 7: balanceSavings();
                break;
            case 8:
			write_account();
			break;
		    case 9:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		   case 10:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		   case 11:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
           case 12:
			display_all();
			break;
		   case 13:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		  case 14:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
          case 15:infromation();

		  case 16:
			cout<<"\n\n\tThanks for using bank management system!\n";
			break;
		 default: cout << "\n\t\t\t   Invalid Option" << endl;
		}
		cin.ignore();
		cin.get();
	}
}

void BankAccount::write_account()
{
	BankAccount ac;
	ofstream outFile;
	outFile.open("BankAccount.dat",ios::binary|ios::app);
	ac.create_BankAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
	outFile.close();
}
void BankAccount::display_sp(int n)
{
	BankAccount ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.retacno()==n)
		{
			ac.show_BankAccount();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void BankAccount::modify_account(int n)
{
	bool found=false;
	BankAccount ac;
	fstream File;
	File.open("BankAccount.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		if(ac.retacno()==n)
		{
			ac.show_BankAccount();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(BankAccount));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void BankAccount::delete_account(int n){
	BankAccount ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount))){
		if(ac.retacno()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		}
	}
	inFile.close();
	outFile.close();
	remove("BankAccount.dat");
	rename("Temp.dat","BankAccount.dat");
	cout<<"\n\n\tRecord Deleted ..";
}
void BankAccount::display_all(){
	BankAccount ac;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount))){
		ac.report();
	}
	inFile.close();
}
void BankAccount::deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	BankAccount ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		if(ac.retacno()==n){
			ac.show_BankAccount();
			if(option==1){
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2){
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void BankAccount::infromation(){
    sqlite3 *db;
    char *zErrMsg=0;
    int rc;
    char *sqlCreate, *sqlInsert, *sqlSelect, *sqlUpdate,*sqlDelete;
    const char*data="Callback funtion called";
    /* Opened Database */
    rc=sqlite3_open("test.db",&db);
    /* Create SQL statement*/
    sqlCreate="CREATE TABLE mydatabasce(" \
    "ID INT PRIMARY KEY    NOT NULL,"\
    "NAME           TEXT   NOT NULL,"\
    "SEX            TEXT   NOT NULL,"\
    "AGE            INT    NOT NULL,"\
    "DATE_OF_BIRTH  TEXT   NOT NULL,"\
    "PLACE_OF_BIRTH TEXT   NOT NULL,"\
    "EMAIL_ADDRESS  TEXT   NOT NULL,"\
    "ADDRESS        CHAR(50),"\
    "PHONE_NUMBER   TEXT   NOT NULL,"\
    "SALARY         REAL );";
    rc=sqlite3_exec(db,sqlCreate,NULL,0,&zErrMsg);
    /* Create SQL statement*/
    sqlInsert="INSERT INTO mydatabasce(ID,NAME,SEX,AGE,DATE_OF_BIRTH,PLACE_OF_BIRTH,EMAIL_ADDRESS,ADDRESS,PHONE_NUMBER,SALARY)" \
              "VALUES (3, 'Paul','Male', 32,'11/04/2001','Pailin province','juradypailin@gmail.com', 'Batdombang','0887765440', 20000.00);"\
              "INSERT INTO mydatabasce(ID,NAME,SEX,AGE,DATE_OF_BIRTH,PLACE_OF_BIRTH,EMAIL_ADDRESS,ADDRESS,PHONE_NUMBER,SALARY)" \
              "VALUES (6, 'Chou vandy','Male', 45,'10/12/2002','Battombang province','jurady123pailin@gmail.com', 'Batdombang','067602606', 25000.00);";
    /*Execute SQL statement*/
    rc=sqlite3_exec(db,sqlInsert,NULL,0,&zErrMsg);
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
   sqlUpdate = "UPDATE mydatabasce set SALARY =2504.00 where ID=1; " \
         "SELECT * from mydatabasce";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sqlUpdate,NULL, (void*)data, &zErrMsg);

    sqlite3_close(db);


}

int main()
{


    system("color 0D");

    BankAccount bank;
    bank.again();
    bank.welcome();
    bank.pinNumber();
    bank.accountType();
    bank.balanceChecking();
    bank.balanceSavings();
    bank.deposit();
    bank.withdraw();
    bank.create_BankAccount();
    bank.show_BankAccount();
    bank.modify();

    bank.report() ;
    bank.retacno();
    bank.retdeposit();
    bank. rettype();
    bank.infromation();


    return 0;
}
