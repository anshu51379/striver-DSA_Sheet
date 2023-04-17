// https://practice.geeksforgeeks.org/problems/good-numbers4629/1#

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int helper(int a, int b){
        int digit=a%10;
        int sum=digit;
        if(digit==b){
            return 0;
        }
        a/=10;
        while(a){
            digit=a%10;
            if(digit==b or digit<=sum){
                return 0;
            }else{
                sum+=digit;
                a/=10;
            }
        }
        return 1;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> ans;
        int i=L;
        while(i<=R){
            if(helper(i, D)){
                ans.push_back(i);
            }
            i+=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends



// https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    long long power(long long x, long long y){
        long long res=1;
        int mod=1000000007;
        while(y>0){
            if(y&1){
                res=(res%mod*x%mod)%mod;
            }
            x=(x%mod*x%mod)%mod;
            y=y>>1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long ans=power(20, n/2);
        if(n%2){
            ans=(ans*5)%1000000007;
        }
        return ans;
    }
};
