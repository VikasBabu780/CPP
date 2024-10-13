// remove duplicates from a sorted linked list

# include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

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

node* removeDuplicates(node* &head){
    // empty list
    if( head == NULL){
        return NULL;
    }

    // non empty list
    node* curr = head;

    while(curr != NULL){
        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
            node* next_next = curr -> next ->next;
            node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        } else {
            curr = curr -> next;
        }
    }
    return head;
}

void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    } cout<<endl;
    
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,4);
    print(head);
    
    InsertAtTail(tail,head,4);
    print(head);

    InsertAtTail(tail,head,6);
    print(head);

    InsertAtPosition(head,tail,4,7);
    print(head);

    InsertAtPosition(head,tail,5,9);
    print(head);
 
    node* ans = removeDuplicates(head);
    print(ans);
    
}