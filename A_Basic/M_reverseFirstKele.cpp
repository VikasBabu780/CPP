// reverse first k elements of Queue

# include <iostream>
# include <stack>
# include<queue>
using namespace std;
queue <int> reverseKElements(queue<int> q,int k){
    // step1 : pop first k elements from Q and put into stack
    stack <int> s;

    for(int i =0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2 : fetch from stack and push into Q
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3 : fetch first (n-k) elements from Q and push back
    int t = q.size()-k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
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

int main (){
    queue <int> m;

    m.push(1);
    m.push(2);
    m.push(3);
    m.push(4);
    m.push(5);

    cout<<"Queue is : ";
    print(m);

    int k;
    cout<<"enter the value of k : ";
    cin>>k;

    queue <int> ans = reverseKElements(m,k);
    cout<<"Queue after reversing k elments : ";
    print(ans);

}