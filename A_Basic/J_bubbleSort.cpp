// sorting array through bubble sort

# include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int *arr,int n){
    if(n == 0 || n == 1){
        return;
    }

    for(int i =0; i<n-1; i++){
        if(arr[i] >arr[i+1]){
            swap(arr[i] ,arr[i+1]);
        }
    }

    bubbleSort(arr,n-1);                             // recursive case
}
int main(){
    int n;
    cout<<"enter the size of array :";
    cin>>n;

    int *arr = new int[n];

    cout<<"enter " <<n<<" elements :"<<endl;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    } 

    cout<<"Array before sorting is : "<<endl;
    printArray(arr,n);

    bubbleSort(arr,n);
    cout<<endl<<"Array after sorting is : "<<endl;
    printArray(arr,n);


}