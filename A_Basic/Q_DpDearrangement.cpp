# include <iostream>
using namespace std;

long long int coutDerangements(int n){
    // base case
    if(n == 1){
        return 0;
    } 
    if( n == 2)
       return 1;

    int ans = (n-1)*(coutDerangements(n-1) + coutDerangements(n-2));

    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    long long int ans = coutDerangements(n);

    cout<<"The number of derangements are "<<ans;

}
