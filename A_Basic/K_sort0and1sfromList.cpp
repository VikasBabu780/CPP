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

void insertAtTail(node* &tail, node* curr){
    tail -> next = curr;
    tail = curr;
}

node* sortList1(node* head){ 
    // creation of dummy nodes                                     // apporach 1
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    node* curr = head;

     // create separate list of 0 1 and 2
    while(curr != NULL){
        int value = curr -> data;

        if(value == 0){
            insertAtTail(zeroTail,curr);
        }
        else if (value == 1){
            insertAtTail(oneTail,curr);
        }
        else if (value == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr -> next;
    }

    // merge lists
    // is not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;

    } else {
        // list is empty
        zeroTail-> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // setup head
    head = zeroHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}

node* sortList(node* head){                                // approach 2
    int zeroCount  = 0;
    int oneCount = 0;
    int twoCount = 0;

    node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            zeroCount++;

        } 
        else if( temp -> data == 1){
            oneCount++;
        }
        else if(temp -> data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
    return head;
}

void print(node* &head){
    node * temp = head;

    while(temp != NULL){
        cout<<temp -> data <<" -> ";
        temp = temp -> next;

    }
    cout<<endl;

}

int main(){

    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,1);
    print(head);
    
    InsertAtTail(tail,head,0);
    print(head);

    InsertAtTail(tail,head,2);
    print(head);

    InsertAtPosition(head,tail,4,1);
    print(head);

    InsertAtPosition(head,tail,5,2);
    print(head);

    node* ans = sortList(head);
    cout<<"List after sorting : "<<endl;
    print(ans);

}