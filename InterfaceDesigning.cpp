#include <iostream>
#include <string>
#include <limits>
using namespace std;

class student
{
   std :: string name;
   int age;
   public:
   void studentInput()
   {
      cout<<"Enter name: "<<endl;
      getline(cin, name);
      cout<<"Enter age: "<<endl;
      cin>>age;
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
   }
   void studentDisplay()
   {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
   }
};

class teacher
{
   std :: string name;
   int age;
   public:
   void teacherInput()
   {
       cout<<"Enter name: "<<endl;
      getline(cin, name);
      cout<<"Enter age: "<<endl;
      cin>>age;
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
   }
   void dteacherDsplay()
   {
     cout<<"Name: "<<name<<endl;
     cout<<"Age: "<<age<<endl;
   }
};

class calculator
{
   int a,b,c;

   public:
   int addition();
   int multiply();
   float division();
   void calculatorDisplay();
   void calculatorInput()
   {
        cout<<"Enter the first number: "<<endl;
        cin>>a;
        cout<<"enter the second number: "<<endl;
        cin>>b;
        cout<<"Enter the third number: "<<endl;
        cin>>c;
   }
};

int  calculator :: addition()
{
    int sum = 0;
    sum = a + b + c;
    return sum;
}

int calculator :: multiply()
{
    int product = 1;
    product = a * b * c;
    return product;
}

float calculator :: division()
{
    float div1, div2, div3;
    if (a!=0 && b!=0)
    {
        div1 = a / b;
        return div1;
    }
    else if(b!=0 && c!=0)
    {
        div2 = b / c;
        return div2;
    }
    else if (a!=0 && c!=0)
    {
        div3 = a / c;
        return div3;
    }
    else{
        cout<<"Division by zero is not allowed."<<endl;
        return 0;
    }
}
void  calculator :: calculatorDisplay()
{
    string operation;
    cout<<"Choose one operation: (A)addition (M)multiplication (D)Division"<<endl;
    cin>>operation;
    switch(operation[0])
    {
        case 'A':
              cout<<"The Addition is: "<<addition()<<endl;
              break;
        case 'M':
              cout<<"The Multiplication is: "<<multiply()<<endl;
              break;
        case 'D':
                cout<<"The Division is: "<<division()<<endl;
                break;
        default:
                cout<<"Invalide operation!"<<endl;
                break;

    }
    
}

int main()
{
    student first_st;
    teacher first_tc;
    calculator calc;
    int choice;
    string answer;
    cout<<"You Want to Enter somthing (yes/no)?"<<endl;
    getline(cin, answer);
    while(1)
    {
        if( answer == "yes" || answer == "Yes")
        {
           cout<<"Choose one option: 1.student 2.teacher 3.calculator 4.exist"<<endl;
           cin>>choice;
           cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
           switch(choice)
           {
                 case 1:
                       first_st.studentInput();
                       first_st.studentDisplay();
                       break;
                case 2:
                       first_tc.teacherInput();
                       first_tc.dteacherDsplay();
                       break;
                case 3:
                          calc.calculatorInput();
                          calc.calculatorDisplay();
                          break;
                case 4:
                            cout<<"Exiting the program."<<endl;
                            return 0;

           }

        }
        else if(answer == "no" || answer == "No")
        {
            cout<<"Thank You!"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Input!"<<endl;
            cout<<"Try again!"<<endl;
        }
    }
   
    return 0;

}