// time complexity O(n),space complexity O(n)
// top -bottom approach

# include<iostream>
# include<vector>
using namespace std;

int fib(int n,vector<int> &dp){
    // base case
    if(n<=1){
        return n;
    }

    // step 3
    if(dp[n] != -1){
        return dp[n];
    }
    
    // step 2
    dp[n] = fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    // step 1
    vector<int> dp(n+1);
    for(int i =0; i<=n; i++){
        dp[i] = -1;
    }
    
    cout<<n<<"th fibonacci number is "<<fib(n,dp)<<endl;
    return 0;
}