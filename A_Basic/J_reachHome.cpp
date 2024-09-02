// source to destination

# include <iostream>
using namespace std;

void reachHome(int src , int dest){

    cout<<"Source "<<src<<" destination "<<dest<<endl;

    if(src == dest){                                  // base case
        cout<<"raeched home "<<endl;
        return;
    }

    src++;                                    //    processing

    reachHome(src,dest);                       //   recursive call
}
int main(){
    int dest = 10;
    int src = 1;

    reachHome(src,dest);
}