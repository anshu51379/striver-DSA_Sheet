// https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-element-in-a-sorted-and-rotated-array

    int findMin(int arr[], int n){
        //complete the function here
        return *min_element(arr, arr+n);
    }

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/

    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
