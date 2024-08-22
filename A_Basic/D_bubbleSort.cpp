// bubble sort (neighbour elements ko compare karate hue chalna hai)
// time complexity O(n^2) where n is the size of array

# include <iostream>
using namespace std;

void printArray(int arr[],int n){           //function to print an array
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}

void bubbleSort(int arr[], int n){
    for(int i =0; i < n-1; i++ ){               // for ruon 1 to n-1 
        bool swapped = false;
        for(int j = 0; j < n-i; j++){                // process element till  (n-i)th index
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);      // swapping arr[j] with arr[j+1]
                 swapped = true;
            }
        }
        if(swapped == false){                 //   already sorted
            break;
        }
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

    bubbleSort(arr,n);                                      // calling  bubble sort function 
    cout<<endl<<"Array after sorting:"<<endl;  
    printArray(arr,n);                                        // calling printing function

}