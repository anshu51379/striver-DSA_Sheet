// https://practice.geeksforgeeks.org/problems/binary-subarray-with-sum/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-subarray-with-sum

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        int i=0, cnt=0, sum=0;
        unordered_map<int, int> tmp;
        while(i<N){
            sum+=arr[i];
            if(tmp.find(sum-target)!=tmp.end()){
                cnt+=tmp[sum-target];
            }
            if(sum==target){
                cnt+=1;
            }
            tmp[sum]+=1;
            i+=1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> tmp;
        int cnt=0, sum=0;
        for(int i=0; i<nums.size(); i+=1){
            sum+=nums[i];
            if(tmp.find(sum-goal)!=tmp.end()){
                cnt+=tmp[sum-goal];
            }
            if(sum==goal){
                cnt+=1;
            }
            tmp[sum]+=1;
        }
        return cnt;
    }
};
