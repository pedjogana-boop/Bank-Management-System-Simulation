#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream myFile;
    myFile.open("Ouattara.txt", ios::out);
    if(myFile.is_open())
    {
        myFile<<"Hello World!"<<endl;
        myFile<<"I'm learning C++ file handling."<<endl;
        myFile<<"I'm Ouattara."<<endl;
        myFile.close();
    }

    myFile.open("Ouattara.txt", ios::app);
    if(myFile.is_open())
    {
        myFile<<"I like coding and one day i will become a real Developer and build great software."<<endl;
        myFile<<"Just focus on your goal and never give up."<<endl;
        myFile.close();
    }

    myFile.open("Ouattara.txt", ios::in);
    if(myFile.is_open())
    {
        string ReadLine;
        while(getline(myFile, ReadLine))
        {
            cout<<ReadLine<<endl;
        }
    }
    myFile.close();
    return 0;
}