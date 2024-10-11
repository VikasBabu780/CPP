# include<iostream> 
using namespace std;
class node{
    public:
    int data;
    node* next;

    // constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

node* kReverse(node* head,int k){
    // base case
    if(head == NULL){
        return NULL;
    }

    // step 1 reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 recurssive call
    if(next != NULL){
        head -> next = kReverse(next,k);
    }

    // step 3 return head of reversed list
    return prev;

}

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

int main(){
    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,4);
    print(head);
    
    InsertAtTail(tail,head,7);
    print(head);

    InsertAtTail(tail,head,8);
    print(head);

    InsertAtPosition(head,tail,4,9);
    print(head);

    InsertAtPosition(head,tail,5,0);
    print(head);

    InsertAtPosition(head,tail,6,1);
    print(head);

    node* ans = kReverse(head,4);
    cout<<"reversed linked list : "<<endl;
    print(ans);
    
}