// https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-left-rotation

  void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   if(n==0 or k==0){
	       return;
	   }
	   k=k%n;
	   int tmp[k];
	   for(int i=0; i<k; i+=1){
	       tmp[i]=arr[i];
	   }
	   for(int i=k; i<n; i+=1){
	       arr[i-k]=arr[i];
	   }
	   for(int i=n-k; i<n; i+=1){
	       arr[i]=tmp[i-(n-k)];
	   }
	} 
