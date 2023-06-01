// https://practice.geeksforgeeks.org/problems/postorder-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ostorder-traversal

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

/* Computes the number of nodes in a tree. */
vector <int> postOrder(struct Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
  	 string inp;
     getline(cin, inp);
     struct Node* root = buildTree(inp);

     vector <int> res = postOrder(root);
     for (int i = 0; i < res.size (); i++)
        cout << res[i] << " ";
     cout << endl;
  }
  return 0;
}
// } Driver Code Ends


//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> res;
  stack<Node*> tmp1, tmp2;
  tmp1.push(root);
  while(!tmp1.empty()){
      root=tmp1.top();
      tmp1.pop();
      tmp2.push(root);
      if(root->left){
          tmp1.push(root->left);
      }
      if(root->right){
          tmp1.push(root->right);
      }
  }
  while(!tmp2.empty()){
      res.push_back(tmp2.top()->data);
      tmp2.pop();
  }
  return res;
}



// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode*> tmp1, tmp2;
        TreeNode* curr=root;
        tmp1.push(root);
        while(!tmp1.empty()){
            curr=tmp1.top();
            tmp1.pop();
            tmp2.push(curr);
            if(curr->left){
                tmp1.push(curr->left);
            }
            if(curr->right){
                tmp1.push(curr->right);
            }
        }
        while(!tmp2.empty()){
            res.push_back(tmp2.top()->val);
            tmp2.pop();
        }
        return res;
    }
};
