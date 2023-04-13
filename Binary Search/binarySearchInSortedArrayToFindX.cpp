// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search

    int binarysearch(int arr[], int n, int k) {
        // code here
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<k){
                low=mid+1;
            }else if(arr[mid]>k){
                high=mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
