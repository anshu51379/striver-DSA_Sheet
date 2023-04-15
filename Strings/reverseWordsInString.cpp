// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-words-in-a-given-string

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int low=0, high=0;
        reverse(S.begin(), S.end());
        while(high<S.size()){
            if(S[high]=='.'){
                reverse(S.begin()+low, S.begin()+high);
                low=high+1;
            }
            high+=1;
        }
        reverse(S.begin()+low, S.end());
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
