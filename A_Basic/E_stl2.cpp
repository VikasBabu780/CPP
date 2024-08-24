// implementation on queue

# include <iostream>
# include <queue>

using namespace std;

int main(){
    queue<string> q;                                          // creation of queue
    q.push("love");
    q.push("babbar");                                             // adding elements to queue
    q.push("kumar");

    cout<<"first element "<<q.front()<<endl;                        // printing front element of queue
    q.pop();                                                    // removing first element of queue
    cout<<"first element "<<q.front()<<endl;

    cout<<"size after pop "<<q.size()<<endl;                       // printing size of queue
}
