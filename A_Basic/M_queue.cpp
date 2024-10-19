# include <iostream>
# include <queue>
using namespace std;

int main (){

    // create queue
    queue <int> q;

    q.push(12);
    q.push(15);
    q.push(17);
    q.push(19);

    cout <<"size of queue is : "<<q.size() <<endl;
    q.pop();
    cout <<"front of queue is : "<<q.front()<<endl;

    cout <<"size of queue is : "<<q.size() <<endl;

    if(q.empty()){
        cout<<"queye is empty ";
    }else{
        cout <<"queue is not empty ";
    }

}