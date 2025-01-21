// space optimization approach
// time complexity O(n) , space complexity O(1)

# include<iostream>
# include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0){
        return prev2;
    }

    for(int i = 2; i<=n; i++){
        int curr = prev1 + prev2;
        // shift logic
        prev2 = prev1;
        prev1 = curr;

    }
    cout<<n<<"th fibonacci number is "<<prev1<<endl;

    return 0;

}