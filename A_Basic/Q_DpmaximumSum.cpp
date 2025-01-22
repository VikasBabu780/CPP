// maximum sum of non adjacent elements in an array

# include<iostream>
# include<vector>
using namespace std;

// recurssion
int solve(vector<int> &nums,int n){
    // base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;

    return max(incl,excl);
}

// recurssion + meemoization
// time complexity O(n) ,space complexity O(n) +O(n)
int solve2(vector<int> &nums,int n,vector<int> &dp){
    // base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;
    
    dp[n] = max(incl,excl);
    return dp[n];
}

// tebulation
// time complexity O(n) ,space complexity O(n)
int solve3(vector<int> &nums){
   int n = nums.size();
   vector<int> dp(n,0);

   dp[0] = nums[0];

   for(int i =1; i<n; i++){
    int incl = dp[i-2]+ nums[i];
    int excl = dp[i-1] + 0;
    dp[i] = max(incl,excl);
   }
   return dp[n-1];
}

// space optimization
// time complexity  O(n) ,space complexity O(1)
int solve4(vector<int> &nums){
   int n = nums.size();

   int prev2 = 0;
   int prev1 = nums[0];

   for(int i =1; i<n; i++){
    int incl = prev2+ nums[i];
    int excl = prev1 + 0;
    int ans = max(incl,excl);
    prev2 = prev1;
    prev1 = ans;
   }
   return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // int n  = nums.size();
    // int ans = solve(nums,n-1);
    // return ans;

    // int n = nums.size();
    // vector<int> dp(n, -1);
    // return solve2(nums,n-1,dp);

    return solve4(nums);


}

int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;

    vector <int> v(n);

    cout<<"Enter the entries of vector : ";
    for(int i =0; i<n; i++){
        cin>>(v[i]);
    }

    int maxSum = maximumNonAdjacentSum(v);
    cout<<"Maximum sum of non adjacent numbers is : "<<maxSum;

    return 0;
}