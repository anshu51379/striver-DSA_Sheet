// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-a-binary-tree-in-vertical-order

//{ Driver Code Starts
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void helper(Node* root, int x, int y, map<int, map<int, vector<int>>> &m){
        if(!root){
            return;
        }
        m[x][y].push_back(root->data);
        helper(root->left, x-1, y+1, m);
        helper(root->right, x+1, y+1, m);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> res;
        map<int, map<int, vector<int>>> m;
        helper(root, 0, 0, m);
        for(auto &i:m){
            vector<int> tmp;
            for(auto &j:i.second){
                // sort(j.second.begin(), j.second.end());
                tmp.insert(tmp.end(), j.second.begin(), j.second.end());
            }
            for(int k=0; k<tmp.size(); k+=1){
                res.push_back(tmp[k]);
            }
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends



// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto tmp1=q.front();
            q.pop();
            TreeNode* tmp2=tmp1.first;
            int a=tmp1.second.first, b=tmp1.second.second;
            m[a][b].insert(tmp2->val);
            if(tmp2->left){
                q.push({tmp2->left, {a-1, b+1}});
            }
            if(tmp2->right){
                q.push({tmp2->right, {a+1, b+1}});
            }
        }
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            res.push_back(v);
        }
        return res;
    }
};
