// https://practice.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortedInsert(stack<int> &s, int a){
    if(s.empty() or s.top()<a){
        s.push(a);
    }else{
        int tmp=s.top();
        s.pop();
        sortedInsert(s,a);
        s.push(tmp);
    }
}
void reverseStack(stack<int> &s){
    if(s.size()){
        int tmp=s.top();
        s.pop();
        reverseStack(s);
        sortedInsert(s,tmp);
    }
}
void SortedStack :: sort()
{
   //Your code here
   reverseStack(s);
}
