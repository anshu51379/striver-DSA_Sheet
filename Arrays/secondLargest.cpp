// https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest

  int print2largest(int arr[], int n) {
	    // code here
	    int max=0, secondMax=0;
	    for(int i=0; i<n; i+=1){
	        if(max<arr[i]){
	            max=arr[i];
	        }
	    }
	    for(int i=0; i<n; i+=1){
	        if((secondMax<arr[i])and(max>arr[i])){
	            secondMax=arr[i];
	        }
	    }
	    if(!secondMax){
	        return -1;
	    }
	    return secondMax;
	}
