# include <iostream>
using namespace std;

class node{

    public:
    int data;
    node *next;

    // constructor
    node(int data){                                     
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~node(){
        int value = this -> data;
        // memory free
        if(this -> next != NULL){
            delete next;
            this ->next = NULL;
        }
        cout<<"memory is free for with data : "<< value <<endl;
    }

};

void InsertAtHead(node* &head,node* &tail,int d){

    // new node create
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    } else{
        node* temp = new node(d);
        temp -> next = head;
        head = temp; 
    }
}

void InsertAtTail(node* &tail ,node* &head,int d){
    // new node create
    if(tail == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    } else{
        node* temp = new node(d);
        tail -> next = temp;
        tail = tail ->next;
    }
}

void InsertAtPosition(node* &head,node* &tail,int position ,int d){
    
    if(position == 1){
        InsertAtHead(head ,tail,d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }
    
    // inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail,head,d);
        return;
    }
    // creating node for d
    node* nodeToInsert= new node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;


}

void deleteNode(int position ,node* &head,node* &tail){
    // deleting the first or starting node
    if(position == 1){
        node* temp = head;
        head = head -> next;
        // memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting last node or any node
        node* curr = head;
        node* prev = NULL;

        int cnt =1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            if(curr -> next == NULL){
                tail = prev;
            }
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(node* &head){
    node * temp = head;

    while(temp != NULL){
        cout <<temp -> data <<" -> ";
        temp = temp -> next;

    }
    cout<<endl;

}

int main(){
    
    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,10);
    print(head);
    
    InsertAtTail(tail,head,12);
    print(head);

    InsertAtTail(tail,head,15);
    print(head);

    InsertAtPosition(head,tail,4,22);
    print(head);

    cout<<"head : "<< head->data<<endl;
    cout<<"tail : "<< tail->data<<endl;

    deleteNode(4,head,tail);
    print(head);

    cout<<"head : "<< head->data<<endl;
    cout<<"tail : "<< tail->data<<endl;

    
}