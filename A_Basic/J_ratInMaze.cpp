# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void print(vector<string>v){                                           // print vector
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

void print2Dvector(vector<vector<int>>v,int row,int col){
    for(int i = 0; i<row; i++){
        for(int j =0; j<col; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int x,int y,int row,int col,vector<vector<int>>visited,vector<vector<int>> m){
    if((x >= 0 && x < row) && (y >= 0 && y < col) && visited[x][y] == 0 && m[x][y] == 1){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,int row,int col,vector<string>&ans,int x,int y,vector<vector<int>>visited,string path){
    // you have reached x,y here
    if(x == row-1 && y == col-1){                                  // base case
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // 4 choices = D ,L,R,U
    // down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx,newy,row,col,visited,m)){
        path.push_back('D');
        solve(m,row,col,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y-1;
    if(isSafe(newx,newy,row,col,visited,m)){
        path.push_back('L');
        solve(m,row,col,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y+1;
    if(isSafe(newx,newy,row,col,visited,m)){
        path.push_back('R');
        solve(m,row,col,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // up
    newx = x-1;
    newy = y;
    if(isSafe(newx,newy,row,col,visited,m)){
        path.push_back('U');
        solve(m,row,col,ans,newx,newy,visited,path);
        path.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> &m,int row,int col){
    vector<string> ans ;
    if(m[0][0] == 0){
        return ans;
    }
    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;
    for(int i =0; i<row; i++){
        for(int j =0; j<col; j++){
            visited[i][j] = 0;
        }
    }

    string path = " ";
    solve(m,row,col,ans,srcx,srcy,visited,path);
    sort(ans.begin(),ans.end());
    return ans;

}

int main(){
    int row,col;
    cout<<"enter your row and col number : ";
    cin>>row>>col;

    cout<<"enter "<<row*col<<" elements : "<<endl;
    vector<vector<int>> v (row,vector<int>(col));
        for(int i =0; i<row; i++){
            for(int j =0; j<col; j++){
                cin>>v[i][j];
            }
        }
    
    cout<<"your input vector is : "<<endl;
    print2Dvector(v,row,col);

    vector<string> s = findPath(v,row,col);
    cout<<endl<<"path is : "<<endl;
    print(s);

}