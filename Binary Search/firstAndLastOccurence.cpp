// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=first-and-last-occurrences-of-x

vector<int> find(int arr[], int n , int x )
{
    // code here
    int flag=0;
    int i=0, j=n-1;
    vector<int> ans, tmp;
    while(i<n){
        if(arr[i]==x){
            ans.push_back(i);
            i+=1;
            flag=1;
            break;
        }else{
            i+=1;
        }
    }
    while(j>0){
        if(arr[j]==x){
            ans.push_back(j);
            flag=1;
            j-=1;
            break;
        }else{
            j-=1;
        }
    }
    sort(ans.begin(), ans.end());
    if(flag){
        return ans;
    }else{
        tmp.push_back(-1);
        tmp.push_back(-1);
        return tmp;
    }
}


// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int helper1(vector<int> arr, int x){
        int low=0, high=arr.size()-1, tmp=-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(arr[mid]==x){
                tmp=mid;
                high=mid-1;
            }else if(arr[mid]>x){
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return tmp;
    }
    int helper2(vector<int> arr, int x){
        int low=0, high=arr.size()-1, tmp=-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(arr[mid]==x){
                tmp=mid;
                low=mid+1;
            }else if(arr[mid]>x){
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return tmp;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(helper1(nums, target));
        ans.push_back(helper2(nums, target));
        return ans;
    }
};
