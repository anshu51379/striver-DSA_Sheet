// https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-all-binary-strings

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(int i, int n, char arr[]){
        if(i==n){
            arr[n]=NULL;
            cout<<arr<<" ";
            return;
        }
        arr[i]='0';
        helper(i+1, n, arr);
        if(!i or (i>0 and arr[i-1]=='0')){
            arr[i]='1';
            helper(i+1, n, arr);
        }
    }
    void generateBinaryStrings(int num){
        //Write your code
        char arr[num];
        helper(0, num, arr);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
