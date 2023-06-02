// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to delete a node from BST.
Node* findLastRight(Node* root){
    if(!root->right){
        return root;
    }
    return findLastRight(root->right);
}
Node* helper(Node* root){
    if(!root->left){
        return root->right;
    }else if(!root->right){
        return root->left;
    }
    Node* tmp1=root->right;
    Node* tmp2=findLastRight(root->left);
    tmp2->right=tmp1;
    return root->left;
}
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(!root){
        return NULL;
    }
    if(root->data==X){
        return helper(root);
    }
    Node* tmp=root;
    while(root){
        if(X<root->data){
            if(root->left and X==root->left->data){
                root->left=helper(root->left);
                break;
            }else{
                root=root->left;
            }
        }else{
            if(root->right and X==root->right->data){
                root->right=helper(root->right);
                break;
            }else{
                root=root->right;
            }
        }
    }
    return tmp;
}



// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* findLastRight(TreeNode* root){
        if(!root->right){
            return root;
        }
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }else if(!root->right){
            return root->left;
        }
        TreeNode* tmp1=root->right;
        TreeNode* tmp2=findLastRight(root->left);
        tmp2->right=tmp1;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* tmp=root;
        while(root){
            if(key<root->val){
                if(root->left and key==root->left->val){
                    root->left=helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right and key==root->right->val){
                    root->right=helper(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return tmp;
    }
};
