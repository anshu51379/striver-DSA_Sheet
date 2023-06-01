// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=boundary-traversal-of-binary-tree

// class Solution {
// public:
//     bool isLeaf(Node* tmp){
//         return !(tmp->left) and !(tmp->right);
//     }
//     void leftBoundaryNodes(Node* root, vector<int> &res){
//         Node* curr=root->left;
//         while(curr){
//             if(!isLeaf(curr)){
//                 res.push_back(curr->data);
//             }
//             if(curr->left){
//                 curr=curr->left;
//             }else{
//                 curr=curr->right;
//             }
//         }
//     }
//     void leafNodes(Node* root, vector<int> &res){
//         if(isLeaf(root)){
//             res.push_back(root->data);
//             return;
//         }
//         if(root->left){
//             leafNodes(root->left, res);
//         }
//         if(root->right){
//             leafNodes(root->right, res);
//         }
//     }
//     void rightBoundaryNodes(Node* root, vector<int> &res){
//         Node* curr=root->right;
//         vector<int> tmp;
//         while(curr){
//             if(isLeaf(curr)){
//                 tmp.push_back(curr->data);
//             }
//             if(curr->right){
//                 curr=curr->right;
//             }else{
//                 curr=curr->left;
//             }
//         }
//         for(int i=tmp.size()-1; i>=0; i-=1){
//             res.push_back(tmp[i]);
//         }
//     }
//     vector <int> boundary(Node *root)
//     {
//         //Your code here
//         vector<int> res;
//         if(!root){
//             return res;
//         }
//         if(!isLeaf(root)){
//             res.push_back(root->data);
//         }
//         leftBoundaryNodes(root, res);
//         leafNodes(root, res);
//         rightBoundaryNodes(root, res);
//         return res;
//     }
// };

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int> res;
    void left(Node* root){
        if(!root){
            return;
        }if(root->left){
            res.push_back(root->data);
            left(root->left);
        }else if(root->right){
            res.push_back(root->data);
            left(root->right);
        }
    }
    void leaf(Node* root){
        if(!root){
            return;
        }leaf(root->left);
        if(!root->left and !root->right){
            res.push_back(root->data);
        }leaf(root->right);
    }
    void right(Node* root){
        if(!root){
            return;
        }
        if(root->right){
            right(root->right);
            res.push_back(root->data);
        }else if(root->left){
            right(root->left);
            res.push_back(root->data);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(!root){
            return res;
        }
        res.push_back(root->data);
        left(root->left);
        leaf(root->left);
        leaf(root->right);
        right(root->right);
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
