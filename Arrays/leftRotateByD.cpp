// https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reversal-algorithm

    void leftRotate(int arr[], int n, int d) {
        // code here
        if(d==0 or n==0){
            return;
        }
        d=d%n;
        int tmp[d];
        for(int i=0; i<d; i+=1){
            tmp[i]=arr[i];
        }
        for(int i=d; i<n; i+=1){
            arr[i-d]=arr[i];
        }
        for(int i=n-d; i<n; i+=1){
            arr[i]=tmp[i-(n-d)];
        }
    }
