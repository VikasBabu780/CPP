// operations on vector

# include<iostream>
# include<vector>
using namespace std;

int main(){
    vector<int>v;                                                            // initialization of vector
    cout<<"size -> "<<v.capacity()<<endl;
 
    vector<int> a(5,1);                                                    // creating a vector of size 5 and initializing all elements with 1
    cout<<"print a"<<endl;
    for(int i :a){
        cout<<i<<" ";
    }cout<<endl;

    v.push_back(1);
    cout<<"size -> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"size -> "<<v.capacity()<<endl;

    v.push_back(3);                                                               // insert the element in vector
    cout<<"size -> "<<v.size()<<endl;                                         // returns size of vector
    cout<<"capacity -> "<<v.capacity()<<endl;                                // returns the capacity of vector

    cout<<"Element at 2nd index :"<<v.at(2)<<endl;

    cout<<"front : " <<v.front()<<endl;                                      // returns the front element
    cout<<"back : "<<v.back()<<endl;                                         // returns the back element
    
    cout<<"before pop  "<<endl;
    for(int i : v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();                                                          // clear the last element

    cout<<"after pop  "<<endl;                     
    for(int i:v){
       cout<<i<<" ";
    }

    cout<<endl<<"before clear size :"<<v.size()<<endl;
    v.clear();
    cout<<"after clear size : "<<v.size()<<endl;                           // after clear size becomes zero not capacity
  

    
}
