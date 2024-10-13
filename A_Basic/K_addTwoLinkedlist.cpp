// time complexity O(m+n)  m,n are entries of list

# include <iostream>
# include <List>
using namespace std;

class node{

    public:
    int data;
    node* next;

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

node* reverse(node* head){

    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* add(node* &head1,node* &head2){
    int carry = 0;

    node* ansHead = NULL;
    node* ansTail = NULL;

    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1 -> data + head2 -> data;
        int digit = sum % 10;
        node* temp = new node(digit);

        // create node and ans in linked list
        InsertAtTail(ansTail,ansHead,digit);

        carry = sum /10;
        head1 = head1 -> next;
        head2 = head2 -> next;

    }

    while(head1 != NULL){
        int sum = carry + head1 -> data;
        int digit = sum % 10;

        // create node and ans in linked list
        InsertAtTail(ansTail,ansHead,digit);

        carry = sum /10;
        head1 = head1 -> next;
    }

    while(head2 != NULL){
        int sum = carry + head2 -> data;
        int digit = sum % 10;

        // create node and ans in linked list
        InsertAtTail(ansTail,ansHead,digit);

        carry = sum /10;
        head2 = head2 -> next;
    }

    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;

        // create node and ans in linked list
        InsertAtTail(ansTail,ansHead,digit);

        carry = sum /10;
    }
    return ansHead;

}

node* addTwoList(node* &head1,node* &head2){
    // step1 = reverse input linked lists
    head1 = reverse(head1);
    head2 = reverse( head2);

    // step2 = add two linked list
    node* ans = add(head1,head2);

    // step3 = reverse ans list
    ans = reverse(ans);

    return ans;

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
    node* head1 = NULL;
    node* tail1 = NULL;
    node* head2 = NULL;
    node* tail2 = NULL;
    print(head1);

    InsertAtHead(head1,tail1,4);
    print(head1);

    InsertAtPosition(head1,tail1,2,5);
    cout<<" linked list 1 is :"<<endl;
    print(head1);

    print(head2);

    InsertAtHead(head2,tail2,3);
    print(head2);
    
    InsertAtTail(tail2,head2,4);
    print(head2);

    InsertAtPosition(head2,tail2,3,5);
    cout<<" linked list 2 is :"<<endl;
    print(head2);

    node* ans = addTwoList(head1,head2);
    cout<<"list after addition :"<<endl;
    print(ans);

}