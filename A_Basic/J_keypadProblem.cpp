// input numbers from 0 to 9 and return all possible string cominations

# include <iostream>
# include <vector>
using namespace std;

void print(vector<string>v){                                           // print vector
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void solve(string digit,string output,int index,vector<string>&ans,string mapping[]){
    if(index >= digit.length()){                                                         // base case
        ans.push_back(output);
        return;
    }
    int number = digit[index]-'0';                                      // charcter value - 0 to get number
    string value = mapping[number];                                         // from here we get string value

    for(int i =0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digit,output,index+1,ans,mapping);
        output.pop_back();                                                   // for backtracking concept
    }
}

vector<string> letterCombination(string digits){
    vector<string> ans ;
    if(digits.length() == 0){
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10] = { " "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,mapping);
    return ans;
}

int main(){
    string digits;
    cout<<"enter your string : "<<endl;
    getline(cin,digits);

    cout<<"Your string is : "<<digits<<endl;

    vector<string> ans = letterCombination(digits);
    cout<<endl<<"combination of words may be : "<<endl;
    print(ans);


}