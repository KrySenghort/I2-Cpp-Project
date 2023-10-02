// #include<iostream>
// using namespace std;
// void back::transfer(){
//     fstream file,file1;
//     system("cls");
//     string s_id,r_id;
//     float amount;
//     int found = 0;
//     cout<<"\n\n\t\t\t Payment Transfer option ";
//     file.open("bank.txt",ios::in);
//     if(!file){
//         cout<<"\n\n File Opening Error...";
//     }else{
//         cout<<endl<<endl<<" Enter User ID for Transection : ";
//         cin>>s_id;
//         cout<<endl<<endl<<" Reciver User ID for Transfer ";
//         cin>>r_id;
//         cout<<" Enter Transfer Amount : ";
//         cin>>amount;
//         file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
//         while(!file.eof()){
//             if(s_id == id)
//                 found++;
//             else if(r_id == id)
//                 found++;
//             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
//         }
//         file.close();
//         if(found == 2){
//             file.open("bank.txt",ios::in);
//             file1.open("bank1.txt",ios::app|ios::out);
//             file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
//             while(!file.eof()){
//                 if(s_id == id ){
//                     balance -= amount;
//                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
//                 }else if(r_id == id ){
//                      balance += amount;
//                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
//                 }else{
//                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
//                 }
//                 file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
//             }
//             file.close();
//             file1.close();
//             remove("bank.txt");
//             rename("bank1.txt","bank.txt");
//             cout<<"\n\n\t\t\t Transfer Successfully...";

//         }else{
//             cout<<"\n\n\t\t\t Both Transction User ID's Invalid...";
//         }
//     }
// }
// int main(){
//     return 0;
// }


















