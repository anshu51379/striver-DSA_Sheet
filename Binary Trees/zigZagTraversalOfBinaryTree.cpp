// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=zigzag-tree-traversal

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code 
    	vector<int> res;
    	if(!root){
    	    return res;
    	}
    	queue<Node*> tmp;
    	tmp.push(root);
    	int index=0;
    	bool flag=true;
    	while(!tmp.empty()){
    	    int sz=tmp.size();
    	    vector<int> level(sz);
    	    for(int i=0; i<sz; i+=1){
    	        Node* curr=tmp.front();
    	        tmp.pop();
    	        if(flag){
    	            index=i;
    	        }else{
    	            index=sz-1-i;
    	        }
    	        level[index]=curr->data;
    	        if(curr->left){
    	            tmp.push(curr->left);
    	        }
    	        if(curr->right){
    	            tmp.push(curr->right);
    	        }
    	    }
    	    flag=!flag;
    	    for(int i=0; i<sz; i+=1){
    	        res.push_back(level[i]);
    	    }
    	}
    	return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends



// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> tmp;
        tmp.push(root);
        bool flag=true;
        int index=0;
        while(!tmp.empty()){
            int sz=tmp.size();
            vector<int> a(sz);
            for(int i=0; i<sz; i+=1){
                TreeNode* curr=tmp.front();
                tmp.pop();
                if(flag){
                    index=i;
                }else{
                    index=sz-1-i;
                }
                a[index]=curr->val;
                if(curr->left){
                    tmp.push(curr->left);
                }
                if(curr->right){
                    tmp.push(curr->right);
                }
            }
            flag=!flag;
            res.push_back(a);
        }
        return res;
    }
};
