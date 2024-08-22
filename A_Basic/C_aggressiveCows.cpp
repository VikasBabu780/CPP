// Aggressive cows

# include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {                // sorting an array
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool isPossible(int arr[], int mid ,int k,int n){         // checking condition of true or false
    int cowCount = 1;
    int lastPos = arr[0];
    for(int i =0; i< n; i++){
        if(arr[i]-lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = arr[i];
        }

    }
    return false;
}

int aggressiveCows(int arr[], int n, int k){
    bubbleSort(arr,n);
    int s =0;
    int maxi = -1;
    for(int i =0; i<n; i++){
        maxi = max(maxi,arr[i]);        // calculating maximunm value

    }
    int e = maxi;
    int ans = -1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(isPossible(arr, mid,k,n)){
            ans = mid;
            s = mid +1;
        } else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
        
    }
    return ans;
}

int main(){
    int n ;
    cout<<"enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"enter "<<n<<" elements:"<<endl;     
    for(int i =0; i<n; i++){                                   // entries of array
        cin>>arr[i];
    }

    int k ;
    cout<<"enter the number of cows:";
    cin>>k;

    int answer = aggressiveCows(arr,n,k);
    cout<<"answer is :"<<answer;
}