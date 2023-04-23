// https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int low=0, high=0, res=0;
        unordered_map<int, int> tmp;
        while(high<fruits.size()){
            tmp[fruits[high]]=high;
            while(tmp.size()>2){
                if(tmp[fruits[low]]==low){
                    tmp.erase(fruits[low]);
                }
                low+=1;
            }
            res=max(res, high-low+1);
            high+=1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends



// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0, high=0, res=0;
        unordered_map<int, int> tmp;
        while(high<fruits.size()){
            tmp[fruits[high]]=high;
            while(tmp.size()>2){
                if(tmp[fruits[low]]==low){
                    tmp.erase(fruits[low]);
                }
                low+=1;
            }
            res=max(res, high-low+1);
            high+=1;
        }
        return res;
    }
};
