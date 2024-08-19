//reverse an array

#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr [] ,int size){
    int s = 0;
    int e = size-1;
    while(s<=e){
        swap(arr[s] ,arr[e]);
        s++;
        e--;
    }
    printArray( arr,size);

    }

int main(){
    int size;
    cout<<"enter the size of array:"<<endl;
    cin>>size;

    int arr[100];
    cout<<"enter "<<size<<" elements :"<<endl;
    for(int i=0; i<size;i++){
        cin>>arr[i];
    }
    
    reverseArray(arr,size);
}
