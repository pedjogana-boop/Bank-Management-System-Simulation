#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <limits>
using namespace std;

class MathematicBook
{
    string title;
    int Id;
    string author;
    string publisher;
    string year_of_publication;
    public:
     void inputMath()
     {
        cout<<"Enter the title of the book: "<<endl;
        getline(cin, title);
        cout<<"Enter the ID of the book: "<<endl;
        cin>>Id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the author of the book: "<<endl;
        getline(cin, author);
        cout<<"Enter the publisher of the book: "<<endl;
        getline(cin, publisher);
        cout<<"Enter the year of publication: "<<endl;
        getline(cin, year_of_publication);
     }
     void displayMath()
     {
        cout<<"Title              : "<<title<<endl;
        cout<<"ID                 : "<<Id<<endl;
        cout<<"Author             : "<<author<<endl;
        cout<<"Publisher          : "<<publisher<<endl;
        cout<<"Year of Publication: "<<year_of_publication<<endl;
     }
};

class PhysicsBook
{
    string title;
    int Id;
    string author;
    string publisher;
    string year_of_publication;
    public:
     void inputPhysic()
     {
        cout<<"Enter the title of the book: "<<endl;
        getline(cin, title);
        cout<<"Enter the ID of the book: "<<endl;
        cin>>Id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the author of the book: "<<endl;
        getline(cin, author);
        cout<<"Enter the publisher of the book: "<<endl;
        getline(cin, publisher);
        cout<<"Enter the year of publication: "<<endl;
        getline(cin, year_of_publication);
     };
     void displayBookDataPhysic()
     {
        cout<<"Title              :  "<<title<<endl;
        cout<<"ID                 :  "<<Id<<endl;
        cout<<"Author             :  "<<author<<endl;
        cout<<"Publisher          :  "<<publisher<<endl;
        cout<<"Year of Publication:  "<<year_of_publication<<endl;
     }
};

int main()
{
    int n = 0, l;
    char choice, choice2, choice3;
    char add, display;
    int opt;
    
    cout<<"Enter the number of Mhat & Physics books: "<<endl;
    cin>>n;
    
    MathematicBook* Math = new MathematicBook[n];
    PhysicsBook* Phys = new PhysicsBook[n];
    
    cout<<"You want to do somthing(Yes(y)/No(n)): "<<endl;
    cin>>choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(1)
    {
        if(choice == 'Y' || choice == 'y')
        {
            cout<<"Enter Options(1.Add Books / 2.Display Books): "<<endl;
            cin>>opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            switch(opt)
            {
                case 1:
                  cout<<"Add Books?"<<endl;
                  cin>>add;
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  
                  if(add == 'Y' || add == 'y')
                  {
                       cout<<"Information: "<<endl;
                       //cout<<"Enter the number of Mhat & Physics books: "<<endl;
                       //cin>>n;
                       for(int i=0; i<n; i++)
                       {
                           cout<<"Enter book type (M for Mathematics / P for Physics): "<<endl;
                           cin>>choice2;
                           cin.ignore(numeric_limits<streamsize>::max(), '\n');
                           
                           switch(choice2)
                           {
                                case 'M':
                                    cout<<"Mathematics"<<endl;
                                    Math[i].inputMath();
                                    break;
                                case  'P':
                                    cout<<"Physics: "<<endl;
                                    Phys[i].inputPhysic();
                                    break;
                                default:
                                    cout<<"Error! Please enter the correct input."<<endl;
                            }
                       }

                    }
                  else if(add == 'N' || add == 'n')
                  {
                    cout<<"Thank you."<<endl;
                    break;
                  }
                  else
                  {
                    cout<<"Try agin!"<<endl;
                  }
                  break;
                case 2:
                   cout<<"Display?"<<endl;
                   cin>>display;
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   
                   if(display == 'Y' || display == 'y')
                   {
                      cout<<"Which kind of books you want to display?"<<endl;
                      for(int i=0; i<n; i++)
                      {
                          cout<<"Enter book type (M for Mathematics / P for Physics): "<<endl;
                          cin>>choice3;
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          
                          switch(choice3)
                          {
                                case 'M':
                                  cout<<"\n"<<"-------------------"<<endl;
                                  Math[i].displayMath();
                                  break;
                                case 'P':
                                   cout<<"\n"<<"-------------------"<<endl;
                                   Phys[i].displayBookDataPhysic();
                                   break;
                                default:
                                   cout<<"Error! Please enter the correct input."<<endl;
                          }
                      }
                   }
                   else if(display == 'N' || display == 'n')
                    {
                        cout<<"Thank you!"<<endl;
                    }
                   else
                    {
                       cout<<"Error input! Try again please."<<endl;
                    }
                  
            }

        }

        else if(choice == 'N' || choice == 'n')
        {
            cout<<"Thank You!"<<endl;
            break;
        }
        else
        {
        cout<<"Wrong input! Try again."<<endl;
        }
    }
    return 0;
}