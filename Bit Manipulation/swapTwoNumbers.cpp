// https://practice.geeksforgeeks.org/problems/swap-two-numbers3844/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Swap+two+numbers

//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        pair<int, int> ans;
        ans.first=b;
        ans.second=a;
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        
        Solution ob;
        pair<int, int>p = ob.get(a, b);
        cout << p.first << ' ' << p.second << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends
