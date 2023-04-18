// https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Division+without+using+multiplication,+division+and+mod+operator

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        int sign=1;
        long long quotient=0;
        if(dividend<0 ^ divisor<0){
            sign=-1;
        }
        divisor=abs(divisor);
        dividend=abs(dividend);
        while(dividend-divisor>=0){
            int cnt=0;
            while(dividend-(divisor<<1<<cnt)>=0){
                cnt+=1;
            }
            quotient+=1<<cnt;
            dividend-=divisor<<cnt;
        }
        return quotient*sign;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends



// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1){
            return INT_MAX;
        }
        long long m=labs(dividend), n=labs(divisor), res=0;
        int sign=((dividend < 0) ^ (divisor < 0))?-1:1;
        if(n==1){
            if(sign==1){
                return m;
            }else{
                return -m;
            }
        }
        while(m>=n){
            long long tmp=n, cnt=1;
            while(m>=(tmp<<1)){
                tmp<<=1;
                cnt<<=1;
            }
            res+=cnt;
            m-=tmp;
        }
        if(sign==1){
            return res;
        }else{
            return -res;
        }
    }
};
