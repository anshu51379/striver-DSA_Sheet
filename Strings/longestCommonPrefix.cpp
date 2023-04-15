// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-common-prefix-in-an-array

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string final="";
        bool flag=true;
        for(int i=0; i<arr[0].size(); i+=1){
            char tmp=arr[0][i];
            for(int j=1; j<N; j+=1){
                if(tmp!=arr[j][i] or arr[j].size()<=i){
                    flag=false;
                    break;
                }
            }
            if(flag){
                final+=tmp;
            }else{
                break;
            }
        }
        if(final==""){
            return "-1";
        }else{
            return final;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
// } Driver Code Ends
