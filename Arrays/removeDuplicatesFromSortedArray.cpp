// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicate-elements-from-sorted-array

    int remove_duplicate(int a[],int n){
        // code here
        int i=0, j=0;
        for(j=1; j<n; j+=1){
            if(a[i]!=a[j]){
                i+=1;
                a[i]=a[j];
            }
        }
        return 1+i;
    }
