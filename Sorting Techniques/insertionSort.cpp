// https://practice.geeksforgeeks.org/problems/insertion-sort/0?category[]=Algorithms&page=1&query=category[]Algorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort
    
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1; i<n; i+=1){
            int j=i-1, tmp=arr[i];
            while(j>=0 and arr[j]>tmp){
                arr[j+1]=arr[j];
                j-=1;
            }
            arr[j+1]=tmp;
        }
    }
