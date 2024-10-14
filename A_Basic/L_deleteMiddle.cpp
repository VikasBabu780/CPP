// delete middle element from stack

# include <iostream>
# include<stack>
using namespace std;

void solve (stack <int> st,int count ,int size){
    // base case
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    // recursive call
    solve(st,count+1,size);

    st.push(num);
}

void deleteMiddle(stack <int> st,int n){
    int count = 0;
    solve(st,count ,n);
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

    int num;
    
    for(int i =0; i<size; i++){
        cout<<"enter number to be pushed in array : "<<endl;
        cin>>num;
        st.push(num);
    }

    print(st);
    deleteMiddle(st,size);

}

