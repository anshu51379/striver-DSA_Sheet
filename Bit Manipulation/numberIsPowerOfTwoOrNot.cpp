// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Power+of+2

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        // Your code here   
        if(!n){
            return false;
        }
        if(floor(log2(n))==ceil(log2(n))){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends



// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n){
            return false;
        }
        while((n>1)and(!(n&1))){
            n=n>>1;
        }
        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};
