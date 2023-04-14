// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

  int count(int arr[], int n, int x) {
	    // code here
	    int cnt=0; 
	    for(int i=0; i<n; i+=1){
	        if(arr[i]==x){
	            cnt+=1;
	        }
	    }
	    return cnt;
	}
