// https://practice.geeksforgeeks.org/problems/queue-using-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=queue-using-stack#

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int dequeue() {
        int res=input.top();
        input.pop();
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends



// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int tmp=s2.top();
            s2.pop();
            return tmp;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int tmp=s2.top();
            s2.pop();
            return tmp;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return (s1.empty() and s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
