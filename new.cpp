#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    /*char name[50];
    cout<<"Enter the name: "<<endl;
    cin>>name;
    ofstream outFile("Text1.txt");
    outFile<<name;
    */
    ifstream myFile("Text1.txt");
    if(myFile.is_open())
    {
        char redName[50];
         myFile>>redName;
         cout<<"Name: "<<redName<<endl;
        
    }
    myFile.close();
    return 0;
}