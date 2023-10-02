// #include <iostream>
// #include<iomanip>
// using namespace std;
// class Account{
//   string name;
//   long int accountNo;
//   long int balance;
//   public:
//   Account(){
//       name = "";
//       accountNo = 0;
//       balance = 0;
//   }
//   Account(string name, long int accountNo, long int balance){
//       name = name;
//       accountNo = accountNo;
//       balance = balance;
//   }
//   void setData(){
//     cout<<"Enter name : ";            getline (cin,name);
//     cout<<"Enter account number : ";  cin>>accountNo;
//     cout<<"Enter balance : ";         cin>>balance;
//   }
//   void display()
//     cout<<setw(20)<<name<<setw(20)<<accountNo<<setw(20)<<balance<<endl;
//   Account transferBalance(Account A2, long int transferbalance){
//       if (balance >= transferbalance){
//           balance -= transferbalance;
//           A2.balance += transferbalance;
//       }
//       else
//           cout<<endl<<"Sorry! Transfer failed! Reason: Insufficient Balance."<<endl;
//       return A2;
//   }
// };
// int main(){
//   Account A1, A2;
//   long int tb;
//   cout<<"Enter Details of transfering Account(Account 1)"<<endl;
//   A1.setData();
//   cout<<endl<<"Enter Details of receiving Account(Account 2)"<<endl;
//   cin.ignore(); 
//   A2.setData();
//   cout<<endl<<"Enter total amount which you want to transfer from Account 1 to Account 2: ";
//   cin>>tb;
//   A2 = A1.transferBalance(A2, tb);
//   cout<<endl;
//   cout<<setw(29)<<"Name"<<setw(15)<<"Accno"<<setw(15)<<"Balance"<<endl;
//   cout<<"Account 1";A1.display();
//   cout<<"Account 2";A2.display();
//   return 0;  
// }





















