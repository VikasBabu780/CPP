// priority queue

# include <iostream>
# include <queue>

using namespace std;

int main(){
    priority_queue<int> maxi;                                      // max heap banane ka tarika
    
    priority_queue<int,vector<int> ,greater<int> >mini;                            // mini heap banane ka tarika

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
 
    int n = maxi.size();                        
    for(int i = 0; i<n; i++){                                    // maxi me sabse pahle maximum element print hota h
        cout<<maxi.top()<<" ";
        maxi.pop();

    }cout<<endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for(int i =0; i<m; i++){                                         // mini me minimum element sqabse pahle print hota h
        cout<<mini.top()<<" ";
        mini.pop();

    }cout<<endl;

}