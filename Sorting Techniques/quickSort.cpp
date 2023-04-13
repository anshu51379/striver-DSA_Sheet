//https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort

    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int iPivot=partition(arr, low, high);
            quickSort(arr, low, iPivot-1);
            quickSort(arr, iPivot+1, high);
        }
    }
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low], i=low, j=high;
       while(i<j){
           while(arr[i]<=pivot && i<=high-1){
               i+=1;
           }
           while(arr[j]>pivot && j>=low+1){
               j-=1;
           }
           if(i<j){
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[low], arr[j]);
       return j;
    }
