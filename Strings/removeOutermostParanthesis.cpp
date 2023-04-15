// https://practice.geeksforgeeks.org/problems/outermost-parentheses/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans="";
        int i=0, cnt=0;
        while(i<s.size()){
            if(s[i]=='('){
                if(cnt){
                    ans+='(';
                }
                cnt+=1;
            }else{
                cnt-=1;
                if(cnt){
                    ans+=')';
                }
            }
            i+=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends
