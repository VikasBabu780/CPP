// swap alternate elements  

#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr [] ,int size){
    for(int i =0; i<size; i+=2){
        if(i+1 < size){
            swap(arr[i] ,arr[i+1]);
        }
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
    
    swapAlternate(arr,size);
}
