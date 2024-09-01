# include <iostream>
using namespace std;

int main(){
    int arr[10] = {2,4,63,3,9,5};
    cout<<"adress of first memeory block is : "<<arr<<endl;    //will give adress of first memory block

    cout<<"adress of first memeory block is : "<<&arr[0]<<endl;           // will give memory adress of first memory block

    cout<<" 4th " <<*arr<<endl;                                 // value at first location
    cout<<" 5th " <<*arr+1<<endl;    
    cout<<" 6th " <<*(arr+1)<<endl;

    int i = 3;
    cout<< i[arr] <<endl;   


    
}
