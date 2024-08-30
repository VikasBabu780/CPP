// check  wheather substring's permutation are present or not

# include <iostream>
using namespace std;

bool checkEqual(int a[26] ,int b[26]){
    for(int i = 0; i<26; i++){
        if(a[i] != b[i]){
            return 0;
        }
        return 1;
    }
}

bool checkInclusion(string part, string s){
    int count1[26] = {0};                                   // character count array
    for(int i = 0; i< part.length(); i++){
        int index = part[i] - 'a';
        count1[index]++;
    }

    int i = 0;                                          // traverse part string window of size s length and compare
    int windowSize = part.length();
    int count2[26] = {0};

    while(i < windowSize && i<s.length()){                            // running for first window
        int index = s[i] - 'a';
        count2[index]++;
        i++;
    }
    if(checkEqual(count1, count2)){
         return 1;
    }

    while(i<s.length()){                               // aage window process karo
        char newchar = s[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldchar = s[i - windowSize];
        index = oldchar - 'a';
        count2[index]--;
        i++;
    
    
        if(checkEqual(count1 , count2)){
            return 1;
        }
    }
    return 0;
}

int main(){
    string s;
    cout<<"enter your string : ";
    getline(cin,s);

    string part;
    cout<<"enter the part which you want to find : ";
    getline(cin,part);

    cout<<"anwer is : "<<checkInclusion(part,s)<<endl;
}