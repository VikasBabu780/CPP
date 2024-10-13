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
        cout<<temp -> data <<" -> ";
        temp = temp -> next;

    }
    cout<<endl;

}

node* getMid(node* head){
    node* slow = head;
    node* fast =  head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node* reverse(node* & head){
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

bool checkPalindrome(node* &head){
    if(head == NULL || head -> next == NULL){
        return true;
    }
    // step 1 = mid nikalo
    node* middle = getMid(head);

    // step 2 = reverse list after middle
    node* temp = middle -> next;
    middle -> next = reverse(temp);

    // step 3 = compare both halfs
    node* head1 = head;
    node* head2 = middle -> next;

    while( head2 != NULL){
        if( head1 -> data != head2 -> data){
            return false;
        }else {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }
    // step 4 = repeat step 2
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;
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

    InsertAtPosition(head,tail,4,0);
    print(head);

    InsertAtPosition(head,tail,5,1);
    print(head);

    if(checkPalindrome(head) == true){
        cout<<" List is palindrome "<<endl;
    } else {
        cout<<" List is not Palindrome "<<endl;
    }

}