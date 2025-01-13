// construct tree from inorder and preorder
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

int findPosition(int in[],int element,int n){
    for(int i =0; i<n; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

node* solve(int in[],int pre[], int &index,int inOrderStart,int inOrderEnd,int n){
    //base case
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);
    int position = findPosition(in,element,n);

    // recursive call
    root -> left = solve(in,pre,index,inOrderStart,position-1,n);
    root -> right = solve(in,pre,index,position+1,inOrderEnd,n);

    return root;

}

node* buildTree(int in[] ,int pre[],int n){
    int preOrderIndex = 0;
    node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
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

int main(){
    node* root = NULL;

    int in[] ={3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};

    root = buildTree(in,pre,6);

    levelOrderTraversal(root);
    
    return 0;

}