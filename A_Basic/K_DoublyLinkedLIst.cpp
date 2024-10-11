# include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* prev;
    node* next;

    // constructor
    node(int d){
    this -> data = d ;
    this -> prev = NULL;
    this -> next = NULL;
    }
    //destructor
    ~node(){
        int  val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data"<<val<<endl;
    }
};


void InsertAtHead(node* &head,node* & tail,int d){
    // empty list
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }else{
        node* temp = new node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

void InsertAtTail(node* &tail,node* &head,int d){
    // empty list
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;

    } else{
        node* temp = new node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(node* &head,node* &tail,int position ,int d){
    // insert at start
    if(position == 1){
        InsertAtHead(head,tail,d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp ->next;
        cnt++;
    }

    // inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail,head,d);
        return;
    }

    // creating a node for d
    node* nodeToInsert = new node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next -> prev = nodeToInsert;

    temp -> next = nodeToInsert;

    nodeToInsert -> prev = temp;
}

void deleteNode(int position, node* &head){
    // deleteing first or starting node
    if(position == 1){
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    } else{
        // deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
             prev = curr;
             curr = curr -> next;
             cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }
}

// traversing a linked list
void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout <<temp -> data<<" <-> ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    
    node* head = NULL;
    node* tail = NULL;

    print(head);

    InsertAtHead(head,tail,11);
    print(head);

     InsertAtHead(head,tail,12);
    print(head);

    InsertAtHead(head,tail,13);
    print(head);

    InsertAtTail(tail,head,9);
    print(head);

    InsertAtPosition(head,tail,5,45);
    print(head);

    deleteNode(3,head);
    print(head);
}