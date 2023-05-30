// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-a-matrix

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int i=0, j=M-1;
	    while(i<N and j>=0){
	        if(mat[i][j]==X){
	            return 1;
	        }
	        if(mat[i][j]<X){
	            i+=1;
	        }else{
	            j-=1;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends



// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()){
	        return false;
	    }
        int N=matrix.size(), M=matrix[0].size();
	    int low=0, high=(N*M)-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(matrix[mid/M][mid%M]==target){
	            return true;
	        }else if(matrix[mid/M][mid%M]<target){
	            low=mid+1;
	        }else{
	            high=mid-1;
	        }
	    }
	    return false;
    }
};
