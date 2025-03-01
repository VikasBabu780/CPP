# include <iostream>
# include<vector>
# include <limits.h>
using namespace std;

// recursion
// time complexity exponential
int solve(int n,int x,int y,int z){
    // base case
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }
    int a = solve(n-x,x,y,z) + 1;
    int b = solve(n-y,x,y,z) + 1;
    int c = solve(n-z,x,y,z) + 1;

    int ans =  max(a,max(b,c));
    return ans;
}

// recursion + memoization
// time complexity O(n) , space complexity O(n) +O(n)
int solve2(int n,int x,int y,int z,vector <int> &dp){
    // base case
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int a = solve2(n-x,x,y,z,dp) + 1;
    int b = solve2(n-y,x,y,z,dp) + 1;
    int c = solve2(n-z,x,y,z,dp) + 1;

    dp[n] =  max(a,max(b,c));
    return dp[n];
}

// tabulation
// time complexity O(n) , space complexity O(n)
int solve3(int n,int x,int y,int z){
    
    vector <int> dp(n+1,INT_MIN);
    dp[0] = 0;

    for(int i =1; i<=n; i++){
        if(i-x >= 0)
            dp[i] = max(dp[i],dp[i-x]+1);

        if(i-y >= 0)
            dp[i] = max(dp[i],dp[i-y]+1);

        if(i-z >= 0)
            dp[i] = max(dp[i],dp[i-z]+1);
        
    }

    if(dp[n] < 0){
        return 0;
    } else {
        return dp[n];
    }
}

int cutSegments(int n,int x,int y,int z ){
    // int ans = solve(n,x,y,z);
    // if(ans < 0){
    //     return 0;
    // } else {
    //     return ans;
    // }

    // vector<int > dp(n+1,-1);
    // int ans = solve2(n,x,y,z,dp);
    // if(ans < 0){
    //     return 0;
    // } else {
    //     return ans;
    // }

    return solve3(n,x,y,z);
}

int main(){
    int n;
    cout<<"Enter the size of Rod : ";
    cin>>n;

    int x;
    cout<<"Enter the size of Piece 1 : ";
    cin>>x;

    int y;
    cout<<"Enter the size of Piece 2 : ";
    cin>>y;

    int z;
    cout<<"Enter the size of Piece 3 : ";
    cin>>z;

    int ans = cutSegments(n,x,y,z);
    cout<<"Maximum segments can be cutted are "<<ans;

    return 0;
}