// painter partition problem

# include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid){
    int painterCount = 1;
    int daySum = 0;

    for(int i =0; i<n; i++){
        if(daySum+arr[i] <= mid){
            daySum += arr[i];
        }else{
            painterCount++;
            if(painterCount > k || arr[i] > mid){             // checking distribution is true or false
                return false;
            }
            daySum = arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int n ,int k){
    int s = 0;
    int sum =0;

    for(int i =0; i<n; i++){
        sum +=arr[i];

    }
    int e = sum; 
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(arr,n, k ,mid)){
            ans = mid;
            e = mid -1;

        } else{
            s = mid +1;
        }
        mid = s+(e-s)/2;
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
    cout<<"enter the number of painter:";
    cin>>k;

    int answer = painterPartition(arr,n,k);
    cout<<"answer is :"<<answer;

}