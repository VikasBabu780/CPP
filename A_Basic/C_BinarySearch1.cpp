// finding first and last occurance of a number, sorted array
// total number of occ can be calculated by (last occ - fisrt occ)+1

#include<iostream>
using namespace std;

int firstOccurance(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int mid = start+ (end-start)/2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            end = mid -1;

        }else if(key > arr[mid] ){
            start = mid + 1;

        }else{
            end =  mid -1;

        }
     mid = start+ (end-start)/2;

    }
    return ans;
    
}

int lastOccurance(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int mid = start+ (end-start)/2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            start = mid+1;

        }else if(key > arr[mid] ){
            start = mid + 1;

        }else{
            end =  mid -1;

        }
     mid = start+ (end-start)/2;

    }
    return ans;
    
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

    cout<<"the number first occured at index :"<<firstOccurance(arr,n,key)<<endl;
    cout<<"the number last occured at indeex :"<<lastOccurance(arr,n,key)<<endl;
}

    