// search element in rotated sorted array

# include<iostream>
using namespace std;

int getPivot(int arr[] , int n){
    int s = 0, e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int BinarySearch(int arr[] ,int s ,int e,int key){
    int start =s, end = e;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        } else if(key >arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int findPosition(int arr[],int n,int key){
    int pivot = getPivot(arr,n);
    if(key >= arr[pivot] && key <= arr[n-1]){
        return BinarySearch(arr,pivot,n-1,key);
    } else{
        return BinarySearch(arr,0,pivot-1,key);
    }
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

    cout<<"number found at index:"<<findPosition(arr,n,key);
}