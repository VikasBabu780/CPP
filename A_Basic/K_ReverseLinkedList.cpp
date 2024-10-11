# include<iostream>
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

void print(node* &head){
    node * temp = head;

    while(temp != NULL){
        cout <<temp -> data <<" -> ";
        temp = temp -> next;

    }
    cout<<endl;

}

// recurssive way
node* reverse(node* head){
    
    // base case

    if(head == NULL || head -> next == NULL){
        return head ;
    }

    node* smallHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return smallHead;
}

// iterative way
node* reverseLinkedList(node* head){
    if(head == NULL || head -> next == NULL){
        
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        
      
    }
    return prev;  
   
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    node* curr = head;
    node* prev = NULL;
    print(head);

    InsertAtHead(head,tail,1);
    print(head);
    
    InsertAtTail(tail,head,2);
    print(head);

    InsertAtTail(tail,head,5);
    print(head);

    InsertAtPosition(head,tail,4,8);
    print(head);

    node* asn = reverse(head);
    cout<<"Reversed linked list is :"<<endl;
    print(asn);

    
}