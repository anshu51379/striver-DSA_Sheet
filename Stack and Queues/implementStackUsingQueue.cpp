// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stack-using-two-queues

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code   
        if(q1.empty()){
            return -1;
        }
        int res=q1.front();
        q1.pop();
        return res;
}



// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q;
    
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i+=1){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res=q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(!q.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
