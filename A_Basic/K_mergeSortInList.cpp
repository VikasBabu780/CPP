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

void print(node* &head){
    node * temp = head;

    while(temp != NULL){
        cout<<temp -> data <<" -> ";
        temp = temp -> next;

    }
    cout<<endl;

}

node* findMid(node* & head){
    node* slow = head;
    node* fast = head -> next;

    while( fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node* merge(node* & left,node* &right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans ;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }

    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while( right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}

node* mergeSort(node* & head){
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    // break linked list into 2 halfs after finding mid
    node* mid = findMid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

     // recursive call to sort both halfs
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    node* result = merge(left,right);

    return result;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    print(head);

    InsertAtHead(head,tail,8);
    print(head);
    
    InsertAtTail(tail,head,2);
    print(head);

    InsertAtTail(tail,head,3);
    print(head);

    InsertAtPosition(head,tail,4,1);
    print(head);

    InsertAtPosition(head,tail,5,0);
    print(head);

    node* ans = mergeSort(head);
    cout<<"list after merging "<<endl;
    print(ans);

}