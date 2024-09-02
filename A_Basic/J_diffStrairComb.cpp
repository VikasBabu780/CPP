// calculate number of ways to climb n stairs if at a time you can climb 1 or 2

# include <iostream>
using namespace std;

int countWaysToClimb(int n){
    if(n < 0){                         // base case
        return 0;
    }
    if(n == 0){
        return 1;
    }

    int ans = countWaysToClimb(n-1) + countWaysToClimb(n-2);           // recursive case
    return ans;
}
int main(){
    int n;
    cout<<"enter the number of stairs : ";
    cin>>n;

    int ans = countWaysToClimb(n);
    cout<<"total number of ways are : "<<ans<<endl;
}