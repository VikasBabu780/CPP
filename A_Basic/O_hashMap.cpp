# include <iostream>
# include<map>
# include<unordered_map>
using namespace std;

int main (){

    // creation
    unordered_map<string,int> m;

    // insertion 
    // first way
    pair<string,int> p = make_pair("babbar" ,3);
    m.insert(p);

    // second way
    pair <string,int> pair2("love",2);
    m.insert(pair2);

    // third way
    m["mera"] = 1;

    // search
    cout<<m["mera"] <<endl;
    cout<<m.at("babbar") <<endl;

    //cout<<m.at("unknownkey")<<endl; //   here compiler will terminate because of not availabilty if program
    // but agr uper bali line ko niche bali line ke bad likh de to ye bhi zero return kr degi
    cout <<m["unknownkey"]<<endl;     // ek entry ban jati hai unknown key ke liye corresponding to zero
    
    //size
    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("bro")<<endl;    // count func agr entry padi hai to 1 return kr dega nhi to 0 erurn kr dega

    // erase
    m.erase("love");
    cout<<m.size()<<endl;


    // access krne ka tarika
    for(auto i : m){
        cout <<i.first<<" "<<i.second <<endl;
    }

    // iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
       cout <<it ->first <<" "<<it -> second<<endl;
       it++;
    }

    return 0;
}