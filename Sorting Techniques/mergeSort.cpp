//https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
    
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int> tmp;
         int low=l, high=m+1;
         while(low<=m and high<=r){
             if(arr[low]<=arr[high]){
                 tmp.push_back(arr[low]);
                 low+=1;
             }else{
                 tmp.push_back(arr[high]);
                 high+=1;
             }
         }
         while(low<=m){
             tmp.push_back(arr[low]);
             low+=1;
         }
         while(high<=r){
             tmp.push_back(arr[high]);
             high+=1;
         }
         for(int i=l; i<=r; i+=1){
             arr[i]=tmp[i-l];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
