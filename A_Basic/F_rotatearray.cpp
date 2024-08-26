# include <iostream>
# include <vector>

using namespace std;

void rotate(vector<int>&nums,int k){
    vector<int> temp(nums.size());
    for(int i =0; i<nums.size(); i++){
        temp[(i+k)%nums.size()] = nums[i];                  //here cocept of (num%n)remainder comes b/w 0 to n-1 is used
    }

    nums = temp;                                           // copy temp into nums vector
}

void print(vector<int>v){
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
    int n;
    cout<<"enter the value of n :";
    cin>>n;

    vector<int>v(n);

    cout<<"enter "<<n<<" elements"<<endl;

    for(int i =0; i<n; i++){
        cin>>v[i];
    }cout<<endl;
    
 
    cout<<"vector before rotation :"<<endl;
    print(v);

    int k;
    cout<<"enter the value of k : " <<endl;
    cin>>k;
    
    rotate(v,k);
    cout<<"vector after rotation : "<<endl;
    print(v);
    
    
}