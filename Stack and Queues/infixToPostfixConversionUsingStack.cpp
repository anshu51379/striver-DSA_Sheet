// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int helper(char a){
        if(a=='('){
            return 0;
        }
        if(a=='+' or a=='-'){
            return 1;
        }
        if(a=='*' or a=='/'){
            return 2;
        }
        if(a=='^'){
            return 3;
        }
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<int> tmp;
        string res="";
        for(auto x:s){
            if(isalpha(x)){
                res+=x;
            }else if(x=='('){
                tmp.push(x);
            }else{
                if(x==')'){
                    while(tmp.top()!='('){
                        res+=tmp.top();
                        tmp.pop();
                    }
                    tmp.pop();
                }else if(tmp.empty() or helper(x)>helper(tmp.top())){
                    tmp.push(x);
                }else{
                    while(!tmp.empty() and helper(x)<=helper(tmp.top())){
                        res+=tmp.top();
                        tmp.pop();
                    }
                    tmp.push(x);
                }
            }
        }
        while(!tmp.empty()){
            res+=tmp.top();
            tmp.pop();
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
