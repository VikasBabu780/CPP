// print spiral order of matrix

# include <iostream>
using namespace std;

void spiralPrintArray(int arr[][4],int row, int col){
    int row_start = 0;
    int col_start = 0;
    int row_end = row-1;
    int col_end = col-1;
    int count = 0;
    int total = row*col;

    while( count < total){
        for(int col = col_start; count < total && col<=col_end; col++ ){  //print starting row
            cout<<arr[row_start][col]<<" ";
            count++;
        } row_start++;

        for(int row = row_start; count < total && row<=row_end; row++ ){ // print ending column
            cout<<arr[row][col_end]<<" ";
            count++;
        } col_end--;

        for(int col = col_end; count < total && col>=col_start; col-- ){   // print emnnding row
            cout<<arr[row_end][col]<<" ";
            count++;
        }row_end--;

        for(int row = row_end; count < total && row >=row_start; row--){    // print ending column
            cout<<arr[row][col_start]<<" ";
            count++;
        }col_start++;
    }
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

    cout<<"spiral Array print is : "<<endl;
    spiralPrintArray(arr,row,col);
}