#include <iostream>
#include <limits>
#include <unordered_map>
#include <string>
#include <random>
using namespace std;

class BankManagement
{
    int            account_no;
    std :: string    password;
    std :: string  first_name;
    std :: string   last_name;
    int            actualSold;
    int            send_money;
    public:
       void                input();
       void           get_acc_no();
       void    get_back_password();
       void          transaction();
       void         display_sold();
       void  display_information();
};
void BankManagement :: get_acc_no()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < 5; i++) {
        std::cout << dist(gen) << " ";
    }
}
void BankManagement :: input()
{
    cout<<"Enter Your passeword: "<<endl;
    getline(cin, password);
    cout<<"Enter the first Name: "<<endl;
    getline(cin, first_name);
    cout<<"Enter the last Name: "<<endl;
    getline(cin, last_name);
    cout<<"Enter your actual solde(sold <= 20,000$): "<<endl;
    cin>>actualSold;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void BankManagement :: display_sold()
{
   cout<<"Enter your password: "<<endl;
    getline(cin, password);
    string checkpassword;
    while(1)
    {
       if(checkpassword == "password" )
        {
          cout<<"PassWord: "<<password<<endl;
        }
        else if(checkpassword != "password")
        {
            cout<<"Invalide password. Try agin!"<<endl;
        }
        else
        {
            cout<<"Invalide input"<<endl;
        }
        break;
    }
}
void BankManagement :: transaction()
{
   int money_sended = 0;
   string choiceT;
   cout<<"Do you want to send money(yes/no): "<<endl;
   while(1)
   {
       if(choiceT == "yes" || choiceT == "Yes")
        {
           if(send_money != 0 && send_money <= actualSold)
            {
              money_sended = actualSold - send_money;
              cout<<"Your actual sold is: "<<money_sended<<endl;
            }
           else 
            {
               cout<<"Enter a valid amount!"<<endl;
            }
        }
       else if(choiceT == "no" || choiceT == "No")
       {
          cout<<"Thank you."<<endl;
          break;
       }
      else
       {
         cout<<"Invalide input!Try agian."<<endl;
       }
    }
}
void BankManagement :: display_information()
{
    cout<<"Enter the Account number: "<<endl;
    cin>>account_no;
    int checkAcc;
    while(1)
    {
        if(checkAcc != account_no)
        {
           cout<<"Invalid Account No! Please try again."<<endl;
        }
        else
        {
          cout<<"account_no                       : "<<" "<<endl;
           cout<<"Password                        : "<<password<<endl;
           cout<<"First Name                      : "<<first_name<<endl;
           cout<<"Last Name                       : "<<last_name<<endl;
           cout<<"Actual sold without transaction : "<<actualSold<<endl;
        }
    }
    
}

int main()
{
    BankManagement first;
    //first.get_acc_no();
    //first.input();
    //first.display_sold();
    first.transaction();
    return 0;
}
