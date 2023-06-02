// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int res=-1;
    while(root){
        if(root->val==X){
            res=root->val;
            return res;
        }
        if(X>root->val){
            res=root->val;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return res;
}
