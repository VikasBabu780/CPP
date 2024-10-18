# include <iostream>
# include <stack>
using namespace std;

bool knows(int M[][4],int a ,int b,int n){
    if(M[a][b] == 1){
        return true;
    } else {
        return false;
    }

}

int celebrity(int M[][4] ,int n){
    stack <int> s;
    // push all elements in stack
    for(int i = 0; i< n; i++){
        s.push(i);

    }

    //  get 2 elements and compare them
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }else {
            s.push(a);
        }
    }
    int ans = s.top();
    // single element in stack is potential celebrity
    // so verify it
    bool rowCheck = false;
    int zeroCount = 0;

    for(int i = 0; i<n; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }
    if(zeroCount == n){
        rowCheck = true;
    }

    // col check
    bool colCheck = false;
    int oneCount = 0;

    for(int i =0; i<n; i++){
        if(M[i][ans] == 1){
             oneCount++;
        }
    }

    if (oneCount == n-1){
        colCheck = true;
    }

    if(rowCheck == true && colCheck == true){
        return ans;
    } else {
        return -1;
    }
}

int main(){
    int size = 4;

    int arr[4][4];

    cout<<"enter "<<size*size<<" elements :"<<endl;
    for(int i = 0 ; i<size; i++){                      // taking input
        for(int j = 0; j<size; j++){
            cin>>arr[i][j];
        }
        
    }cout<<endl;

    cout<<"Array is : "<<endl;
    for(int i =0 ; i<size; i++){                      // printing output
        for(int j = 0; j<size; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int ans = celebrity(arr,4);
    cout<<"celebrity is : "<<ans <<endl;
}

