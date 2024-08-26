# include <iostream>
# include <vector>

using namespace std ;

vector<int> merge(vector<int>v1,int n, vector<int>v2,int m, vector<int> v3){
    int i =0,j= 0;
    int k =0;
    while(i<n && j<m){
        if(v1[i] <v2[j]){                                                // checking condition if element of v1>v2
            v3[k++] = v1[i++];                              
           
        } else{
            v3[k++] = v2[j++];
            
        }

    }
    while(i<n){                                                       // codition if v1>v2
        v3[k++] = v1[i++];                                             // jo v1 me bache h vo copy kr diye
        
    }
    while(j<m){                                                        //condition if v2>v1
        v3[k++] = v2[j++];                                             // jo v2 me bache h vo copy kr diye
       
    }
    return v3;
}

void print(vector<int> v,int n ){                                                           // function to print array
    for(int i =0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
    vector <int> v1;
     
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(9);

    

    cout<<"vector 1 is:"<<endl;
    print(v1,5);

    vector <int> v2;

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    cout<<"vector 2 is:"<<endl;
    print(v2,3);                                                                         // calling to printing function

    
    vector<int>v3(8,0);
    vector<int >ans = merge( v1,5,v2,3,v3);                                          // calling to merge function
    cout<<"After merge vector 3 is:"<<endl;
    print(ans,8);                                       
}