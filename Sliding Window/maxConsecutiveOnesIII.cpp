// https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-consecutive-ones

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int i=0, j=0, cnt=0, res=0;
        while(j<n){
            if(!nums[j]){
                cnt+=1;
            }
            while(cnt>k){
                if(!nums[i]){
                    cnt-=1;
                }
                i+=1;
            }
            res=max(res, j-i+1);
            j+=1;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0, high=0, cnt=0, res=0;
        while(high<nums.size()){
            if(!nums[high]){
                cnt+=1;
            }
            while(cnt>k){
                if(!nums[low]){
                    cnt-=1;
                }
                low+=1;
            }
            res=max(res, high-low+1);
            high+=1;
        }
        return res;
    }
};
