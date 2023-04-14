// https://practice.geeksforgeeks.org/problems/peak-element/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=peak-element

    int peakElement(int arr[], int n)
    {
       // Your code here
       int ans=0;
       for(int i=0; i<n-1; i+=1){
           if(arr[i]<arr[i+1]){
               ans=i+1;
           }
       }
       return ans;
    }
