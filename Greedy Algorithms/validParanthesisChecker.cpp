// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=parenthesis-checker


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<int> s; bool ans=false;
        for(int i=0; i<x.size(); i+=1){
            if(x[i]=='(' or x[i]=='{' or x[i]=='['){
                s.push(x[i]);
            }else{
                if(s.empty()){
                    return false;
                }
                char tmp=s.top();
                s.pop();
                if((x[i]==')' and tmp=='(')or(x[i]=='}' and tmp=='{')or(x[i]==']' and tmp=='[')){
                    ans=true;
                }else{
                    return false;
                }
            }
        }
        return s.empty()&&ans;
    }

};



// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int low=0, high=0;
        for(char c:s){
            if(c=='('){
                low+=1;
                high+=1;
            }else if(c==')'){
                if(low>0){
                    low-=1;
                }
                high-=1;
            }else{
                if(low>0){
                    low-=1;
                }
                high+=1;
            }
            if(high<0){
                return false;
            }
        }
        if(!low){
            return true;
        }else{
            return false;
        }
    }
};
