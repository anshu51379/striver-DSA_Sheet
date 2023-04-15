// https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

  int findKRotation(int arr[], int n) {
	    // code here
	    int minVal=*min_element(arr, arr+n);
	    for(int i=0; i<n; i+=1){
	        if(arr[i]==minVal){
	            return i;
	        }
	    }
	}
