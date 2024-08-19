// linear search
#include<iostream>
using namespace std;

bool search(int arr[],int size,int element){
    for(int i = 0; i<size; i++){
        if(arr[i] == element){
            return 1;
        }

    }
    return 0;
}

int main(){
    int size;
    cout<<"enter the size of array:";
    cin>>size;

    int arr[100];
    cout<<"enter "<<size<<" elements:";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int element;
    cout<<"enter the element to be searched:";
    cin>>element;

    bool found = search(arr,size,element);

    if(found){
        cout<<"element is found"<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }

}