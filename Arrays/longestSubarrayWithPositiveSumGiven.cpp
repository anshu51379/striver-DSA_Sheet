// https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int low=0, high=0, dMax=0;
    long long sum=a[0];
    while(high<a.size()){
        while(sum>k and low<=high){
            sum-=a[low];
            low+=1;
        }
        if(sum==k){
            dMax=max(dMax, high-low+1);
        }
        high+=1;
        if(high<a.size()){
            sum+=a[high];
        }
    }
    return dMax;
}
