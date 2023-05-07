// https://practice.geeksforgeeks.org/problems/lemonade-change/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=lemonade-change

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int d1=0, d2=0, d3=0;
        for(int i=0; i<N; i+=1){
            if(bills[i]==5){
                d1+=1;
            }else if(bills[i]==10 and d1>0){
                d2+=1;
                d1-=1;
            }else if(bills[i]==20 and d1>0 and d2>0){
                d3+=1;
                d1-=1;
                d2-=1;
            }else if(bills[i]==20 and d1>=3){
                d3+=1;
                d1-=3;
            }else{
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> tmp;
        for(int i:bills){
            tmp[i]+=1;
            if(tmp[5]<tmp[10]+tmp[20] or tmp[5]<3*tmp[20]-tmp[10]){
                return false;
            }
        }
        return true;
    }
};
