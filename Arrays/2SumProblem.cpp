// https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int i=0, j=n-1;
    sort(book.begin(), book.end());
    while(i<=j){
        if(book[i]+book[j]==target){
            return "YES";
        }else if(book[i]+book[j]<target){
            i+=1;
        }else{
            j-=1;
        }
    }
    return "NO";
}

// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmp;
        for(int i=0; i<nums.size(); i+=1){
            if(tmp.find(target-nums[i])==tmp.end()){
                tmp[nums[i]]=i;
            }else{
                return {tmp[target-nums[i]], i};
            }
        }
        return {-1, -1};
    }
};
