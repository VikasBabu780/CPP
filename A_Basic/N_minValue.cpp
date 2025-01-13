// finding minimum and maximum value in BST
// deletion from BST also

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

node* minVal(node* root){
    node* temp = root;

    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

node* maxVal(node* root){
    node* temp = root;

    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

// deletion fron BST
node* deleteFromBST(node* root,int val){
    // base case
    if(root == NULL){
        return root;
    }
    if(root -> data == val){
        // 0 child
        if(root -> left == NULL && root -> right == NULL ){
            delete root;
            return NULL;
        }

        // 1 child
        // (i) left child
        if(root -> left != NULL && root -> right == NULL){
            node* temp = root -> left;
            delete root;
            return temp;
        }
        // (ii) right child
        if(root -> left == NULL && root -> right != NULL){
            node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right ,mini);
            return root;
        }
    } else if(root -> data > val){
        // left part
        root -> left = deleteFromBST(root -> left,val);
        return root;
    } else {
        //right part
        root -> right = deleteFromBST(root -> right,val);
        return root;
    }
}

int main(){
    node* root = NULL;

    cout <<"Enter data to create BST :" <<endl;
    takeInput(root); 

    cout <<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<"min value in BST is: "<<minVal(root)-> data<<endl;
    cout<<"max val in BST is : "<<maxVal(root) -> data<<endl;

    int val;
    cout<<"enter the value to be deleted from BST : "<<endl;
    cin>>val;

    root = deleteFromBST(root,val);

    cout <<"printing the BST after deletion : "<<endl;
    levelOrderTraversal(root);

    return 0;
}
