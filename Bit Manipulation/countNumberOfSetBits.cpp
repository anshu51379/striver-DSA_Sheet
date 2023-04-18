// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Count+total+set+bits

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int i=1, ans=0;
        while(i<=n){
            int cnt=(n+1)/i;
            ans+=(cnt/2)*i;
            int tmp=(n+1)-(i*cnt);
            if(cnt%2){
                ans+=tmp;
            }
            i*=2;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
