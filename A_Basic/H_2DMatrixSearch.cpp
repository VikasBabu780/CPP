// search element in row wise and column wise sorted matrix 

# include <iostream>
using namespace std;

bool searchMatrix(int arr[][4],int row,int col, int target){
    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0){
        int element = arr[rowIndex][colIndex];              // start from first row last col

        if(element == target){
            return 1;
        }
        if(element < target){
            rowIndex++;
        } else {
            colIndex--;
        }
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
    cout<<"enter the element to search : "<<endl;
    cin>>target;

    cout<<"answer is :"<<searchMatrix(arr,row,col,target)<<endl;
}