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
    int height(TreeNode* root){
        if(!root){
            return 0;//empty tree
        }
        int left=height(root->left);//check left subtree
            if(left==-1)return -1;
        int right=height(root->right);//check right subtree
            if(right==-1)return -1;
        if(abs(right-left)>1){
            return -1;//one side is heavy
        }
        return 1+max(left,right);//bottom-up approach ek bhi unbalanced node mila toh stop checking and return false kyuki -1 dedega
        
    }
    bool isBalanced(TreeNode* root) {
        return (height(root)!=-1);

        
    }
};