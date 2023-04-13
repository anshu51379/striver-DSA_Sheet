// https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-an-array-is-sorted

    bool arraySortedOrNot(int arr[], int n) {
        // code here
        bool ans=true;
        for(int i=0; i<n; i+=1){
            if(arr[i]<arr[i-1]){
                ans=false;
            }
        }
        return ans;
    }
