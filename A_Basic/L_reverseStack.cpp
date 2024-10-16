# include <iostream>
# include <stack>
using namespace std;

void insertAtBottom(stack <int> &st,int element){
    // base case
    if(st.empty()){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();

    //recursive call
    insertAtBottom(st,element);

    st.push(num);
}

void reverseStack(stack <int> &st){

    // base case
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    //recursive call
    reverseStack(st);

    insertAtBottom(st,num);

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

    for(int i =0; i<size; i++){
        int num;
        cout<<"enter number :";
        cin>>num;
        st.push(num);
    }

    print(st);

    reverseStack(st);
    cout<<"stack after reversing : "<<endl;
    print(st);
    
}
