// implementations on list

# include <iostream>
# include<list>

using namespace std;

int main(){
    list<int> l;                                 // creating a list
     
    list<int>n(5,100);                           // creating list with size 5 and each element of size 100
     cout<<"printing n"<<endl;
    for(int i : n){
        cout<<i<<" ";
    }cout<<endl;

    l.push_back(1);                               // adding element from back side
    l.push_front(2);                                 // adding element from front side

    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin());                                // erase function taking starting and ending index
    cout<<"after erase"<<endl;
    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"size of list :"<<l.size()<<endl;                      // printing size of list
}