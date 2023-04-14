// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long ans=-1;
        for(long long i=0; i<n; i+=1){
            if(v[i]<=x){
                ans=i;
            }
        }
        return int(ans);
    }
