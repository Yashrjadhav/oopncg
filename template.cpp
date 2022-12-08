#include<iostream>
using namespace std;
template<typename T> 
void selection_sort(T b) 
{
T a[50];
T temp;
cout<<"Enter the array elements :"<<endl;
for(int i=0;i<b;i++) 
{
cin>>a[i];
}
for(int i=0;i<b;i++) 
{
for(int j=i+1;j<b;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
cout<<"The sorted array is :"<<endl;
for(int i=0;i<b;i++) 
{
cout<<a[i]<<"\n";
}
}
int main()
{
int k,s;
do
{
cout<<"PRESS : \n 1. for integer sorting \n 2. for Floating sorting \n 3. EXIT \n";
cin>>k;
switch(k)
{
case 1:
{
cout<<"Enter size for sorting array :"<<endl;
cin>>s; 
selection_sort<int>(s);
}
break;
case 2:
{
cout<<"Enter size for sorting array :"<<endl;
cin>>s; 
selection_sort<float>(s);
}
break;
case 3:
break; 
} 
if(k==3)
break; 
}while(true);
return 0;