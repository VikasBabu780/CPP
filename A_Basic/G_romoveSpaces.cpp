// replace all spaces by @40

# include<iostream>
using namespace std;


string replaceSpaces(string &s){              // function which will insert @40 at spaces
    string temp = "";
    for(int i = 0; i<s.length(); i++){
        if(s[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            temp.push_back(s[i]);
        }
    }
    return temp;
}

int main(){
    string s;
    cout<<"enter your string : ";
    getline(cin,s);

    cout<<"string after replacement is : " <<replaceSpaces(s)<<endl;                     // call tp replacement function

    
}