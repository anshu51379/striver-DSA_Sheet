// https://practice.geeksforgeeks.org/problems/missing-number4257/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=missing-number

int missingNumber(int A[], int N)
{
    // Your code goes here
    int tmp[N+1]={0};
    for(int i=0; i<N-1; i+=1){
        tmp[A[i]]+=1;
    }
    for(int i=1; i<=N; i+=1){
        if(tmp[i]==0){
            return i;
        }
    }
    return -1;
}
