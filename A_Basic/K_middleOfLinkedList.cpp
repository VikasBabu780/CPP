# include<iostream>
using namespace std;

class node {
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

int getLength(node* head){
    int len =0;
    while(head != NULL){
        len++;
        head = head -> next;
    }

    return len;
}

node* findMiddleNode(node* head){                            // 1st way
    int len = getLength(head);
    int ans =  (len/2);
    node* temp = head;
    int cnt =0;
    while(cnt < ans){
        temp = temp -> next;
        cnt++;
    }
    return temp;
    
}

node* getMiddle(node* head){                             // 2nd way
    if(head == NULL || head -> next == NULL){
        return head;
    }
    // 2 nodes
    if(head -> next -> next == NULL){
        return head -> next;
    }

    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,1);
    print(head);
    
    InsertAtTail(tail,head,2);
    print(head);

    InsertAtTail(tail,head,5);
    print(head);

    InsertAtPosition(head,tail,4,12);
    print(head);

    InsertAtPosition(head,tail,5,15);
    print(head);

    node* ans = getMiddle( head);
    cout<<"Middle node is : "<<ans -> data<<endl;
    

}