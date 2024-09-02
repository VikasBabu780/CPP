// reverse a string

# include<iostream>
using namespace std;

void reverseString(int s,int e,string &str){
    
    if(s>e){
        return;                                            // base  case
    }

    swap(str[s],str[e]);
    s++;
    e--;
    

    reverseString(s,e,str);                                                // recursive call
}

int main(){
    string str;
    cout<<"enter your string : ";
    getline(cin,str);                                            // multiple line input

    int s = 0;
    int e = str.length()-1;
    

    reverseString(s,e,str);
    cout<<"reversed string is :";
    cout<<str<<endl;

}