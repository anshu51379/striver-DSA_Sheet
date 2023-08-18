// https://practice.geeksforgeeks.org/problems/word-break1352/1?page=1&company[]=IBM&sortBy=submissions

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> word(B.begin(), B.end());
        vector<int> tmp(A.size()+1);
        tmp[0]=1;
        for(int i=0; i<tmp.size(); i+=1){
            for(int j=0; j<i; j+=1){
                if(tmp[j] and word.count(A.substr(j, i-j))){
                    tmp[i]=1;
                    break;
                }
            }
        }
        return tmp.back();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
