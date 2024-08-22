// Insertion sort  (compare elements and put them left right accordingly)
// time complexity O(n^2)       where n is the length of array

# include<iostream>
using namespace std;

void printArray(int arr[],int n){           //function to print an array
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}

void insertionSort(int arr[], int n){
    for(int i =1; i<n; i++){
        int temp = arr[i];
        int j = i-1;                              // declared here to use outside loop
        for(; j >= 0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];                 // shifting of elements
            } else {
                break;                                // already sorted then come outside loop
            }

        }
        arr[j+1]  =  temp;
    }
}
int main(){
    int n ;
    cout<<"Enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" Elements:"<<endl;     
    for(int i =0; i<n; i++){                                   // entries of array
        cin>>arr[i];
    }

    cout<<"Array before sorting:"<<endl;
    printArray(arr,n);

    insertionSort(arr,n);                                          // calling insertion function
    cout<<endl<<"Array after sorting:"<<endl;
    printArray(arr,n);                                                   // calling printing function
}