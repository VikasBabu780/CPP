// left to right and right to  left in level order traversal

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

vector <int> zigZagTraversal(node* root){
    vector <int> result;
    if(root == NULL){
        return result;
    }
    queue <node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        //level process
        for(int i =0; i<size; i++){
            node* frontNode = q.front();
            q.pop();
            
            // normal insert or reverse insert
            int index = leftToRight ? i : size -i-1;
            ans[index] = frontNode -> data;

            if(frontNode -> left){
                q.push(frontNode -> left);
            }

            if(frontNode -> right){
                q.push(frontNode -> right);
            }
        }
        // direction change krni hai
        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

void print(vector<int> &v){
    for(int i =0; i< v.size(); i++){
        cout <<v[i]<<" ";
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    
    levelOrderTraversal(root);

    vector <int> ans ;
    ans = zigZagTraversal(root);

    cout<<"zigzag traversal is : "<<endl;
    print(ans);

    return 0;

}