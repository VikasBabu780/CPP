// travese an array in wave manner

# include <iostream>
 using namespace std;

 void wavePrintArray(int arr[][4],int row,int col){
    for(int j =0; j<col; j++){
        if(j&1){                                  // odd index (bottom to top)
        
            for(int i = row-1; i>=0; i--){           
                cout<<arr[i][j]<<" ";
            } 
        } else {                                       // even index (top to bottom)
                for(int i = 0; i< row; i++){
                    cout<<arr[i][j]<<" ";
                }
        }
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

    cout<<"Array after traversing :"<<endl;
    wavePrintArray(arr,row,col);
 }