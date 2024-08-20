// square root using binary search

# include<iostream>
using namespace std;

int BinarySearch(int n){
    int s =0;
    int e = n;
    int mid = s+(e-s)/2;
    long long int ans = -1;

    while(s <= e){
        long long int square = mid*mid;         // if integer value exceed than 2^31-1 which is not in integer range

        if(square == n){
            return mid;
        }else if(square < n){
            ans = mid;
            s = mid +1;
        } else{
            e = mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int mySqrt(int x){
    return BinarySearch(x);
}

double morePrecision(int n , int precision , int tempsol){
    double factor =1;
    double ans = tempsol;

    for(int i = 0; i<precision; i++){
        factor = factor/10;
        for(double j =ans ; j*j<n; j = j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter the number of which sqrt to be calculated:";
    cin>>n;

    int tempsol = mySqrt(n);

    cout<<"sqrt of "<<n<<" is:" << morePrecision(n,3,tempsol);


}