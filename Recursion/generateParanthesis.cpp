// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-all-possible-parentheses

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void helper(vector<string> &ans, int open, int close, string tmp){
        if(open>close){
            return;
        }
        if(!open and !close){
            ans.push_back(tmp);
        }else{
            if(open>0){
                helper(ans, open-1, close, tmp+'(');
            }
            if(close>0){
                helper(ans, open, close-1, tmp+')');
            }
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends



// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void helper(vector<string> &ans, int open, int close, string tmp){
        if(open>close){
            return;
        }
        if(!open and !close){
            ans.push_back(tmp);
        }else{
            if(open>0){
                helper(ans, open-1, close, tmp+'(');
            }
            if(close>0){
                helper(ans, open, close-1, tmp+')');
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }
};
