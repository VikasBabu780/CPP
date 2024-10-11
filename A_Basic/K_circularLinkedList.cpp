# include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    // constructor
    node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    // destructor
    ~node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout <<"memory is free for node with data : "<< value<<endl;
    }
};

void insertNode(node* &tail,int element ,int d){

    // empty list
    if(tail == NULL){
        node* newNode = new node(d);
        tail = newNode;
        newNode -> next = newNode;
    } else{
        // non empty list
        // assuming that the element is present int the list

        node* curr = tail;

        while(curr -> data != element){
            curr = curr -> next;
        }

        //element found curr is reprenting the element wala node
        node* temp = new node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

void deleteNode(node* &tail,int value){
    // empty list
    if(tail == NULL){
        cout <<" list is empty "<<endl;
        return;
    } else {
        // non empty
        // assuming that value is present in the linked list
        node* prev = tail;
        node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        // 1 node linked list
        if(curr == prev){
            tail = NULL;
        }
        // node => 2
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void print(node* &tail){
    node* temp = tail;

    if(tail == NULL){
        cout<<" list is empty !";
        return;
    }
    
    do{
        cout << tail -> data<<" -> ";
        tail = tail -> next;

    } while (tail != temp);
    cout<<endl;

}

int main(){

    node* tail = NULL;

    //empty list me insert kr rhe hai
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    deleteNode(tail,5);
    print(tail);

}