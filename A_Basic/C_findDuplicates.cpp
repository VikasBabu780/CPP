// Finding duplicates in array
// taking XOR of n-1 numbers with them  because n-1 numbers are present and one is duplicate

# include<iostream>
using namespace std;

int findDuplicates(int arr[] , int size){
    int ans = 0;
    // xor ing all array elements
    for(int i =0; i< size; i++){
        ans = ans^arr[i];
    }
    // xor ing n-1 elements
    for(int i =1 ; i < size; i++){
        ans = ans^i;
    }
    return ans;
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

    int Answer = findDuplicates(arr,size);
    cout<<"Answer is:"<<Answer;


}