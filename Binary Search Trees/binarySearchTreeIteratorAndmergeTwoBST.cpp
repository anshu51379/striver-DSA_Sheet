// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
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
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void storeInorder(Node* root, vector<int> &tmp){
        if(!root){
            return;
        }
        storeInorder(root->left, tmp);
        tmp.push_back(root->data);
        storeInorder(root->right, tmp);
    }
    vector<int> mergeVectors(vector<int> &x, vector<int> &y){
        int i=0, j=0, k=0;
        vector<int> ans(x.size()+y.size());
        while(i<x.size() and j<y.size()){
            if(x[i]<y[j]){
                ans[k]=x[i];
                i+=1;
                k+=1;
            }else{
                ans[k]=y[j];
                j+=1;
                k+=1;
            }
        }
        while(i<x.size()){
            ans[k]=x[i];
            i+=1;
            k+=1;
        }
        while(j<y.size()){
            ans[k]=y[j];
            j+=1;
            k+=1;
        }
        return ans;
    }
    Node* inorderToBST(int low, int high, vector<int> &in){
        if(low>high){
            return NULL;
        }
        int mid=low+(high-low)/2;
        Node* root=new Node(in[mid]);
        root->left=inorderToBST(low, mid-1, in);
        root->right=inorderToBST(mid+1, high, in);
        return root;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a, b, c;
       storeInorder(root1, a);
       storeInorder(root2, b);
       vector<int> final=mergeVectors(a, b);
       int low=0, high=final.size()-1;
       Node* res=inorderToBST(low, high, final);
       storeInorder(res, c);
       return c;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends



// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
private:
    stack<TreeNode*> tmp;
    void pushAll(TreeNode* root){
        for(;root!=NULL;tmp.push(root),root=root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        TreeNode* curr=tmp.top();
        tmp.pop();
        pushAll(curr->right);
        return curr->val;
    }
    bool hasNext() {
        return !tmp.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
