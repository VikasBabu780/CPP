# include <iostream>
# include <vector>

using namespace std;

vector<int> reverse(vector<int> v){
    int s =0;
    int e = v.size() - 1;

    while(s < e){
        swap(v[s++],v[e--]);
    }
    return v;
}

void print(vector<int>v){
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

vector<int> findArraySum(vector<int>a , int n, vector<int>b, int m){
    int i = n-1;
    int j = m-1;
    vector<int> ans;

    int carry = 0;

    while(i >= 0 && j >= 0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum /10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i >= 0){                                         // first case
        int sum = a[i] + carry;
        carry = sum/10;
        ans.push_back(sum);
        i--;
        
    }

    while(j >= 0){                                          // second case
        int sum = b[j] +carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    while(carry != 0){                                           // third case
        int sum = carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);

    }
    vector<int>sum = reverse(ans);
    return sum;
    
   
}

int main(){
    int n;
    cout<<"enter the value of n :";
    cin>>n;

    vector<int>a(n);

    cout<<"enter "<<n<<" elements"<<endl;

    for(int i =0; i<n; i++){
        cin>>a[i];
    }cout<<endl;

    int m;
    cout<<"enter the value of m :";
    cin>>m;

    vector<int>b(m);

    cout<<"enter "<<m<<" elements"<<endl;

    for(int i =0; i<m; i++){
        cin>>b[i];
    }cout<<endl;

    vector<int>sum = findArraySum(a,n,b,m);
    print(sum);
}