# include <iostream>
# include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }
};

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        // purana level complete ho chuka hai
        if(temp == NULL){
            cout<< endl;
            //queue still has some child nodes
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout<<temp -> data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp ->right);
            }
        }
    }
}

node* insertIntoBST(node* root,int d){
    // base case
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(d > root -> data){
        // right part me insert karna hai
        root -> right = insertIntoBST(root -> right ,d);
    } else {
        // left part me insert karna hai
        root -> left = insertIntoBST(root -> left ,d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

// recursive way
bool searchInBST(node* root ,int x){
    // base case
    if(root == NULL){
        return false;
    }
    if(root -> data == x ){
        return true;
    }

    if(root -> data > x){
        // left part me
        return searchInBST(root -> left ,x);
    } else {
        // right part me
        return searchInBST(root -> right ,x);
    }
}

// iterative way
bool searchInBst(node* root , int x){
    node* temp = root;

    while(temp != NULL){
        if(temp -> data == x){
            return true;
        }
        if(temp -> data > x){
            temp = temp -> left;
        } else {
            temp = temp -> right;
        }
    }
    return false;
}

int main(){
    node* root = NULL;

    cout <<"Enter data to create BST :" <<endl;
    takeInput(root); 

    cout <<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    int x;
    cout<<"enter the value of node to be searched :"<<endl;
    cin>>x;

    if(searchInBst(root,x)){
        cout<<"node is present !"<<endl;
    } else{
        cout<<"node is not present !"<<endl;
    }
    return 0;
}