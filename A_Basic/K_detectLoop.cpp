# include <iostream>
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

node* floydDetectLoop(node* head){
    if(head == NULL){
        return NULL;
    }
    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast){
            cout<<"cycle is present at : "<< slow -> data<<endl;            // not necessary to give starting node of loop
            return slow;
        }
    }
    return NULL;

}

node* getstartingNode(node* head){
    if(head == NULL){
        return NULL;
    }

    node* intersection = floydDetectLoop(head);
    node* slow = head;

    while( slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(node* head){
    if(head == NULL){
        return;
    }
    node* startOfLoop = getstartingNode(head);
    node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
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

    tail -> next = head -> next;

    if(floydDetectLoop(head) != NULL){
        cout<< "cicrcle is present "<<endl;

    } else{
        cout<<" circle is not present";
    }

    node* loop = getstartingNode(head);
    cout<< "loop start at : "<<loop -> data<<endl;

    removeLoop(head);
    print(head);
}