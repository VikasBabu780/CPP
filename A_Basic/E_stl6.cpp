// implementation on stack

# include<iostream>
# include<stack>

using namespace std;

int main(){
    stack<string> s;                                              // creating stack

    s.push(" love");                                              //inserting elements
    s.push("babbar");
    s.push("kumar");

    cout<<"top element -> "<<s.top()<<endl;                      // printing top element

    s.pop();                                                    // deleting top element
    cout<<"top element is : "<<s.top()<<endl;

    cout<<"size of satck -> "<<s.size()<<endl;                   // printing size of stack

    cout<<"emoty or not : "<<s.empty()<<endl;                    // checking empty or not
}