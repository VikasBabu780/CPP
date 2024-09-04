# include <iostream>
using namespace std;

void printArray(int arr[],int size){                                        // function to print Array
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int partition(int arr[], int s, int e){
    int pivot = arr[s];

    int count = 0;
    for(int i =s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex] , arr[s]);                                     // place pivot at right place

    int i = s,j = e;
    while(i < pivotIndex && j > pivotIndex){                             // left and right part adjust 
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}

void quickSort(int *arr,int s,int e){
    if(s>=e){                                          // base case
        return;
    }
    int p = partition(arr,s,e);                               // partition

    quickSort(arr,s,p-1);                                   // left part recursive call
    quickSort(arr,p+1,e);                                      // right part recursive call
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

    cout<<"Array before sorting : "<<endl;
    printArray(arr,n);

    cout<<endl<<"Array after sorting : "<<endl;
    quickSort(arr,0,n-1);
    printArray(arr,n);

}