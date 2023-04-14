// https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-the-element-that-appears-once-in-sorted-array

    int findOnce(int arr[], int n)
    {
        //code here.
        int low=0, high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]!=arr[mid^1]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return arr[low];
    }

// https://leetcode.com/problems/single-element-in-a-sorted-array/

    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[1^mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return nums[low];
    }
