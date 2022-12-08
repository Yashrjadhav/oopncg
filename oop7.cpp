#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class itemrec
{
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    bool operator==(const itemrec &obj1)
    {
        if (code == obj1.code)
        {
            return 1;
        }
        return 0;
    }
    bool operator<(const itemrec &obj1)
    {
        if (code < obj1.code)
        {
            return 1;
        }
        return 0;
    }
};
vector<itemrec> v1;
void insert();
void display();
void search();
void dlt ();
void print(itemrec & obj1);
bool compare(const itemrec &obj1, const itemrec &obj2)
{
    return obj1.cost < obj2.cost;
}
int main()
{
    int choice, l = 0;
    while (l == 0)
    {
        cout << "**********************" << endl;
        cout << "PRESS1:INSERT\nPRESS2:DELETE\nPRESS3:DISPLAY\nPRESS4:SEARCH\nPRESS5:SORT\nPRESS6:EXIT" << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            insert();
            break;

            case 2:
            dlt();
            break;

            case 3:
            display();
            break;

            case 4:
            search();
            break;

            case 5:
            sort(v1.begin(),v1.end());
            cout<<"\n\nSORTED RECORD AS PER COST : ";
            display();
            break;

            case 6:
            l+=1;
            break;
        }
    }
}

void insert()
{
    itemrec obj1;
    cout << "\nENTER THE ITEM NAME : ";
    cin >> obj1.name;
    cout << "\nENTER THE ITEM QUANTITY : ";
    cin >> obj1.quantity;
    cout << "\nENTER THE ITEM COST : ";
    cin >> obj1.cost;
    cout << "\nENTER THE ITEM CODE: ";
    cin >> obj1.code;
    v1.push_back(obj1);
}
void dlt()
{
    vector<itemrec>::iterator p;
    itemrec obj1;
    cout<<"\nENTER THE ITEM CODE TO DELETE : ";
    cin>>obj1.code;
    p=find(v1.begin(), v1.end(), obj1);
    if (p==v1.end())
    {
        cout << "THE RECORD WAS NOT FOUND";
    }
    else
    {
        cout<<"RECORD FOUND SUCCESFULLY" << endl;
        v1.erase(p);
        cout<<"RECORD DELETED SUCCESFULLY"<<endl;
    }
}

void display(){
    vector<itemrec>::iterator p;
    for(int i=0;i<=v1.size()-1;i++)
    print(v1[i]);
}
void search()
{
    vector<itemrec>::iterator p;
    itemrec obj1;
    cout << "\n  ENTER THE CODE OF ITEM YOU WANT TO SEARCH : ";
    cin >> obj1.code;
    p=find(v1.begin(), v1.end(),obj1);
    if(p==v1.end())
    {
        cout << "RECORD NOT FOUND" << endl;
    }
    else
    {
        cout << "RECORD FOUND SUCCESFULLY" << endl;
    }
    cout<<endl;
}
void print(itemrec &obj1){
    cout<<"\n***********"<<endl;
    cout<<"\nITEM NAME : "<<obj1.name;
    cout<<"\nITEM QUANTITY : "<<obj1.quantity;
    cout<<"\nITEM COST : "<<obj1.cost;
    cout<<"\nITEM CODE : "<<obj1.code;
    cout<<"\n\n";
}

