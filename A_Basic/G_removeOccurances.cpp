// remove particular part of a string

# include <iostream>
using namespace std;


string removeOccurances(string s,string part){
    while(s.length() != 0 && s.find(part) < s.length()){  //  find karo part h kya if yes then enter in the loop and erase that part
        s.erase(s.find(part), part.length());
    }
    return s;

}
int main(){
    string s;
    cout<<"enter your string : ";
    getline(cin,s);

    string part;
    cout<<"enter the part which you want to delete : ";
    getline(cin,part);

    cout<<"string after deletion is : "<<removeOccurances(s,part)<<endl;
    
}