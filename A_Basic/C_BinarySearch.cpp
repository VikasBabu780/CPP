//Binary search

#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n , int key){
    int start =0;
    int end = n-1;
    int mid = start+(start-end)/2;  // beacause mid value can be greater than integer limit

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){      // go to right part
            start = mid +1;
        }
        else{
            end = mid-1;
        }
        mid = start+(start-end)/2;
    }
    return -1;
}
int main(){
    int n ;
    cout<<"enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"enter "<<n<<" elements:"<<endl;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"enter the number to be searched:";
    cin>>key;

    int index = BinarySearch(arr,n,key);
    cout<<"number found at index:"<<index;
}