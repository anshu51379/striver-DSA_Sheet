// https://practice.geeksforgeeks.org/problems/largest-bst/1

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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
// class NodeVal{
//     public:
//     int maxi, mini, size;
//     NodeVal(int maxi, int mini, int size){
//         this->mini=mini;
//         this->maxi=maxi;
//         this->size=size;
//     }
// };
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    // NodeVal helper(Node* root){
    //     if(!root){
    //         return NodeVal(INT_MAX, INT_MIN, 0);
    //     }
    //     NodeVal tmp1=helper(root->left);
    //     NodeVal tmp2=helper(root->right);
    //     if(tmp1.maxi<root->data and root->data<tmp2.mini){
    //         return NodeVal(min(root->data, tmp1.mini), max(root->data, tmp2.maxi), tmp1.size+tmp2.size+1);
    //     }
    //     return NodeVal(INT_MIN, INT_MAX, max(tmp1.size, tmp2.size));
    // }
    vector<int> helper(Node* root, int &size){
        if(!root){
            return {1, INT_MAX, INT_MIN, 0};
        }
        auto tmp1=helper(root->left, size);
        auto tmp2=helper(root->right, size);
        if(tmp1[0] and tmp2[0] and root->data>tmp1[2] and root->data<tmp2[1]){
            size=max(size, tmp1[3]+tmp2[3]+1);
            int mini=min({tmp1[1], tmp2[1], root->data});
            int maxi=max({tmp1[2], tmp2[2], root->data});
            return {1, mini, maxi, tmp1[3]+tmp2[3]+1};
        }
        return {0, 0, 0, tmp1[3]+tmp2[3]+1};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    // 	return helper(root).size;
        int ans=0;
        helper(root, ans);
        return ans;
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
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends
