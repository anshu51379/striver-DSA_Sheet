// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

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
void helper(int x, stack<int> &s){
    stack<int> tmp;
    while(!s.empty() and x<s.top()){
        tmp.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!tmp.empty()){
        s.push(tmp.top());
        tmp.pop();
    }
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()){
       return;
   }
   int x=s.top();
   s.pop();
   sort();
   helper(x, s);
   return;
   
}
