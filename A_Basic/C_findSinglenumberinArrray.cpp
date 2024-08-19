// finding unique number
// XOR of a^a = 0
// XOR of 0^a = a

#include<iostream>
using namespace std;

int searchNumber(int arr[] ,int size){
    int ans = 0;
    for(int i =0; i<size; i++){
        ans = ans^arr[i];
    }
    return ans;
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
    int answer = searchNumber(arr,size);
    cout<<"Answer is:"<<answer;
}