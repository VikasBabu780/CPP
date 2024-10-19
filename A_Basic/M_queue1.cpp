# include <iostream>
using namespace std;

class Queue{
    
    public:
    int *arr;
    int qfront;
    int rear;
    int size;

    Queue(int size){
        this -> size = size;
        arr = new int [size];
        qfront = 0;
        rear = 0;
    }

void enQueue(int data){
    if (rear == size){
        cout<<"Queue is full !!";
    } else {
        arr[rear] = data;
        rear++;
    }
} 

int deQueue(){
    if(qfront == rear){
        return -1;
    } else {
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear){
            qfront = 0;
            rear = 0;
        }
        return ans;
    }
}
    
int front(){
    if(qfront == rear){
        return -1;
    } else {
        return arr[qfront];
    }
}


bool isEmpty(){
    if(qfront == rear){
        return true;
    } else {
        return false;
    }
}

};

int main(){
    Queue q(4);
    q.enQueue(2);
    q.enQueue(5);
    q.enQueue(7);
    q.enQueue(9);

    cout<<"front element is : " <<q.front()<<endl;;
    
    q.deQueue();

    cout<<"After dequeue front element is : " <<q.front()<<endl;;

    if(q.isEmpty()){
        cout<<"queue is empty !!"<<endl;;
    } else {
        cout <<"queue is not empty !!"<<endl;
    }
}