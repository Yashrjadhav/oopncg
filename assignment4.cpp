#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class employee{
    public:
    int id;
    string name;
    float salary;
    string address;
    friend class student;

};
class student{
    public:
    string name1;
    int id1;
    string add;
    void input(employee &);
    void display(employee &);

};
void student::input(employee &state){
    ofstream state3;
    state3.open("file123.txt");
    cout<<"ENTER THE NAME OF EMPLOYEE:"<<endl;
    getline(cin,state.name);
    state3<<state.name<<endl;
    cout<<"ENTER THE ID OF EMPLOYEE:"<<endl;
    cin>>state.id;
    state3<<state.id<<endl;
    cout<<"ENTER THE ADDRESS OF EMPLOYEE:"<<endl;
    cin.ignore();
    getline(cin,state.address);
    state3<<state.address<<endl;
    cout<<"ENTER THE SALARY OF EMPLOYEE:"<<endl;
    cin>>state.salary;
    state3<<state.salary<<endl;
    cout<<"***********************************"<<endl;
    cout<<"ENTER THE NAME OF STUDENT:"<<endl;
    cin.ignore();
    getline(cin,name1);
    state3<<name1<<endl;
    cout<<"ENTER THE ID OF STUDENT:"<<endl;
    cin>>id1;
    state3<<id1<<endl;
    cout<<"ENTER THE ADDRESS OF STUDENT :"<<endl;
    cin.ignore();
    getline(cin,add);
    state3<<add<<endl;
    state3.close();
}
void student:: display(employee &state1){
    ifstream state5;
    state5.open("file123.txt");
    cout<<"READING THE FILE"<<endl;
    while(getline(state5,state1.name)){
        cout<<state1.name<<endl;
    }
    cout<<"CLOSING THE FILE"<<endl;
    state5.close();
}
int main(){
    student state11;
    employee state22;
    state11.input(state22);
    state11.display(state22);
}

