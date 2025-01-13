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

void inOrderTraversal(node* root){
    //basse case
    if(root == NULL){
        return;
    }
    inOrderTraversal(root -> left);
    cout <<root ->data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(node* root){
    // basde case
    if(root == NULL){
        return;
    }
    cout <<root -> data <<" ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node* root){
    // baase case
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout <<root -> data <<" ";
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

int main(){
    node* root = NULL;
    cout <<"Enter data to create BST :" <<endl;
    takeInput(root); 

    cout <<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<"printing Inorder : "<<endl;
    inOrderTraversal(root);

    cout<<endl<<"printing preorder : "<<endl;
    preOrderTraversal(root);

    cout<<endl<<"printing postorder : "<<endl;
    postOrderTraversal(root);

    return 0;
}