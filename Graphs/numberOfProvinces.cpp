// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int node, int n, vector<int> &visited){
        visited[node]=true;
        for(int i=0; i<n; i+=1){
            if(adj[node][i]){
                if(!visited[i]){
                    dfs(adj, i, n, visited);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=0;
        vector<int> visited(V);
        for(int i=0; i<V; i+=1){
            if(!visited[i]){
                cnt+=1;
                dfs(adj, i, V, visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/number-of-provinces/#:~:text=A%20province%20is%20a%20group,the%20total%20number%20of%20provinces.

class Solution {
public:
    void helper(int node, vector<vector<int>> &isConnected, vector<int> &vis){
        vis[node]=1;
        for(int i=0; i<isConnected.size(); i+=1){
            if(isConnected[node][i] and !vis[i]){
                helper(i, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int n=isConnected.size();
        vector<int> vis(n);
        for(int i=0; i<n; i+=1){
            if(!vis[i]){
                cnt+=1;
                helper(i, isConnected, vis);
            }
        }
        return cnt;
    }
};
