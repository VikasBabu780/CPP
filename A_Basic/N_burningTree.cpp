// minimum time to burn a tree

# include <iostream>
# include<queue>
# include<map>
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

node* buildTree(node* root){
    cout<<"enter the value of data :"<<endl;
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

// create mapping
//return target node

node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent){
    node* res = NULL;

    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front -> data == target){
            res = front;
        }

        if(front -> left){
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }

        if(front -> right){
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    
    }
    return res;
}

int burnTree(node* root,map<node*,node*> &nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = true;

    int ans =  0;

    while(!q.empty()){

        bool flag = 0;
        int size = q.size();
        for(int i =0; i<size; i++){
            // process karna hai neighbouring node ko
            node* front = q.front();
            q.pop();

            if(front -> left && !visited[front -> left]){
                flag = true;
                q.push(front -> left);
                visited[front -> left] = true;
            }

            if(front -> right && !visited[front -> right]){
                flag = true;
                q.push(front -> right);
                visited[front -> right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == true){
            ans++;
        }
    }
    return ans;

}

int minTime(node* root,int target){
    int ans =0;
    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root,target,nodeToParent);

    ans = burnTree(targetNode,nodeToParent);

    return ans;
}
int main(){
    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    int time = minTime(root,8);
    cout<<"time to burn complete tree is :"<<time<<endl;

    return 0;

}