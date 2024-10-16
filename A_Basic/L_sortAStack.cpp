# include <iostream>
# include <stack>
using namespace std;

void sortedInsert(stack <int> &st,int num){
    // base case
    if(st.empty() || (!st.empty() && st.top() < num)){
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    // recrursive call
    sortedInsert(st,num);

    st.push(n);

}

void sortStack(stack <int> &st){
    // base case
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    sortedInsert(st,num);
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
    cout<<"enter size of stack : "<<endl;
    cin>>size;

    for(int i =0; i<size; i++){
        cout<<"enter number  : "<<endl;
        int num;
        cin>>num;
        st.push(num);
    }

    cout<<"stack before sorting : "<<endl;
    print(st);

    sortStack(st);
    cout<<"stack after sorting : "<<endl;
    print(st);
}