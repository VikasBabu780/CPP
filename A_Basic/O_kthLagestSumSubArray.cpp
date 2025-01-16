# include <iostream>
# include<queue>
# include<algorithm>
using namespace std;

// space complexity O(n^2)
int getKthLargest(vector<int> &arr,int k){
    vector <int> sumStore;
    int n = arr.size();

    for(int i = 0; i<n; i++){
        int sum = 0;

        for(int j = i; j<n; j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];
}

// space complexity O(k)
int getKthlargest(vector<int> &arr,int k){

    priority_queue<int,vector<int>,greater<int>> mini;

    int n = arr.size();
    for(int i = 0; i< n; i++){
        int sum = 0; 
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(mini.size() <k){
                mini.push(sum);
            } else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main (){
    
    vector <int> arr;
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);

   int k ;
   cout<<"enter the value of  k :"<<endl;
   cin>>k;

   int ans = getKthlargest(arr,k);
   cout <<"answer is : "<<ans <<endl;

    return 0;
}