// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=parenthesis-checker

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<int> s; bool ans=false;
        for(int i=0; i<x.size(); i+=1){
            if(x[i]=='(' or x[i]=='{' or x[i]=='['){
                s.push(x[i]);
            }else{
                if(s.empty()){
                    return false;
                }
                char tmp=s.top();
                s.pop();
                if((x[i]==')' and tmp=='(')or(x[i]=='}' and tmp=='{')or(x[i]==']' and tmp=='[')){
                    ans=true;
                }else{
                    return false;
                }
            }
        }
        return s.empty()&&ans;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends



// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<int> st; bool ans=false;
        for(int i=0; i<s.size(); i+=1){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char tmp=st.top();
                st.pop();
                if((s[i]==')' and tmp=='(')or(s[i]=='}' and tmp=='{')or(s[i]==']' and tmp=='[')){
                    ans=true;
                }else{
                    return false;
                }
            }
        }
        return st.empty()&&ans;
    }
};
