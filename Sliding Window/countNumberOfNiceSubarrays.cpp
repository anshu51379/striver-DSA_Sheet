// https://practice.geeksforgeeks.org/problems/count-subarray-with-k-odds/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-subarray-with-k-odds

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        for(int i=0; i<n; i+=1){
            if(nums[i]&1){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
        int i=0, cnt=0, sum=0;
        unordered_map<int, int> tmp;
        for(int i=0; i<n; i+=1){
            sum+=nums[i];
            if(tmp.find(sum-k)!=tmp.end()){
                cnt+=tmp[sum-k];
            }
            if(sum==k){
                cnt+=1;
            }
            tmp[sum]+=1;
        }
        return cnt;
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
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0, sum=0;
        unordered_map<int, int> tmp;
        for(int i=0; i<nums.size(); i+=1){
            if(nums[i]&1){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }
        for(int i=0; i<nums.size(); i+=1){
            sum+=nums[i];
            if(sum==k){
                cnt+=1;
            }
            if(tmp.find(sum-k)!=tmp.end()){
                cnt+=tmp[sum-k];
            }
            tmp[sum]+=1;
        }
        return cnt;
    }
};
