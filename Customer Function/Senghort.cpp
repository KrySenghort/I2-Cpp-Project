void link::withdraw(){
    p:
    system("cls");
    fstream file,file1;
    node *ptr ;
    string t_id,emp_id,id;// it is the id that we scan from user and use to connect to data .មានស្រាប់.ដើម
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
    }
    else{
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
                    }
                    else{
                        cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balance<<"  is Less...";
                        cout<<"\n\n\t\t\t Your Current Balance  "<<emp_balanceriel<<"  is Less...";
                    }
                }
                else if(again == "no" || again == "No" ){
                    break;
                }
                else{
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
                }
                else if(again == "no" || again == "No"){
                    break;
                }
                else{
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
    }
    else{
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
    }
    else{
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







