// given x,n,m to calculate (x^n)%m

# include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m){
    int res = 1;

    while(n > 0){
        if(n & 1){                              // odd
            res = (1LL*(res) * (x)%m)%m;                  // multiply by 1LL becaause reslut may lead integer limit
        }
        x = (1LL*(x)%m * (x)%m)%m;
        n = n >>1;                     // right shift by 1 is equal to divided by 2
    }
    return res;
}

int main(){
    int x,n ,m;
    cout<<"enter the value of x , n & m  : "<<endl;
    cin>> x >> n >> m ;
    
    int ans = modularExponentiation(x,n,m);
    cout<<"answer is : "<<ans<<endl;
    
}