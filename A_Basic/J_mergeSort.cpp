// sort an array using merge sort
// time complexity O(nlogn)

# include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void merge(int *arr,int s,int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second  = new int[len2];

    int mainArrayIndex = s;                                             // copy  values
    for(int i =0; i <len1; i++){
        first[i]= arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i =0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;                                                       // merge two sorted array
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 <len1 && index2 < len2){
        if(first[index1] <second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        } else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 <len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;                                    // delete kr diya taki memory allocation me dikkat na aye or enka kam khatm ho gya tha
    delete []second;
}

void mergeSort(int *arr,int s,int e){
     if(s >=e ){                                       // base case
        return;
     }
    
    int mid = s+(e-s)/2;                               
     mergeSort(arr,s,mid);                                  // left part sort karna 

     mergeSort(arr,mid+1,e);                                   // right part sort karega

     merge(arr,s,e);
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

    cout<<"Array before sorting :"<<endl;
    printArray(arr,n);

    mergeSort(arr,0,n-1);
    cout<<endl<<"Array after sorting : "<<endl;
    printArray(arr,n);
}