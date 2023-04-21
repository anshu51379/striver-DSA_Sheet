// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=get-minimum-element-from-stack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<long long> s;
    long long minEle=INT_MIN;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           //Write your code here
           if(s.empty()){
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           //Write your code here
           if(s.empty()){
               return -1;
           }
           long long tmp=s.top();
           s.pop();
           long long mini=minEle;
           if(tmp<minEle){
               minEle=2*minEle-tmp;
               return mini;
           }else{
               return tmp;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           //Write your code here
           long long num=x;
           if(s.empty()){
               minEle=num;
               s.push(num);
            }else{
                if(num<minEle){
                    s.push(2*num*1LL-minEle);
                    minEle=num;
                }else{
                    s.push(num);
                }
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends



// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<long long> st;
    long long minVal=INT_MIN;
    
    MinStack() {}
    
    void push(int val) {
        long long num=val;
        if(st.empty()){
            minVal=num;
            st.push(num);
        }else{
            if(num<minVal){
                st.push(2*num*1LL-minVal);
                minVal=num;
            }else{
                st.push(num);
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long tmp=st.top();
        st.pop();
        if(tmp<minVal){
            minVal=2*minVal-tmp;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long tmp=st.top();
        if(tmp<minVal){
            return minVal;
        }
        return tmp;
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
