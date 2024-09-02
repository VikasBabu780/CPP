// check palindrome 

# include<iostream>
using namespace std;

bool checkPalindrome(string &str,int s, int e){
    if(s>e){
        return true;                                                  // base case
    }
    if(str[s] != str[e]){
        return false;
    } else{
        return checkPalindrome(str,s+1,e-1);                                // recursive call
    }
}

int main(){
    string str;
    cout<<"enter your string : ";
    getline(cin,str);                                                      // get mutiple line input

    bool isPalindrome = checkPalindrome(str,0,str.length()-1);

    if(isPalindrome){
        cout<<"string is palindrome !";
    } else{
        cout<<"string is not palindrome !";
    }
}