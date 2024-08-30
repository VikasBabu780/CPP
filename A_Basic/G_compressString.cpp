# include <iostream>
# include <vector>
using namespace std;

int compress(vector<char> &s){
    int i = 0;
    int ansIndex = 0;
    int n = s.size();

    while(i < n){
        int j = i+1;
        while(j < n && s[i] == s[j]){
            j++;
        }                      // bahar tabhi ayege jb ya to vector pua traverse krdia ya fir new char encounter kia h
        s[ansIndex++] = s[i];     // old character store kr lia
        int count = j-i;

        if(count > 1){
            string cnt = to_string(count);            // converting counting into single digit and saving in answer
            for(char ch : cnt){
                s[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

void print(vector<char> s ){
    for(int i =0 ; i<s.size(); i++){
        cout<<s[i]<<" ";
    }cout<<endl;
}

int main(){
    int length;
    cout<<"enter the length of vector : " <<endl;
    cin>>length;

    vector<char> s(length);
    
    cout<<"enter "<<length<< " cahracters :"<<endl;
    for(int i =0; i<length; i++){
        cin>>s[i];
        
    }

    cout<<"vector before compress : "<<endl;
    print(s);

    compress(s);
    cout<<"vector after compress : "<<endl;
    print(s);

}