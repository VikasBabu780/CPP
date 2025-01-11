# include <iostream> 
# include <queue>
using namespace std;

class  node {
    public:
    int data;
    node *left;
    node *right;

    node (int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

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

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout <<" enter data for root : "<<endl;
    int data;
    cin>>data; 
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout <<"enter left node for : " <<temp -> data <<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp -> left);
        }

        cout <<"enter right node for : " <<temp -> data <<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp -> right);
        }
    }

}

int main (){

    node* root = NULL;

    // creating tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //lebel order
    cout <<" printing the level order traversal :"<<endl;
    levelOrderTraversal(root);

    cout <<"inorder traversal is : ";
    inOrderTraversal(root);

    cout <<endl;
    cout <<"preorder traversal is : ";
    preOrderTraversal(root);

    cout <<endl;
    cout <<"post order traversal is : ";
    postOrderTraversal(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;

}