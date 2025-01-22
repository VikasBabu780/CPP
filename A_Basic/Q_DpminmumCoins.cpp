# include <iostream>
# include <vector>
# include <limits.h>
using namespace std;

// recurssion
// time comlexity  exponential
int solve(vector <int> &num,int x){
    // base case
    if(x == 0){
        return 0;
    }

    if(x < 0){
        return INT_MAX;
    }
    
    int mini = INT_MAX;
    for(int i = 0; i<num.size(); i++){
       int ans = solve(num,x-num[i]);
       if(ans != INT_MAX){
        mini = min(mini,1+ans);
       }
    }
    return mini;
}

// recurssion + memoization
// time complexity O(n*x) ,space complexity O(x)
int solve2(vector <int> &num,int x ,vector<int> &dp){
    // base case
    if(x == 0){
        return 0;
    }

    if(x < 0){
        return INT_MAX;
    }

    if(dp[x] != -1){
        return dp[x];
    }
    
    int mini = INT_MAX;
    for(int i = 0; i<num.size(); i++){
       int ans = solve(num,x-num[i]);
       if(ans != INT_MAX){
        mini = min(mini,1+ans);
       }
    }
    dp[x] = mini;
    return mini;
}

// tabulation
// time complexity O(n*x) ,space complexity O(x)
int solve3(vector <int> &num,int x){
    
    vector <int> dp(x+1,INT_MAX);
    dp[0] =0;

    for(int i =1; i<=x; i++){
        // i am trying to solve for every amount figure from 1 to x
        for(int j = 0; j< num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j] != INT_MAX]){
                 dp[i]  = min(dp[i] ,1+dp[i-num[j]]);
            }
           
        }
    }

    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];
}

int minimumCoins(vector <int> &num ,int x){
    // int ans = solve(num,x);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    // vector <int> dp(x+1,-1);
    // int ans = solve2(num,x,dp);
    // if(ans == INT_MAX){
    //     return -1;
    // } else {
    //     return ans;
    // }

    return solve3(num,x);
}

int main (){
    int n;
    cout<<"Enter the number of coins : ";
    cin>>n;

    vector <int> v(n);

    cout<<"Enter the value of coins : ";
    for(int i =0; i<n; i++){
        cin>>(v[i]);
    }

    int x;
    cout<<"Enter the amount to calculate coins : ";
    cin>>x;

    int minCoins = minimumCoins(v,x);
    cout<<"The minimum number of coins needed are "<<minCoins;

    return 0;
}