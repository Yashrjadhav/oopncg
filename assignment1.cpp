#include <iostream>
using namespace std;
class complex{
    private:
    int real,imag;
    public:
    friend ostream & operator <<(ostream &out,complex const &state);
    friend istream & operator >> (istream &in, complex &state);
    complex(int r=0,int i=0){
        real=r;
        imag=i;
    }
    complex operator +(complex const &state){
        complex state1;
        state1.real=real+state.real;
        state1.imag=imag+state.imag;
        return state1;
    }
    complex operator *(complex const &state){
        complex state1;
        state1.real=((real)*(state.real))-((imag)*(state.imag));
        state1.imag=((real)*(state.imag))+((imag)*(state.real));
        return state1;
    }
};
ostream & operator <<(ostream &out,complex const &state){
    out<<state.real;
    out<<"+i"<<state.imag;
    return out;
}
istream & operator >> (istream &in, complex &state){
    cout<<"ENTER THE REAL PART: "<<endl;
    in>>state.real;
    cout<<"ENTER THE IMAGINARY PART: "<<endl;
    in>>state.imag;
    return in;
}
int main(){
    complex c1,c2,c3,c4;
    cout<<"ENTER THE FIRST NUMBER: "<<endl;
    cin>>c1;
    cout<<"THE FIRST NUMBER is : "<<c1<<endl;
    cout<<"ENTER THE SECOND NUMBER: "<<endl;
    cin>>c2;
     cout<<"THE SECOND NUMBER is : "<<c2<<endl;
    c3=c1+c2;
    cout<<"ADDITION OF TWO NUMBERS IS:"<<c3<<endl;
    cout<<"MULTIPLICATION OF TWO NUMBERS IS:"<<endl;
    return 0;
}
