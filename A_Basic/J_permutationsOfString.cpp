// permutations of a string

# include <iostream>
# include <vector>
using namespace std;

void print(vector<string>v){                                           // print vector
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void solve(string s,vector<string>&ans,int index){
    if(index >= s.length()){                                            // based case
        ans.push_back(s);
        return;
    }
    for(int j = index; j<s.length(); j++){
        swap(s[index],s[j]);
        solve(s,ans,index+1);                                                   // recursive call

        swap(s[index],s[j]);                                              // for backtracking 
    }
}

vector<string> subsequences(string s){
    vector<string> ans;
    int index = 0;
    solve(s,ans,index);
    return ans ;
}

int main(){
    string s ;
    cout<<"enter yopur string : "<<endl;
    getline(cin ,s);

    cout<<"your string is : "<<s<<endl;

    vector<string>ans = subsequences(s);
    cout<<endl<<"permutations are : "<<endl;
    print(ans);
}