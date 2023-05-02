// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=fractional-knapsack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool helpCompare(Item x, Item y){
        double tmp1=(double)x.value/(double)x.weight;
        double tmp2=(double)y.value/(double)y.weight;
        return tmp1>tmp2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, helpCompare);
        // int currWt=0;
        double res=0.0; int i=0;
        // for(int i=0; i<n; i+=1){
        //     if(currWt+arr[i].weight<=W){
        //         currWt+=arr[i].weight;
        //         res+=arr[i].weight;
        //     }else{
        //         int tmp=W-currWt;
        //         res+=(arr[i].value/(double)arr[i].weight)*(double)tmp;
        //         break;
        //     }
        // }
        // return res;
        while(i<n and W>=0){
            if(arr[i].weight>W){
                res+=((double)arr[i].value/arr[i].weight)*W;
                break;
            }else{
                W=W-arr[i].weight;
                res+=arr[i].value;
            }
            i+=1;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
