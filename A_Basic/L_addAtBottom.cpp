# include <iostream>
# include <stack>
using namespace std;

void solve(stack<int> &s,int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s,x);

    s.push(num);
}

stack <int> pushAtBottom(stack<int> &st,int x){
    solve(st,x);
    return st;
}

void print(stack<int> s) { // Pass by value to keep original stack
    while (!s.empty()) {
        cout << s.top() << " "; // Print the top element
        s.pop();                      // Remove the top element
    }
    cout <<endl;
}

int main(){

    stack <int> st;

    int size;
    cout<<" enter the size of stack :";
    cin>>size;

    int x; 
    cout<<"enter the value of x :";
    cin>>x;

    for(int i =0; i<size; i++){
        int num;
        cout<<"enter number :";
        cin>>num;
        st.push(num);
    }
    
    cout<<"stack before value is pushed :"<<endl;
    print(st);

    stack <int> ans = pushAtBottom(st,x);

    cout<<"stack after value is pushed : "<<endl;
    print(ans);
    
}