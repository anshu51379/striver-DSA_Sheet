// https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

    void bubbleSort(int arr[], int n)
    {
        // Your code here  
        if(n==1){
            return;
        }
        for(int i=0; i<n-1; i+=1){
            if(arr[i]>arr[i+1]){
                int tmp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=tmp;
            }
        }
        bubbleSort(arr, n-1);
    }
