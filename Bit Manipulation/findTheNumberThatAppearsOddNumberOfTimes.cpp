// https://practice.geeksforgeeks.org/problems/find-the-odd-occurence4820/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Power-SetExceptionally-odd

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
        unordered_map<int, int> m;
        for(int i=0; i<n; i+=1){
            m[arr[i]]+=1;
        }
        for(auto x:m){
            if(x.second&1){
                return x.first;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends



// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> tmp;
        for(int i=0; i<nums.size(); i+=1){
            tmp[nums[i]]+=1;
        }
        for(int i=0; i<nums.size(); i+=1){
            if(tmp[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};
