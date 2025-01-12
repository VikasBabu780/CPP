// height of left subtree - height of right subtree <= 1

# include <iostream>
# include <queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right =  NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the value of data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of  "<<data  <<endl;
    root ->  left =  buildTree(root -> left);
    cout <<"Enter data for inserting in right of "<< data <<endl;
    root -> right = buildTree(root -> right);
    return root;

}

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

int height(node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left,right)+1;
    return ans;
}

bool isBalanced(node* root){
    // base case
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);

    bool diff =  height(root -> left) - height(root -> right) <= 1;

    if(left && right &&diff){
        return true;
    } else {
        return false;
    }
}

bool isIdentical(node* r1,node* r2){
    // base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = isIdentical(r1 -> left ,r2 -> left);
    bool right = isIdentical(r1 -> right ,r2 -> right);

    bool value = r1 -> data == r2 -> data;

    if(left && right && value){
        return true;
    } else {
        return false;
    }
}

int main (){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    cout<<endl;
    if(isBalanced(root)){
        cout<<"Tree is balanced !"<<endl;

    } else {
        cout<<"Tree is not balanced ! "<<endl;
    }

    return 0;

}