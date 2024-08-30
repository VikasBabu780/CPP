// to print row wise sum &  column wise

# include <iostream>
# include <math.h>
using namespace std;

void calSumRow(int arr[][4],int row,int col){
     
    for(int i = 0; i<row; i++){                  // function to print row wise sum
        int sum = 0;
        for(int j =0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }

}

void calSumCol(int arr[][4],int row,int col){
     
    for(int j = 0; j<col; j++){                  // function to print column wise sum
        int sum = 0;
        for(int i =0; i<row; i++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }

}

int largestRowSum(int arr[][4] ,int row ,int col){               // function that find the largest sum in row & row number
    int maxi = INT8_MIN;
    int rowIndex = -1;

    for(int i = 0; i<row; i++){                  // function to print row wise sum
        int sum = 0;
        for(int j =0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
        if(sum> maxi){
            maxi = sum;
            rowIndex = i;
        }
    }
    cout<<"the maximum sum is :"<<maxi<<endl;
    return rowIndex;
    
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

    cout<<"Sum of rows are : "<<endl;
    calSumRow(arr,row,col);

    cout<<endl<<"Sum of columns are : "<<endl;
    calSumCol(arr,row,col);

    cout<<endl<<largestRowSum(arr,row,col)<<endl;
}