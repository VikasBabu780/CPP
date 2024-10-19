# include <iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    Deque(int size){
        this -> size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void pushFront(int data){
        // check full or not
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Deque is full so no element can be inserted !!"<<endl;
        } else if(front == -1){                        // single element is present
            front = rear = 0;
        } else if (front == 0 && rear != size-1){
            front = size-1;
        } else {
            front--;
        }
        arr[front] = data;
    }

    void pushRear(int data){
        // cehck full or not
        if((front == 0 && rear == size -1) ||(rear == (front-1)%(size-1))){
            cout<<"Deque if full so no more element can be inserted !!"<<endl;
        } else if(front == -1){
            front = rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else {
            rear++;
        }
        arr[rear] = data;

    }

    int popFront(){
        if(front == -1){                      // to check queue is empty
            cout<<"queue is empty !!"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){                         // single element is present
            front = rear = -1;
        } else if(front == size-1){                 // to maintain cyclic nature
            front = 0;
        } else {                                   // normal flow
            front++;
        }
        return ans ;
    }

    int popRear(){
        if(front == -1){                             // to check queue is empty
            cout<< " Queue is empty !!"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){                 // single element presnt hai
            front = rear = -1;
        }
        else if(rear == 0){
        rear = size-1;                   // to maintain cyclic nature
        } else {
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }else {
            return arr[front];
        }
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        } else {
            return arr[rear];
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }else {
            return false;
        }
    }

    bool isFull(){
        if((front == 0 && rear == size -1) ||(rear == (front-1)%(size-1))){
            return true;
        } else {
            return false;
        }
    }

};

int main(){
    Deque d(6);

    d.pushFront(3);
    d.pushFront(9);
    d.pushRear(5);

    cout<<d.popFront()<<endl;
    cout<<d.popRear()<<endl;

    if(d.isFull()){
        cout<<"Deque is full !!"<<endl;

    } else {
        cout<<"Deque is not full !!"<<endl;
    }


}
