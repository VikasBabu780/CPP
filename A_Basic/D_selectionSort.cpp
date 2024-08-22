// selection sort (smallest element leke right place par fix karna hota h)
// time complexity O(n^2)  where n is the size of array

# include<iostream>
using namespace std;


void printArray(int arr[],int n){           //function to print an array
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}
void selectionSort(int arr[], int n ){              // function for sorting
    for(int i =0; i<=n-1; i++){                     
        int minIndex = i;                           // here we assume that minimum value at index i
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);                  // here we are swapping values of minimum witn index i
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

    cout<<"Array before sorting:"<<endl;                      // printing array before sorting
    printArray(arr,n);

    selectionSort(arr,n);                                       // printing array after sorting
    cout<<endl<<"array after sorting:"<<endl;
    printArray(arr,n);


}