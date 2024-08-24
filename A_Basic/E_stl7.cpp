// operation on set

# include <iostream>
# include <set>

using namespace std;
int main(){
    set<int> s;                                                         // dreation of set

    s.insert(5);
    s.insert(5);                                                  // insertion in set
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(auto i : s){                                                // printing of set
        cout<<i<<endl;
    }

    s.erase(s.begin());                                                  // erase function
    for(auto i : s){
        cout<<i<<endl;
    }

    cout<<s.count(5)<<endl;                                           // check wheather element is present or not

    set<int>::iterator itr = s.find(4);                              // returns the iterator of number

}