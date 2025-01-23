// All houses are in cicular order and in no two adjacent house rowery can be done
// time complexity O(n) ,space complexity O(n)

# include<iostream>
# include<vector>
using namespace std;

long long int solve(vector<int> &valueInHouse){
   int n = valueInHouse.size();

   int prev2 = 0;
   int prev1 = valueInHouse[0];

   for(int i =1; i<n; i++){
    int incl = prev2+ valueInHouse[i];
    int excl = prev1 + 0;
    int ans = max(incl,excl);
    prev2 = prev1;
    prev1 = ans;
   }
   return prev1;
}

long long int houseRobber(vector <int> &valueInHouse){
    int n = valueInHouse.size();

    if(n == 1){
        return valueInHouse[0];
    }

    vector<int> first,second;
    for(int i =0; i<n; i++){
        if(i != n-1){
           first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }
    return max(solve(first),solve(second));
}

int main(){
    int n;
    cout<<"Enter the number of houses : ";
    cin>>n;

    vector <int> v(n);

    cout<<"Enter the money present in houses : ";
    for(int i =0; i<n; i++){
        cin>>(v[i]);
    }

    long long int ans = houseRobber(v);
    cout<<"Maximum amount stolen by theif is "<<ans;

    return 0;
}