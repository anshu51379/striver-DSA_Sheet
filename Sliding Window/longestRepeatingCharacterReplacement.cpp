// https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-repeating-character-replacement

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int low=0, high=0, res=0;
        unordered_map<char, int> m;
        int tmp=INT_MIN;
        while(high<S.size()){
            m[S[high]]+=1;
            tmp=max(tmp, m[S[high]]);
            if(high-low+1-tmp>K){
                m[S[low]]-=1;
                low+=1;
            }
            res=max(res, high-low+1);
            high+=1;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int left=0, right=0, cnt=INT_MIN, ans=0;
        while(right<s.size()){
            m[s[right]]+=1;
            cnt=max(cnt, m[s[right]]);
            if(right-left+1-cnt>k){
                m[s[left]]-=1;
                left+=1;
            }
            ans=max(ans, right-left+1);
            right+=1;
        }
        return ans;
    }
};
