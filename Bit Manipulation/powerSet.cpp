// https://practice.geeksforgeeks.org/problems/power-set4302/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    for(int i=1; i<(1<<s.size()); i+=1){
		        string tmp="";
		        for(int j=0; j<s.size(); j+=1){
		            if(i&(1<<j)){
		                tmp+=s[j];
		            }
		        }
		        ans.push_back(tmp);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1);
        for(int i=0; i<nums.size(); i+=1){
            int n=ans.size();
            for(int j=0; j<n; j+=1){
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};
