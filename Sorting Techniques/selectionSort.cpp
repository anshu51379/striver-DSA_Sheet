// https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int iMin=i;
        for(int j=i+1; j<n; j+=1){
            if(arr[j]<arr[iMin]){
                iMin=j;
            }
        }
        return iMin;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=0; i<n-1; i+=1){
           int iMin=select(arr, i, n);
           int tmp=arr[iMin];
           arr[iMin]=arr[i];
           arr[i]=tmp;
       }
    }
