// https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

void bubbleSort(int arr[], int n)
    {
        // Your code here  
        for(int i=n-1; i>=0; i-=1){
            for(int j=0; j<=i-1; j+=1){
                if(arr[j+1]<arr[j]){
                    int tmp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=tmp;
                }
            }
        }
    }
