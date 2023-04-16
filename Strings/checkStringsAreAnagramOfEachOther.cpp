// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=anagram

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // Your code here
        if(a.size()!=b.size()){
            return false;
        }
        unordered_map<char, int> m;
        for(int i=0; i<a.size(); i+=1){
            m[a[i]-'a']+=1;
        }
        for(int i=0; i<b.size(); i+=1){
            m[b[i]-'a']-=1;
        }
        for(int i=0; i<m.size(); i+=1){
            if(m[i]!=0){
                return false;
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
