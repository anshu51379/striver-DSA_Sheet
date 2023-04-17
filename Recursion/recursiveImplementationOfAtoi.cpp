// https://practice.geeksforgeeks.org/problems/implement-atoi/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-atoi

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0, sign=1, i=0;
        if(str[i]=='-'){
            sign=-1;
            i+=1;
        }
        while(str[i]){
            int tmp=str[i]-'0';
            if(tmp>=0 and tmp<=9){
                ans=(ans*10)+tmp;
            }else{
                return -1;
            }
            i+=1;
        }
        return ans*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends



// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i=0, res=0, sign=1;
        while(i<s.size() and s[i]==' '){
            i+=1;
        }
        if(i<s.size() and s[i]=='-'){
            sign=-1;
            i+=1;
        }else if(i<s.size() and s[i]=='+'){
            sign=1;
            i+=1;
        }
        while(i<s.size() and 0<=(int)s[i]-'0' and (int)s[i]-'0'<=9){
            if((res>INT_MAX/10) or (res==INT_MAX/10 and (int)(s[i]-'0')>INT_MAX%10)){
                return res=(sign==1?INT_MAX:INT_MIN);
            }
            res*=10;
            res+=((int)s[i]-'0');
            i+=1;
        }
        return res*sign;
    }
};
