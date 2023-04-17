// https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    if(n==1){
	        return 2;
	    }
	    int zeros=1, ones=1;
	    int sum=zeros+ones;
	    for(int i=2; i<=n; i+=1){
	        ones=zeros%(1000000007);
	        zeros=sum%(1000000007);
	        sum=(zeros+ones)%(1000000007);
	    }
	    return sum%(1000000007);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
