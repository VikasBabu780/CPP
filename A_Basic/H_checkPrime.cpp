// sieve of eractosthenes 
// calculate the total prime numbers less than n
// time complexity O(n*log(logn))

# include <iostream>
# include <vector>
using namespace std;

int countPrime(int n){
    int count = 0;
    vector<bool> prime(n+1,true);  // array in which we assumed all numbers as prime numbers

    prime[0] = prime[1] = false;

    for(int i = 2; i<n; i++){
        if(prime[i]){
            count++;

            for(int j = 2*i; j<n; j+=i){             // cross all the multiple numbers of  prime numbers
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main (){
    int n; 
    cout<<"enter the value  of n :";
    cin>>n;

    cout<<"prime numbers are : "<<countPrime(n)<<endl;

}