#include<iostream>
using namespace std;

int main(){
    int n ;
    cout<<"enter the amount for which notes to be calcutate:";
    cin>>n;

    int notes;
    int rs;
    cout<<"enter the note value:";
    cin>>rs;

    switch(rs){
        case 100 : notes = n/100;
        n = n%100;
        cout<<"100 rs notes are:"<<notes<<endl;
        
        
        case 50 : notes = n/50;
        n = n%50;
        cout<<"50 rs notes are:"<<notes<<endl;
        

        case 20 :notes = n/20;
        n = n%20;
        cout<<"20 rs notes are:"<<notes<<endl;
        

        case 1 : notes = n/1;
        n = n%1;
        cout<<"1 rs notes are:"<<notes<<endl;
        
        
        
    }
}