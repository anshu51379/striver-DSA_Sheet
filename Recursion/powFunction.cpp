// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=power-of-numbers

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       long long res, ans;
       if(R==0){
           return 1;
       }
       if(R==1){
           return N;
       }
       res=power(N, R/2);
       ans=(res*res)%mod;
       if(R%2){
           return (ans*N)%mod;
       }
       return ans;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends



// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        long long tmp=n;
        double res=1.0;
        if(tmp<0){
           tmp=-1*tmp;
        }
        while(tmp){
            if(tmp&1){
               res=res*x;
               tmp-=1;
            }else{
               x=x*x;
               tmp/=2;
            }
        }
        if(n<0){
           res=(double)(1.0)/res;
        }
        return res;
    }
};
