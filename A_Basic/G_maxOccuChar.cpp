// maximum occurring character
# include <iostream>
using namespace std;

char getMaxOccCharacter(string s){
    int arr[26] = {0};                                      // create an array of count of characters
    for(int i =0; i<s.length(); i++){                          
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z'){                             // lower case
           number = ch - 'a';
        } else {                                              // upper case
            number = ch -'A';
        }
        arr[number]++;
    }

    int maxi = -1, ans = -1;
    for(int i =0; i<26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns ='a'+ans;
    return finalAns;
}

int main(){
    string s;
    cin>>s;
    cout<<getMaxOccCharacter(s)<<endl;

    return 0;

}
