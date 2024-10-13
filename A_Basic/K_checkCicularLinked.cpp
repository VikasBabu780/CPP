# include <iostream>
# include <map>
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

bool isCircularList(node* head){
    // empty list
    if( head == NULL){
        return false;
    }

    node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    } else {
        return false;
    }
}

bool detectLoop(node* &head){                        // detect loop algorithm
    // empty list
    if( head == NULL){
        return false;
    }

    map<node*, bool> visited;

    node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
        return true;
    }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
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
    
    if(isCircularList(tail)){
         cout<<"Linked list is circular ";
    }  else{
        cout<<" Linked list is not circular";
    } cout<<endl;

    if(detectLoop(head)){
         cout<<"Linked list is circular ";
    }  else{
        cout<<" Linked list is not circular";
    }
    
}