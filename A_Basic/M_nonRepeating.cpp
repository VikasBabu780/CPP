# include <iostream>
# include <map>
# include <queue>
using namespace std;

string firstNonRepeating(string A){
    
    map< char,int> count;
    queue <int> q;
    string ans = " ";

    for(int i = 0; i< A.length(); i++){
        char ch = A[i];

        // increase count
        count[ch]++;

        // queue me push karo
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                // repeating character
                q.pop();
            } else {
                // non repeating character mil gya
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string s;
    cout<<"enter your string : ";
    getline(cin,s);

    cout<<"string is : "<<s<<endl;

    string ans = firstNonRepeating(s);
    cout<<"non repeating string is : "<<ans;


}