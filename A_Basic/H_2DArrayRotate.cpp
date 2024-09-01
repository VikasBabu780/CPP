// program to rotate array by 90 degree

# include <iostream>
using namespace std;

void rotateMatrix(int arr[][3],int row , int col){
    int sr = 0;
    int sc = 0; 
    int er = row -1;
    int ec = col-1;
    int count = 0;
    int total = row*col;

    while(count<total){                                      // function to rotate array by 90 degree
        for(int row = er; count<total && row >= sr; row--){
            cout<<arr[row][sc]<<" ";
            count++;
        } sc++;
        cout<<endl;

        
    }
}

int main(){
    int row;
    int col;

    cout<<"enter row & col no : "<<endl;
    cin>>row;
    cin>>col;

    int arr[3][3];

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
    cout<<"Matrix after rotation : "<<endl;
    rotateMatrix(arr,row,col);

}