#include<iostream>
#include<map>
#include<string.h>
using namespace std;
class states
{
map<string,int> obj;
public:
states()
{
obj["Uttar Pradesh"]=199812341; 
obj["Maharashtra"]=112374333; 
obj["Bihar"]=104099452; 
obj["West Bengal"]=91276115; 
obj["Madhya Pradesh"]=72626809; 
obj["Tamil Nadu"]=72147030; 
obj["Rajasthan"]=68548437; 
obj["Karnataka"]=61095297; 
obj["Gujarat"]=60439692; 
obj["Andhra Pradesh"]=49577103; 
obj["Odisha"]=41974219; 
obj["Telangana"]=35003674; 
obj["Kerala"]=33406061; 
obj["Jharkhand"]=32988134; 
obj["Assam"]=31205576; 
obj["Punjab"]=27743338; 
obj["Chhattisgarh"]=25545198; 
obj["Haryana"]=25351462; 
obj["Delhi"]=16787941; 
obj["Jammu and Kashmir"]=12267032; 
obj["Uttarakhand"]=10086292; 
obj["Himachal Pradesh"]=6864602; 
obj["Tripura"]=3673917; 
obj["Meghalaya"]=2966889; 
obj["Manipur"]=2570390; 
obj["Nagaland"]=1978502; 
obj["Goa"]=1458545; 
obj["Arunachal Pradesh"]=1383727; 
obj["Puducherry"]=1247953; 
obj["Mizoram"]=1097206; 
obj["Chandigarh"]=1055450; 
obj["Sikkim"]=610577; 
obj["Daman and Diu"]=585764; 
obj["Andaman and Nicobar Islands"]=380581; 
obj["Ladakh"]=274000; 
obj["Lakshadweep"]=64473;
}
void search(string st)
{
map<string,int>::iterator iter;
iter =obj.find(st);
if( iter!= obj.end() )
cout<<st<<"'s population is "<<iter->second ;
else
cout<<"State Not Found in the Map"<<"\n";
obj.clear();
}
};
int main()
{
string state;
cout<<"\n Number of States are : 28 and Union Territories are : 8";
cout<<"\n Enter name of the state :";
cin>>state;
states obj;
obj.search(state);
}