// seraching in 2D matrix binary search in a sorted matrix
// time coplexity O(log(row*col))

# include <iostream>
using namespace std;

bool searchMatrix(int arr[][4], int row , int col,int target){
    int s = 0;
    int e = row* col -1;
    int mid = s+(e-s)/2;

    while(s <= e){
        int element = arr[mid/col][mid % col];              // important line mid ko col se divide and modulo le lo
        if(element == target){
            return 1;
        }
        if(element > target){
            e = mid -1;

        }else {
            s = mid+1;
        }
        mid = s +(e-s)/2;
    }
    return 0;
}

int main(){
    int row;
    int col;

    cout<<"enter row & col no : "<<endl;
    cin>>row;
    cin>>col;

    int arr[3][4];

    cout<<"enter "<<row*col<<" elements :"<<endl;
    for(int i =0 ; i<row; i++){                      // taking input
        for(int j = 0; j<col; j++){
            cin>>arr[i][j];
        }
        
    }cout<<endl;

    cout<<"Array is : "<<endl;
    for(int i =0 ; i<row; i++){                      // printing output
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int target;
    cout<<"enter the number to serach : ";
    cin>>target;

    cout<<"answer is : "<<searchMatrix(arr,row,col,target)<<endl;
}