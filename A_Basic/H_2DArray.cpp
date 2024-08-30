# include <iostream>
using namespace std;

bool isPresent(int arr[][4],int target){
    for(int i = 0; i<3; i++){
        for(int j =0 ; j<4; j++){
            if(arr[i][j] == target){
                return 1;
            }
        }
    }
    return 0;

}

int main(){
   int row = 3;
   int col =4;

    int arr[3][4];                                 // create 2d array

    cout<<"enter "<<row*col<<" elements :"<<endl;
    for(int i =0 ; i<row; i++){                      // taking input
        for(int j = 0; j<col; j++){
            cin>>arr[i][j];
        }
        
    }cout<<endl;

for(int i =0 ; i<row; i++){                      // printing output
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"enter the element to search : "<<endl;
    int target;
    cin>>target;

    if(isPresent(arr,target)){
        cout<<"found !";

    }else {
        cout<<"not found !";
    }
    
}