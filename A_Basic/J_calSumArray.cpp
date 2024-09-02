// to calculate sum of the giving array

# include<iostream>
using namespace std;

int calSum(int *arr,int size){
    
    if(size == 0){
        return 0;                                   // base case
    } 
    if(size == 1){
        return arr[0];
    }
   
    int sum =  arr[0];
    int remainingSum = calSum(arr+1,size-1);                          // recursive call
    int finalSum = sum + remainingSum;

    return finalSum;
}
int main(){
    int n; 
    cout<<"enter the size of array : "<<endl;
    cin>>n;

    int *arr = new int[n];                        // array creation dynamically

    cout<<"Enter "<<n<<" elements : "<<endl;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int totalSum = calSum(arr,n);
    cout<<"Total sum of array is : "<<totalSum<<endl;
}