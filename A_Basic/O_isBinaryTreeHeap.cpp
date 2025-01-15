# include <iostream>
# include <climits>
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

class info{
    public:
       int maxi;
       int mini;
       bool isBST;
       int size;
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

node* buildTree(node* root){
    cout <<"Enter data : "<<endl;
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

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1+ countNodes(root -> left)+countNodes(root -> right);
    return ans;
}

bool isCBT(node* root,int index,int cnt){
    if(root == NULL){
        return true;
    }
    if(index >= cnt){
        return false;
    } else {
        bool left = isCBT(root -> left,2*index+1,cnt);
        bool right = isCBT(root -> right,2*index+2,cnt);
        return(left && right);
    }
}

bool isMaxOrder(node* root){
    // leaf node
    if(root -> left == NULL && root -> right == NULL){
        return true;
    }
    if(root  -> right == NULL){
        return (root -> data > root -> left -> data);
    } else {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        return (left && right && (root -> data >root -> left -> data && root -> data > root -> right -> data));
    }
}

bool isHeap(node* root){
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    } else{
        return false;
    }

}

int main(){

    node* root = NULL;

    root = buildTree(root); 

    cout <<"printing the binary tree : "<<endl;
    levelOrderTraversal(root);

    if(isHeap(root)){
        cout<<"Given tree is Heap "<<endl;
    } else {
        cout<<"Given tree is not Heap "<<endl;
    }

    return 0;
}