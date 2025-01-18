# include <iostream>
# include<string>
# include <vector>
using namespace std;

void print(vector<string>v){                                           // print vector
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void print2Dvector(vector<vector<int>>v,int n){
    for(int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int newx,int newy,vector<vector<bool>> &vis,vector<vector<int>>&arr,int n){
    if((newx >= 0 && newx <n) && (newy >=0 && newy <n)&& vis[newx][newy] != 1 && arr[newx][newy] == 1){
        return true;
    }
}

void solve (int x,int y,vector <vector<int>> &arr,int n ,vector<string> &ans ,
vector<vector<bool>> &vis,string path){
    // base case
    if(x == n-1  && y == n-1){
        ans.push_back(path);
        return;
    }

    // D,L,R,U
    // Down
   if(isSafe(x+1,y,vis,arr,n)){
    vis[x][y] =1;
    solve(x+1,y,arr,n,ans,vis,path+'D');
    vis[x][y] = 0;

   }
   
   // left
   if(isSafe(x,y-1,vis,arr,n)){
    vis[x][y] =1;
    solve(x,y-1,arr,n,ans,vis,path+'L');
    vis[x][y] = 0;

   }

   //right
   if(isSafe(x,y+1,vis,arr,n)){
    vis[x][y] =1;
    solve(x,y+1,arr,n,ans,vis,path+'R');
    vis[x][y] = 0;

   }
   
   // up
   if(isSafe(x-1,y,vis,arr,n)){
    vis[x][y] =1;
    solve(x-1,y,arr,n,ans,vis,path+'U');
    vis[x][y] = 0;

   }


}

vector <string> searchMaze(vector <vector<int>> &arr,int n){
    vector<string> ans ;
    vector <vector<bool>>visited (n,vector<bool>(n,0));
    string path = " ";
    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0,arr,n,ans,visited,path);
    return ans;
}

int main(){
    int n;
    cout<<"enter order of matrix : ";
    cin>>n;

    cout<<"enter "<<n*n<<" elements : "<<endl;
    vector<vector<int>> v (n,vector<int>(n));
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                cin>>v[i][j];
            }
        }
    
    cout<<"your input vector is : "<<endl;
    print2Dvector(v,n);

    vector<string> s = searchMaze(v,n);
    cout<<endl<<"path is : "<<endl;
    print(s);

    return 0;
}