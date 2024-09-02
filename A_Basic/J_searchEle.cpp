// to search a element is present or not

# include <iostream>
using namespace std;

bool search(int *arr,int size,int key){
     if(size == 0){                                  // base case
        return false;
     }

     if(arr[0] == key){
        return true;
     } else{
        bool reamainingPart = search(arr+1,size-1,key);                 // recursive case
        return reamainingPart;
     }
}
int main(){
    int n; 
    cout<<"enter the size of array : "<<endl;
    cin>>n;

    int *arr = new int[n];                        // array creation dynamically

    cout<<"Enter "<<n<<" elements : "<<endl;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

     int key;
     cout<<"Enter the element to be searched : ";
     cin>>key;

    bool ans = search(arr,n,key);

    if(ans){
        cout<<"key is present !";

    } else{
        cout<<"key is not present !";
    }

}