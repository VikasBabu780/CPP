// find fibonacci of  a number

# include <iostream>
using namespace std;

int fib(int n){
    if(n == 1){
        return 0;                          // base case
    } else if(n == 2){
        return 1;
    }
    
    int fibN = fib(n-1) + fib(n-2);                // recursive case
}
int main(){
    int n;
    cout<<"enter the value of n :";
    cin>>n;

    int ans = fib(n);
    cout<<"fibonacci of "<<n<<" is : "<<ans<<endl;
}