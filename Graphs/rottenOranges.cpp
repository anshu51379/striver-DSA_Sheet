// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten-oranges

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>, int>> tmp;
        int vis[n][m];
        int cntFresh=0;
        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                if(grid[i][j]==2){
                    tmp.push({{i, j}, 0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntFresh+=1;
                }
            }
        }
        int cntT=0;
        int addRow[]={-1, 0, 1, 0};
        int addCol[]={0, 1, 0, -1};
        int cnt=0;
        while(!tmp.empty()){
            int row=tmp.front().first.first;
            int col=tmp.front().first.second;
            int tmpT=tmp.front().second;
            cntT=max(cntT, tmpT);
            tmp.pop();
            for(int i=0; i<4; i+=1){
                int nRow=row+addRow[i];
                int nCol=col+addCol[i];
                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and vis[nRow][nCol]==0 and grid[nRow][nCol]==1){
                    tmp.push({{nRow, nCol}, tmpT+1});
                    vis[nRow][nCol]=2;
                    cnt+=1;
                }
            }
        }
        // for(int i=0; i<n; i+=1){
        //     for(int j=0; j<m; j+=1){
        //         if(vis[i][j]!=2 and grid[i][j]!=1){
        //             return -1;
        //         }
        //     }
        // }
        if(cnt!=cntFresh){
            return -1;
        }
        return cntT;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>, int>> tmp;
        int vis[n][m];
        // int cntFresh=0;
        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                if(grid[i][j]==2){
                    tmp.push({{i, j}, 0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                // if(grid[i][j]==1){
                //     cntFresh+=1;
                // }
            }
        }
        int cntT=0;
        int addRow[]={-1, 0, 1, 0};
        int addCol[]={0, 1, 0, -1};
        // int cnt=0;
        while(!tmp.empty()){
            int row=tmp.front().first.first;
            int col=tmp.front().first.second;
            int tmpT=tmp.front().second;
            cntT=max(cntT, tmpT);
            tmp.pop();
            for(int i=0; i<4; i+=1){
                int nRow=row+addRow[i];
                int nCol=col+addCol[i];
                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and vis[nRow][nCol]==0 and grid[nRow][nCol]==1){
                    tmp.push({{nRow, nCol}, tmpT+1});
                    vis[nRow][nCol]=2;
                    // cnt+=1;
                }
            }
        }
        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                if(vis[i][j]!=2 and grid[i][j]==1){
                    return -1;
                }
            }
        }
        // if(cnt!=cntFresh){
        //     return -1;
        // }
        return cntT;
    }
};
