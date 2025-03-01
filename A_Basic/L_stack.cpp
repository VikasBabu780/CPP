# include<iostream>
using namespace std;

class stack{
    // properties
    public :
    int *arr;
    int top;
    int size;

    //constructor
    stack(int size){
        this -> size = size;
        arr = new int [size];
        top = -1;
    }

    void push(int element){
        if(top < size){
            top++;
            arr[top] = element;
        } else{
            cout<<"STACK OVERFLOW !!!!"<<endl;
        }
    }
    
    void pop(){
        if(top >= 0){
            top--;
        } else {
            cout<<"STACK UNDERFLOW !!!!"<<endl;
        }
    }

    int peek(){
        if(top >= 0 ){
            return arr[top];
        } else{
            cout<<"STACK IS EMPTY !!!!  ";
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }

};

int main(){
    stack st(5);

    st.push(22);
    st.push(43);
    st.push(50);

    cout<<st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;

    st.pop();
    st.pop();

    cout<<st.peek()<<endl;

}