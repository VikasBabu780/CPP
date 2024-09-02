// pronounce the digits of number

# include <iostream>
using namespace std;

void sayDigit(int n, string arr[]){
    if(n == 0){                            // base case
        return;
    }

    int digit = n % 10;                         // processing
    n = n/10;
    
    sayDigit(n,arr);                    // recursive call

    cout<<arr[digit]<<" ";
}
int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cout<<"enter number :";
    cin>>n;

sayDigit(n,arr);

}