// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Bit-Difference

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int tmp=a^b, cnt=0;
        while(tmp>0){
            if(tmp&1){
                cnt+=1;
            }
            tmp>>=1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int tmp=start^goal;
        while(tmp>0){
            if(tmp&1){
                cnt+=1;
            }
            tmp>>=1;
        }
        return cnt;
    }
};
