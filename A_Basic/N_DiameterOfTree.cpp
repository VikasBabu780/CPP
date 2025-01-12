// longest path between any two end nodes

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

int diameter(node* root){
    // base case
    if(root == NULL){
        return 0;
    }

    int option1 = diameter(root -> left);
    int option2 = diameter(root -> right);
    int option3 = height(root -> left) + height(root -> right)+1;

    int ans = max(option1,max(option2,option3));
    return ans;
};

int main(){
    node* root = NULL;

    root =  buildTree(root);

    levelOrderTraversal(root);

    cout<<"diameter is : "<<diameter(root)<<endl;

    return 0;

}