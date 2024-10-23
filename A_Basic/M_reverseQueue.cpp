# include <iostream>
# include <stack>
# include <queue>
using namespace std;

queue <int> rev(queue <int> q){
    stack <int> s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;

}

void print(queue <int> q){
    while(!q.empty()){
        int element = q.front();
        cout<<element<<" ";
        q.pop();
    } cout<<endl;
}

int main(){
    queue <int> m;

    m.push(4);
    m.push(3);
    m.push(1);
    m.push(10);
    m.push(2);
    m.push(6);

    cout<<"Queue is : ";
    print(m);

    queue <int> s = rev(m);
    cout<<"Queue after reversing is : ";
    print(s);

}