// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod=1e9+7;
	int dfs(int i, int t, int arr[], vector<vector<int>> &dp){
	    if(!i){
	        if(!t and !arr[0]){
	            return 2;
	        }
	        if(!t){
	            return 1;
	        }
	        return arr[0]==t;
	    }
	    if(dp[i][t]!=-1){
	        return dp[i][t];
	    }
	    int nPck=dfs(i-1, t, arr, dp);
	    int pck;
	    if(arr[i]<=t){
	        pck=dfs(i-1, t-arr[i], arr, dp);
	    }else{
	        pck=0;
	    }
	    return dp[i][t]=(pck+nPck)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return dfs(n-1, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
