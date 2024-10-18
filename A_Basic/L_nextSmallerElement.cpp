# include <iostream>
# include <stack>
# include <vector>
using namespace std;

vector<int> nextSmallerElement(vector <int> &arr,int n){
    stack <int> st;
    st.push(-1);
    vector <int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];

        while(st.top() >= arr[i]){
            st.pop();
        }

        // ans is stack ka top
        ans [i] = st.top();
        st.push(curr);

    }
    return ans;

}

void print(vector<int> v ){                                                           // function to print array
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

    cout<<"original array is : "<<endl;
    print(v);

    vector <int> ans = nextSmallerElement(v,n);
    cout<<"next smaller elements are :"<<endl;
    print(ans);

}