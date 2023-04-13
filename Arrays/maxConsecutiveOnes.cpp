// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximize-number-of-1s

    int findZeroes(int arr[], int n, int m) {
        // code here
        int i=0, j=0, tmp=0, cnt=0;
        while(j<n){
            if(tmp<=m){
                if(arr[j]==0){
                    tmp+=1;
                }
                cnt=max(cnt,j-i);
                j+=1;
            }else{
                if(arr[i]==0){
                    tmp-=1;
                }
                i+=1;
            }
        }
        if(tmp<=m){
            cnt=max(cnt,j-i);
        }
        return cnt;
    }  


// https://leetcode.com/problems/max-consecutive-ones/

int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, tmp=0, cnt=0;
        while(i<nums.size()){
            if(nums[i]==1){
                tmp+=1;
                cnt=max(cnt, tmp);
            }else{
                tmp=0;
            }
            i+=1;
        }
        return cnt;
    }
