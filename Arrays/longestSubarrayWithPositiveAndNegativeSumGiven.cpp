// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<long long, int> tmp;
        long long sum=0; int dMax=0;
        for(int i=0; i<N; i+=1){
            sum+=A[i];
            if(sum==K){
                dMax=max(dMax, i+1);
            }
            long long val=sum-K;
            if(tmp.find(val)!=tmp.end()){
                dMax=max(dMax, i-tmp[val]);
            }
            if(tmp.find(sum)==tmp.end()){
                tmp[sum]=i;
            }
        }
        return dMax;
    } 
