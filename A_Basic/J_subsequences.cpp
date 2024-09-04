# include<iostream>
# include<vector> 
using namespace std;

void print(vector<string>v){                                           // print vector
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void solve(string s,string output,int index, vector<string>&ans){
    if(index >= s.length()){                                                // base case
        ans.push_back(output);
        return;
    }

    solve(s,output,index+1,ans);                                       // exclude

    char element = s[index];                                              // include 
    output.push_back(element);
    solve(s,output,index+1,ans);
}

vector<string> subsequences(string s){
    vector<string> ans;
    string output = " ";
    int index = 0;
    solve(s,output,index,ans);
    return ans;

}

int main(){
    string s;
    cout<<"enter your string : "<<endl;
    getline(cin,s);

    cout<<"Your string is : "<<s<<endl;

    vector<string>ans  = subsequences(s);
    cout<<"subsequences are : "<<endl;
    print(ans);

}