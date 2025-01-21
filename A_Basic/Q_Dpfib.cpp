// Bottom up approach
// time complexity O(n) , space complexity O(n)

# include <iostream> 
# include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    //step 1
    vector<int> dp(n+1);

    //step 2
    dp[1] = 1;
    dp[0] = 0;

    //step 3
    for(int i =2; i<=n; i++){
        dp[i] = dp[i-1] +dp[i-2];
    }

    cout<<n<<"th fibonacci number is "<<dp[n]<<endl;

}