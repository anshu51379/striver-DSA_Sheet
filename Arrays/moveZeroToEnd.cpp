// https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=move-all-zeroes-to-end-of-array

  void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int iZero=0;
	    while(iZero<n){
	        if(arr[iZero]==0){
	            break;
	        }else{
	            iZero+=1;
	        }
	    }
	    int low=iZero, high=iZero+1;
	    while(low<n and high<n){
	        if(arr[high]!=0){
	            int tmp=arr[low];
	            arr[low]=arr[high];
	            arr[high]=tmp;
	            low+=1;
	        }
	        high+=1;
	    }
	}
