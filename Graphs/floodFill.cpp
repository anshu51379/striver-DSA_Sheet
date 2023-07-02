// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm\

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &tmp, vector<vector<int>> &image, int newColor, int dRow[], int dCol[], int iniColor){
        tmp[row][col]=newColor;
        for(int i=0; i<4; i+=1){
            int nRow=row+dRow[i];
            int nCol=col+dCol[i];
            if(nRow>=0 and nRow<image.size() and nCol>=0 and nCol<image[0].size() and image[nRow][nCol]==iniColor and tmp[nRow][nCol]!=newColor){
                dfs(nRow, nCol, tmp, image, newColor, dRow, dCol, iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniColor=image[sr][sc];
        vector<vector<int>> tmp=image;
        int dRow[]={-1, 0, 1, 0};
        int dCol[]={0, 1, 0, -1};
        dfs(sr, sc, tmp, image, newColor, dRow, dCol, iniColor);
        return tmp;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &image, int color, vector<vector<int>> &tmp, int dRow[], int dCol[], int tmpColor){
        tmp[row][col]=color;
        for(int i=0; i<4; i+=1){
            int nRow=row+dRow[i];
            int nCol=col+dCol[i];
            if(nRow>=0 and nCol>=0 and nRow<image.size() and nCol<image[0].size() and image[nRow][nCol]==tmpColor and tmp[nRow][nCol]!=color){
                dfs(nRow, nCol, image, color, tmp, dRow, dCol, tmpColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int tmpColor=image[sr][sc];
        vector<vector<int>> tmp=image;
        int dRow[]={-1, 0, 1, 0};
        int dCol[]={0, 1, 0, -1};
        dfs(sr, sc, image, color, tmp, dRow, dCol, tmpColor);
        return tmp;
    }
};
