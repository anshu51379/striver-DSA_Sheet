// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

  int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int iRow=0, val=-1;
	    for(int i=0; i<n; i+=1){
	        int cnt=0;
	        for(int j=0; j<m; j+=1){
	            if(arr[i][j]==0){
	                cnt+=1;
	            }else{
	                break;
	            }
	        }
	        int tmp=m-cnt;
	        if(tmp==m){
	            return i;
	        }else{
	            if(tmp>iRow){
	                iRow=tmp;
	                val=i;
	            }
	        }
	    }
	    return val;
	}
