# include <iostream>
# include <vector>

using namespace std;

bool check(vector<int>v,int n){
    int count = 0;
    for(int i =1 ; i<n; i++){
        if(v[i-1] > v[i]){                                        // comparing elements
            count++;
            break;
        }
        else if(v[n-1] > v[0]){                                   // comparing last element to first element
        count++;
        } else{
            return 0;
        }
    }
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

    
    if(check(v,n) > 0){                                      // checking coditions
        cout<<"False" <<endl;
    } else{
        cout<<"True"<<endl;
    }
}