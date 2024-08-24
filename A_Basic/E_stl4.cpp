// operations on deque

# include <iostream>
# include <deque>

using namespace std;

int main(){
    deque<int> d;                                                           // creating deque

    d.push_back(1);                                                            // adding element from back side
    d.push_front(2);                                                           // adding element from front side

    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"print first index element -> "<<d.at(1)<<endl;                                       // accessing element at index
    
    cout<<"front : "<<d.front()<<endl;                                                      // accessing front element
    cout<<"back : "<<d.back()<<endl;                                                        // accessing back element
    
    cout<<"empty or not : "<<d.empty()<<endl;                                               // checking deque is empty or not

    d.pop_front();                                                                         // deleting front element
    cout<<endl;
    for(int i :d){
        cout<<i<<" ";
    }

    cout<<"before erase "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);                                          // erase function take starting and ending indexes
    cout<<"after erase:"<<d.size()<<endl;

    

}