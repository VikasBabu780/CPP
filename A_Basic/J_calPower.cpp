// find 2 raise to the power n

# include <iostream>
using namespace std;

int power(int n){
    if(n == 0){                 // base case
        return 1;
    }
    int powNm1 = power(n-1);                   //   recursive case 
    int powN  = 2 * powNm1;

    return powN;
}
int main(){
    int n ;
    cout<<"enter the value of n :";
    cin>>n;

    int ans = power(n);
    cout<<"2 raise to power "<<n<< " is : "<<ans<<endl;
}