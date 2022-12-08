/*PROBLEM STATEMENT:
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class file{
    public:
    string str1,str2,str;
    void write(){
        ofstream state1;
        state1.open("xyz.txt");
        cout<<"ENTER THE DATA IN THE FILE: "<<endl;
        getline(cin,str1);
        state1<<str1;
        state1.close();
        cout<<"CLOSING THE FILE!!!!!"<<endl;
    }
    void append()
    {
        ofstream state;
        state.open("xyz.txt",ios::app);
        cout<<"ENTER THE DATA YOU WANT TO APPEND IN THE FILE:"<<endl;
        getline(cin,str);
        state<<str;
        state.close();
        cout<<"CLOSING APPENDED FILE!!! "<<endl;
    }
    void read(){
        ifstream state2("xyz.txt");
        cout<<"YOUR READ DATA IS :"<<endl;
        while(getline(state2,str2)){
            cout<<str2;
        }
        state2.close();
    }
};
int main(){
    file state3;
    state3.write();
    state3.append();
    state3.read();
    return 0;
}