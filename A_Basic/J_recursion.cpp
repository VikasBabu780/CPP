// factorial of a number

# include <iostream>
using namespace std;

int Factorial(int n){
    if(n == 1 | n == 0){                     // base case
        return 1;
    } 
    int factNm1 = Factorial(n-1);
    int factN = n * factNm1;

    return factN;
}
int main(){
    int n ;
    cout<<"enter the value of n :";
    cin>>n;

    int ans = Factorial(n);
    cout<<"factorial of "<<n<< " is : "<<ans<<endl;

}