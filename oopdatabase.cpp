/*
Problem statement:
Develop an stateect oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation operators-new and delete.
*/
#include <iostream>
#include <string.h>
using namespace std;
class personalinfo{      //creating a class
    string license,dob,bloodgrp;
    public:
    personalinfo();       // making a default constructor
    personalinfo(personalinfo &);// making a copy constructor and will be passing state of the class
    ~personalinfo(){      // this is a destructor and will be called after the block of code is executed
        cout<<"THE DESTRUCTOR FOR CLASS PERSONALINFO IS CALLED"<<endl<<"RECORD DELETED SUCCESSFULLY!!!"<<endl;
    }
    friend class student;

};
class student{     //creating a class
    string  name ,address ,year ,division ;
    int roll_no;
    long mob_no;
    static int count;
    public:
    void create(personalinfo &);// this is a function taking state as an argument of classes and why? that we will see below
    void display(personalinfo &);
    inline static void incount(){// this is a inline static function which improves the execution time and static for making it restricted
        count++;
    }
    inline static void displaycnt(){
        cout<<"~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
        cout<<"THE TOTAL NO. OF RECORDS ARE: "<<count<<endl;
    }
    student();// a default constructor again
    student(student &);//a copy constructor ready to take arguments as stateects
    ~student(){ //destructor
        cout<<"DESTRUCTOR FOR CLASS STUDENT IS CALLED "<<endl<<"RECORD DELETED SUCCESFULLY!!!"<<endl;
    }

};
int student::count;
student::student(){  //default constructor assigning some default values to variables
    name="YASH JADHAV";
    address="flat no 202 kapoorstreet mumbai";
    year="SE COMPUTER";
    division='P';
    roll_no=13;
    mob_no=942329999;
}
personalinfo::personalinfo(){ //same here
    license="ABD45656";
    dob="02/11/1997";
    bloodgrp="A+";
}
student::student(student &state){  // a copy constructor which has argument as the state of same class 
    this->name=state.name;
    this->address=state.address;
    this->year=state.year;
    this->division=state.division;
    this->roll_no=state.roll_no;
    this->mob_no=state.mob_no;
}
personalinfo::personalinfo(personalinfo &state){  // same here
    license=state.license;
    dob=state.dob;
    bloodgrp=state.bloodgrp;
}
void student::create(personalinfo &state){ // taking inputs where the state in the arguments helps  to includes the variables of another class is same function
    cout<<"*************************"<<endl;
    cout<<"ENTER YOUR NAME: "<<endl;
    cin>>name;
    cout<<"ENTER YOUR ADDRESS: "<<endl;
    cin>>address;
    cout<<"ENTER YOUR YEAR: "<<endl;
    cin>>year;
    cout<<"ENTER YOUR DIVISION :"<<endl;
    cin>>division;
    cout<<"ENTER YOUR ROLL.NO :"<<endl;
    cin>>roll_no;
    cout<<"ENTER YOUR MOBILE.NO: "<<endl;
    cin>>mob_no;
    cout<<"ENTER YOUR LICENSE.NO: "<<endl;
    cin>>state.license;
    cout<<"ENTER YOUR DATE OF BIRTH: "<<endl;
    cin>>state.dob;
    cout<<"ENTER YOUR BLOOD GROUP: "<<endl;
    cin>>state.bloodgrp;
}
void student::display(personalinfo &state){ // displaying outputs
    cout<<""<<endl;
    cout<<"*******STUDENT PERSONAL INFO*******"<<endl;
    cout<<"NAME OF STUDENT IS: "<<name<<endl;
    cout<<"ADDRESS OF THE STUDENT IS: "<<address<<endl;
    cout<<"DATE OF BIRTH IS: "<<state.dob<<endl;
    cout<<"YEAR OF STUDYING IS: "<<year<<endl;
    cout<<"DIVISON OF STUDENT IS: "<<division<<endl;
    cout<<"ROLL.NO OF STUDENT IS: "<<roll_no<<endl;
    cout<<"BLOOD GROUP OF STUDENT IS: "<<state.bloodgrp<<endl;
    cout<<"LICENSE NUMBER OF STUDENT IS: "<<state.license<<endl;
    cout<<"MOBILE NUMBER OF STUDENT IS: "<<mob_no<<endl;
    cout<<"************************************"<<endl;
    cout<<""<<endl;
}
int main(){
    int choice,m,n,i=0;
    cout<<"ENTER THE NO. OF STUDENT DATA YOU WANT TO ENTER: "<<endl;
    cin>>n;
    student *ptr1=new student[n]; //a pointer state declared which allocates (or make new stateects) and  stores the array of stateects (as much as the input) of student class and can be accesed by incrementing the pointer
    personalinfo *ptr2=new personalinfo[n];// same here
    while(i==0){
        cout<<""<<endl;
        cout<<"***MENU***"<<endl;
        cout<<"PRESS 1: CREATE DATABASE\nPRESS 2: DISPLAY DATABASE\nPRESS 3: COPY CONTRUCTOR\nPRESS 4: DEFAULT CONTRUCTOR\nPRESS 5: DELETE DATABASE"<<endl;
        cin>>choice; // taking choice from the user
        cout<<""<<endl;
        switch(choice){
            case 1:
            {
                for(int j=0;j<n;j++){ //here we are creating a data base ie inputing the inforamtion from the user and  incrementing a pointer to  input number of enteries and store it in specific stateects 
                    ptr1[i].create(ptr2[i]);// here we are passing 1st state of personal info so that it gets one with the student class and can be accesed
                    ptr1[i].incount(); // incrementing the count of input

                }
            }
            break;
            case 2:
            	{
			ptr1[0].displaycnt();
            for(int i=0;i<n;i++){ // here we only display the state of student  to state of  personalinfo 
                ptr1[i].display(ptr2[i]);
                }
            }
            break;
            case 3:
            {
                student state1; //here created two new state of classes
                personalinfo state2;
                state1.create(state2); //calling create function by other class do not give error as they are friend class
                student state3(state1); //copy constructor  where the variable data the state1 was holding  becomes equal to the state3
                personalinfo state4(state2);//copy constructor  where the variable data the state2 was holding  becomes equal to the state4
                cout<<"COPY CONSTRUCTOR IS CALLED "<<endl;
                state3.display(state4); //copy constructor is called (where after values of variables becoming equal) the state3 of class student calls the display function  by passing the state4 for accesing and displaying  variables of class personal info
            }
            break;
            case 4:
            {
            student state1; // stateects are made
            personalinfo state2;
            cout<<"DEFAULT CONSTRUCTOR IS CALLED "<<endl;
            state1.display(state2); //here we directly call the display function so the compiler will search for the default constructor as print the data which is present in it
            }
            break;
            case 5:
            
                delete[] ptr1; //here we are deleting the allocated memory by the new keyword and freeing up the space
                delete [] ptr2;
        }
        cout<<""<<endl;
        cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION : \n PRESS 1: YES \n PRESS 2: NO :"<<endl;
        cin>>m;
        if (m!=1){
            i+=1;
            break;
        }
    }
}

