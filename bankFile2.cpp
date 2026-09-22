#include <iostream>
#include <limits>
#include <unordered_map>
#include <string>
#include <random>
#include <fstream>
using namespace std;

class BankManagement
{
    int            account_no;
    std :: string   password1;
    int             pin_code;
    std :: string  first_name;
    std :: string   last_name;
    int     actualSold = 20000;
    int            send_money;
    public:
       //void                input();
       void           get_acc_no();
       void          pin_code_input();
       void          pin_code_reading();
       void         intermediar1();
       void         intermediar2();
       void         checkBalance();
       void            createPassword();
       bool            access();
       //int            validadtion_transaction();
       //void    get_back_password();
       void          transaction();
       //void         display_sold();
       //void  display_information();
};
void BankManagement :: get_acc_no()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < 5; i++)
    {
        std::cout << dist(gen) << " ";
    }
}
void BankManagement :: intermediar1()
{
    fstream MyFile;
    cout<<"\n"<<"Account Number: "<<endl;
    MyFile.open("Mohamed.txt", ios::out);
    if(MyFile.is_open())
    {
        get_acc_no();
        MyFile.close();
    }
}
void BankManagement :: intermediar2()
{
    //cout<<"Enter Your actual sold: "<<endl;
    //cin>>actualSold;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    fstream MyFile2;
    MyFile2.open("Sold.txt", ios:: out);
    if(MyFile2.is_open())
    {
       MyFile2<<"Actual Sold: "<<actualSold<<endl;
       MyFile2.close();
    }

}


void BankManagement :: pin_code_input()
{
    cout<<"Creat your pin code to confirm transaction: "<<endl;
    cin>>pin_code;
    fstream MyFile3;

    cout<<"Your pin code is set to: "<<pin_code<<endl;
    MyFile3.open("PinCode.txt", ios::out);
    if(MyFile3.is_open())
    {
        MyFile3<<pin_code;
        MyFile3.close();
    }
}

/*void BankManagement :: pin_code_reading()
{
        fstream MyFile3;
        MyFile3.open("PinCode.txt", ios::in);
        if(MyFile3.is_open())
        {
            int storedPin;
            MyFile3>>storedPin;
            MyFile3.close();
        }
}*/

void BankManagement :: transaction()
{
    // Read current balance from file
    fstream MyFile2;
    MyFile2.open("Sold.txt", ios::in);
    if(MyFile2.is_open())
    {
        string line;
        getline(MyFile2, line);
        // Assuming format: "Actual Sold: 20000"
        size_t pos = line.find(": ");
        if(pos != string::npos)
        {
            actualSold = stoi(line.substr(pos + 2));
        }
        MyFile2.close();
    }

    ///file reading pin code;
     fstream MyFile3;
        MyFile3.open("PinCode.txt", ios::in);
        if(MyFile3.is_open())
        {
            int storedPin;
            MyFile3>>storedPin;
            MyFile3.close();
        }

    string choice1;
    int choice2;
    cout<<"\n"<<"++++++ Transaction Module ++++++"<<"\n";
    cout<<"Hi!"<<endl;
    while(1)
    {
        cout<<"Do you want to do something(yes/no)? "<<endl;
        cin>>choice1;
        if(choice1 == "yes" || choice1 == "Yes")
        {
            cout<<"Enter your choice: 1.Check_Balance, 2.Send_Money, 3.Check_new_balance: "<<endl;
            cin>>choice2;
            switch(choice2)
            {
                case 1:
                    cout<<"Check your Balance: "<<actualSold<<endl;
                    break;
                case 2:
                    cout<<"Send Money: "<<endl;
                    cout<<"Enter amount to send: "<<endl;
                    cin>>send_money;
                    if(send_money > actualSold)
                    {
                        cout<<"Insufficient sold!"<<endl;
                    }
                    else if(send_money > 0 && send_money <= actualSold)
                    {
                        /*cout<<"Enter your pin code to confirm transaction: "<<endl;
                        int pin_code;
                        cin>>pin_code;*/
                        actualSold -= send_money;
                        int code;
                        cout<<"Enter your pin code to confirm transaction: "<<endl;
                        cin>>code;
                        if(code == pin_code)
                        {
                            cout<<"Transaction confirmed."<<endl;
                            cout<<"Money sent successfully"<<endl;
                            // Write new balance to file
                            MyFile2.open("Sold.txt", ios::out);
                            if(MyFile2.is_open())
                            {
                              MyFile2<<"Actual Sold: "<<actualSold<<endl;
                              MyFile2.close();
                            }

                        }
                        else{
                            cout<<"Invalid pin code. Transaction cancelled."<<endl;
                        }

                        /*cout<<"Money sent successfully"<<endl;
                        // Write new balance to file
                        MyFile2.open("Sold.txt", ios::out);
                        if(MyFile2.is_open())
                        {
                            MyFile2<<"Actual Sold: "<<actualSold<<endl;
                            MyFile2.close();
                        }*/
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                    break;
                case 3:
                    cout<<"Check new Balance: "<<actualSold<<endl;
                    break;
                default:
                   cout<<"Enter the valid input"<<endl;
                   break;
            }
            
        }
        else if(choice1 == "no" || choice1 == "No")
        {
            cout<<"Thank You!"<<endl;
            break;
        }
        else
        {
          cout<<"Invalid input"<<endl;
          cout<<"Try again!"<<endl;
        }
    }
}

void BankManagement :: createPassword()
{
    //string storedPassword1;
    //password1 = storedPassword1;
    cout<<"Creat your password(maximu 8 characters): "<<endl;
    getline(cin, password1);
    ofstream MyPassword;
    MyPassword.open("Password2.txt", ios::out);
    MyPassword<<password1;
    MyPassword.close();

    /*if(MyPassword.is_open())
    {
        MyPassword<<password1;
        MyPassword.close();
    }*/
}
bool BankManagement :: access()
{
    string userPassword2;
    string storedPassword2;

    cout<<"Enter your password: ";
    getline(cin, userPassword2);

    ifstream MyPassword("Password2.txt", ios::in);
    getline(MyPassword, storedPassword2);
    MyPassword.close();

    if(userPassword2 == storedPassword2)
        return true;
    else
        return false;
}
int main()
{
    BankManagement first;
    first.createPassword();
    first.pin_code_input();

    /*first.get_acc_no();
    first.intermediar1();
    first.intermediar2();
    first.transaction();
    */
   int mainChoice1;
   string mainChoice2;
   //string userPassword2;
   while(true)
   {
     cout<<"You want to Access to your account(yes or no)?  "<<"\n";
     cin>>mainChoice2;
     cin.ignore();

     if(mainChoice2 == "yes" || mainChoice2 == "Yes")
     {
        /*cout<<"Enter your Password: "<<endl;
        getline(cin, userPassword2);
        ifstream MyPassword("Password1.txt", ios::in);*/
        if(first.access())
        {
            cout<<"Access granted"<<endl;
            //return false;
            //break;

            first.get_acc_no();
            first.intermediar1();
            first.intermediar2();
            first.transaction();
        
        }
        else
        {
            cout<<"Wrong password, try again!"<<endl;
        }
     }
     else if(mainChoice2 == "no" || mainChoice2 == "No")
     {
        cout<<"Thank you!"<<endl;
        break;
     }
     else{
        cout<<"Please enter the valid input!"<<"\n";
     }
    }

    return 0;
}