// https://practice.geeksforgeeks.org/problems/assign-cookies/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=assign-cookies

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(sz.begin(), sz.end());
        sort(greed.begin(), greed.end());
        int i=N-1, j=M-1, cnt=0;
        while(i>=0 and j>=0){
            if(sz[j]>=greed[i]){
                cnt+=1;
                j-=1;
            }
            i-=1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=g.size()-1, j=s.size()-1, cnt=0;
        while(i>=0 and j>=0){
            if(s[j]>=g[i]){
                cnt+=1;
                j-=1;
            }
            i-=1;
        }
        return cnt;
    }
};
