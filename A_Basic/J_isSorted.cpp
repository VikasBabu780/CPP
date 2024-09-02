// to check wheather a array is sorted or not

# include <iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size == 0 | size == 1){                           // base case
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    } else{
        bool remainingPart = isSorted(arr+1,size-1);                       // recursive call
        return remainingPart;
    }
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

    bool ans = isSorted(arr,n);

    if(ans){
        cout<<"Array is sorted !";
    } else {
        cout<<"Array is not sorted !";
    }
}