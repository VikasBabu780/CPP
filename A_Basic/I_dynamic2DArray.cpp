# include <iostream>
using namespace std;

int main(){
    int row ,col;
    cout<<"enter the value of row and col : ";
    cin>>row>>col;

    int ** arr = new int*[row];

    for(int i =0; i<row; i++){                                // craeting 2D array dynamically
        arr[i] = new int[col];
    }

    cout<<"enter "<<row*col<<" elements : "<<endl;
    for(int i =0; i<row; i++){
        for(int j =0; j<col; j++){                              // taking input
            cin>>arr[i][j];
        }

    }cout<<endl;

    cout<<" matrix is :"<<endl;
    for(int i =0; i<row; i++){                              // printing output
        for(int j =0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i =0 ; i<row; i++){                                // releasing memorry
        delete[] arr[i];
    }
    delete[]arr;

}