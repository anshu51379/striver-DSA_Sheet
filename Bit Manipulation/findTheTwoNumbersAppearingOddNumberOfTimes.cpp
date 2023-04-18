// https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Two-numbers-with-odd-occurrences

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int> ans;
        long long int val=0, tmp=0, res=0, cnt=0;
        for(long long int i=0; i<N; i+=1){
            res^=Arr[i];
        }
        while(!(res&(1<<cnt))){
            cnt+=1;
        }
        tmp|=1<<cnt;
        for(long long int i=0; i<N; i+=1){
            if(Arr[i]&tmp){
                val=val^res^Arr[i];
            }
        }
        ans.push_back(max(val,res^val));
        ans.push_back(min(val,res^val));
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
