// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=length-of-the-longest-substring

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int low=0, high=0;
        vector<int> tmp(256, -1);
        int longest=0;
        while(S[high]!=NULL){
            char nextEle=S[high];
            if(tmp[nextEle]<low){
                high+=1;
            }else{
                int curr=high-low;
                if(curr>longest){
                    longest=curr;
                }
                low=tmp[nextEle]+1;
                high+=1;
            }
            tmp[nextEle]=high-1;
        }
        if((high-low)>longest){
            longest=high-low;
        }
        return longest;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
