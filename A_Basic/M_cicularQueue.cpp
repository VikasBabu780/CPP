# include <iostream>
using namespace std;

class circularQueue{
    public:
    int *arr;
    int front; 
    int rear; 
    int size;

    circularQueue(int size){
        this -> size = size;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    void enQueue(int data){
        // to check wheather Queue is full or not
        if((front == 0 && rear == size -1)|| (rear == (front -1)%(size -1))){                    
            cout <<"Queue is full !!";
        } else if(front == -1) {                                  // first element to push
            front = rear = 0;
            
        } else if (rear == size -1 && front != 0){
            rear = 0;                                          // to maintain cyclic nature
            
        } else {
            rear++;                                              // normal flow
        
        }
        arr[rear] = data;                                       // push inside the queue
    }

    int deQueue(){
        if(front == -1){                             // to check queue is empty
            cout<< " Queue is empty !!"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){                 // single element presnt hai
            front = rear = -1;
        }
        else if(front == size -1){
            front = 0;                   // to maintain cyclic nature
        } else {
            front ++;
        }
        return ans;

    }
};

int main(){

    circularQueue q(4);

    q.enQueue(2);
    q.enQueue(5);
    q.enQueue(7);
    q.enQueue(8);

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;

}
