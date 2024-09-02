//  calculate a^b usng recursion

# include <iostream>
using namespace std;

int power(int a,int b){
    if(b==0){
        return 1;                     // base case
    }
    if(b == 1){
        return a;
    }

    int ans = power(a,b/2);                                       // recursive call

    if(b % 2 == 0){                                      // if b is even
        return ans * ans;
    } else{
        return a * ans *ans;                                   // if b is odd
    }
}
int main(){
    int a,b;
    cout<<"enter the value of a & b :";
    cin>>a>>b;

    int ans = power(a,b);

    cout<<a<<" raise to the power "<<b<<" is : "<<ans<<endl;
}