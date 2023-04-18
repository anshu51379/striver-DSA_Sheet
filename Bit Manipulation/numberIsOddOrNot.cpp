// https://practice.geeksforgeeks.org/problems/odd-or-even3618/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Odd+or+Even

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string oddEven(int N){
        // code here 
        if(1&N){
            return "odd";
        }
        return "even";
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
