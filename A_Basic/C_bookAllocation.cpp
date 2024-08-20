// book allocation problem 

# include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i =0; i<n; i++){
        if(pageSum+arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > m || arr[i] >mid){             // checking distribution is true or false
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n ,int m){
    int s = 0;
    int sum =0; 

    for(int i =0; i<n; i++){                 //calculating sum of array
        sum += arr[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(arr,n, m ,mid)){
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

    int m ;
    cout<<"enter the number of students for distribution:";
    cin>>m;


    int answer = allocateBooks(arr,n,m);
    cout<<"answer is:"<<answer;

}