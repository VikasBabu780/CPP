# include <iostream>
# include <vector>

using namespace std;

vector<int> mooveZero(vector<int > v){
    int nonZero = 0;
    for(int j =0; j<v.size(); j++){
        if(v[j] != 0){
            swap(v[j] ,v[nonZero]);
            nonZero++;
        }
    }
    return v;
}

void print(vector<int> v ){                                                           // function to print array
    for(int i =0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
    vector <int> v;

    v.push_back(12);
    v.push_back(0);
    v.push_back(0);
    v.push_back(9);
    v.push_back(4);
    v.push_back(0);
    v.push_back(1);

    cout<<"array before move:"<<endl;
    print(v);

    vector<int>ans = mooveZero(v);
    cout<<"array after move : "<<endl;
    print(ans);

}