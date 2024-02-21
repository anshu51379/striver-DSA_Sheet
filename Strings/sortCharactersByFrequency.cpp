// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> tmp;
        vector<pair<int,char>> arr;
        for(auto it:s){
            tmp[it]+=1;
        }
        for(auto it:tmp){
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end(), greater<pair<int,char>>());
        string res="";
        for(auto it:arr){
            while(it.first){
                res+=it.second;
                it.first-=1;
            }
        }
        return res;
    }
};

// https://www.codingninjas.com/studio/problems/sorting-characters-by-frequency_1263699?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	unordered_map<char, int> tmp;
    vector<pair<int,char>> arr;
    for(auto it:s){
        tmp[it]+=1;
    }
    for(auto it:tmp){
        arr.push_back({it.second, it.first});
    }
    sort(arr.begin(), arr.end(), greater<pair<int,char>>());
    string res="";
    for(auto it:arr){
        while(it.first){
            res+=it.second;
            it.first-=1;
        }
    }
    return res;
}

def sortByFrequency(n: int, s: str) -> str:
    dic = {}
    for i in s:
        if i in dic:
            dic[i]+=1
        else:
            dic[i]=1
    st = ""
    for i in sorted(dic.items(), key=lambda x:x[1]):
        st += i[0] * i[1]
    return st[::-1]
    pass
