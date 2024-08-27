// check palindrome if string is case senstive

# include <iostream>
using namespace std;

char tolowerCase(char ch){
    if(ch >= 'a' && ch <= 'z')
    return ch;
    else {
        char temp = ch -'A' + 'a';
        return temp;
    }
    
}

bool checkPalindrome(char string[], int n){
     int s = 0, e = n-1;
     
     while(s<e){
        if(tolowerCase(string[s]) == tolowerCase(string[e])){
        s++;
        e--;
      } else{
        return 0;
      }
     }
    return 1;
}

int getLength(char name[]){
    int count = 0;
    for(int i =0; name[i] != '\0' ; i++){
        count++;
    }
    return count;
}

int main(){
    char string[50];
    cout<<"Enter your string : "<<endl;
    cin>>string;

    int len = getLength(string);
    
    if(checkPalindrome(string,len) == 1){
        cout<<" string is palindrome !"<<endl;
    } else {
        cout<<"string is not palindrome !";
    }

}