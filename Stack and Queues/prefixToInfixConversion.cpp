// https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> tmp;
        for(int i=pre_exp.size()-1; i>=0; i-=1){
            char x=pre_exp[i];
            if(x=='+' or x=='-' or x=='*' or x=='/'){
                string s1=tmp.top();
                tmp.pop();
                string s2=tmp.top();
                tmp.pop();
                string st="("+s1+x+s2+")";
                tmp.push(st);
            }else{
                tmp.push(string(1,x));
            }
        }
        return tmp.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
