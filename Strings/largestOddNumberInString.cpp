// https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-odd-number-in-string

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int i=s.size()-1;
        while(i>=0){
            if(s[i]%2==1){
                return s.substr(0, i+1);
            }
            i-=1;
        }
        return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends
