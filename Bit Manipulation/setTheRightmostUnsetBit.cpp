// https://practice.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Set+the+rightmost+unset+bit

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        if(!(N&(N+1))){
            return N;
        }
        return (N|(N+1));
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
