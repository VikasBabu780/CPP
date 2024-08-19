//finding max and  min in array

# include<iostream>
using namespace std;

int main(){
    int size; 
    cout<<"enter the size of array:";
    cin>>size;

    int arr [100];

    cout<<"enter "<<size<< " values:";
    for(int i =0; i<size; i++){
        
        cin>>arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    for(int i =0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        
    }
    cout<<"maximum value in array is:"<<max<<endl;
    cout<<"minimum value in array is:"<<min<<endl;
}