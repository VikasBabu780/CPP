// sorting 0 and 1

#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i =0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void sortOne(int arr[],int size){
    int left =0,right =size-1;
    while(left <= right){
        if(arr[left] == 1 && arr[right] == 0){
            swap(arr[left] , arr[right]) ;   
        left++;
        right--;

        }
        while(arr[left] == 0 ){
            left++;
        }
        while(arr[right] == 1){
            right--;
        }
        
        
    }
}

int main(){
    int size;
    cout<<"enter the size of array:"<<endl;
    cin>>size;

    int arr[100];
    cout<<"Enter "<<size<<" elements:"<<endl;
    for(int i = 0; i< size; i++){
         cin>>arr[i];
    }
     sortOne(arr,size);
     printArray(arr,size);



}