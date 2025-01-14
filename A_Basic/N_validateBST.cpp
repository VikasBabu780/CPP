// check wheather given BST ids valid or not
# include <iostream>
# include <queue>
# include <climits>
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

bool isBST(node* root ,int min,int max){
    // base case
    if(root == NULL){
        return true;
    }
    if(root -> data >=min && root -> data <= max){
        bool left = isBST(root -> left ,min,root -> data);
        bool right = isBST(root -> right ,root -> data , max);
        return left && right;
    } else {
        return false;
    }

}

bool isBst(node* root){
    return isBST(root,INT_MIN,INT_MAX);
}

int main(){
    node* root = NULL;

    cout <<"Enter data to create BST :" <<endl;
    takeInput(root); 

    cout <<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    if(isBst(root)){
        cout<<"given tree is BST !"<<endl;

    } else{
        cout<<"given tree is not BST !"<<endl;
    }


    return 0;
}