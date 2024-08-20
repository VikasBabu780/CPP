// peak element in mountain array ex: [1,4,8,5,3,2]

#include<iostream>
using namespace std;

int peakMountain(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s < e){
        if(arr[mid] < arr[mid+1]){
            s = mid +1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return arr[s];
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

    cout<<"peak element is :"<<peakMountain(arr,n);

}