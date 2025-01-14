// largest BST in binary tree
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

info solve(node* root,int &ans){
    // base case
    if(root == NULL){
        return{INT_MIN ,INT_MAX,true,0};
    }

    info left = solve(root -> left,ans);
    info right = solve(root -> right ,ans);

    info currNode;

    currNode.size = left.size +right.size +1;
    currNode.maxi = max(root -> data ,right.maxi);
    currNode.mini = min(root -> data,left.mini);

    if(left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini)){
        currNode.isBST = true;
    }else {
        currNode.isBST = false;
    }

    // answer update
    if(currNode.isBST){
        ans = max(ans,currNode.size);

    }
    return currNode;
}

int largestBST(node* root){
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}

int main(){

    node* root = NULL;

    root = buildTree(root); 

    cout <<"printing the binary tree : "<<endl;
    levelOrderTraversal(root);

    int ans = largestBST(root);
    cout<<"largest BST inside root is : "<<ans<<endl;

    return 0;
}