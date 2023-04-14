// https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-insert-position-of-k-in-a-sorted-array

    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        for(int i=0; i<N; i+=1){
            if(Arr[i]==k){
                return i;
            }
        }
        for(int i=0; i<N; i+=1){
            if(Arr[i]<k and Arr[i+1]>k){
                return i+1;
            }else if(Arr[0]>k){
                return 0;
            }
        }
    }
