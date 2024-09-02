// searching of element through binary search

# include <iostream>
using namespace std;

bool binarySearch(int*arr,int s,int e,int k){
    if(s>e){                                                           // base case
        return false;

    }
    int mid = s+(e-s)/2;
    if(arr[mid] == k){
        return true;
    }
    

    if(arr[mid] < k){
        return binarySearch(arr,mid+1,e,k);                              // recursive case
    } else{
        return binarySearch(arr,s,mid-1,k);                                   // recursive case
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

     int key;
     cout<<"Enter the element to be searched : ";
     cin>>key;
     
     int s = 0;
     int e = n-1;

     bool ans = binarySearch(arr,s,e,key);

    if(ans){
       cout<<"key is present !";  
     } else{
        cout<<"key is not present !";
     }
     
}