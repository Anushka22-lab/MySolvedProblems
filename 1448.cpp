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
    int countnodes(TreeNode* root,int maxsofar){
        int c=0;
        if(!root)return 0;
        if(root->val>=maxsofar){
         c++;
        }
        maxsofar=max(maxsofar,root->val);
        c+=countnodes(root->left,maxsofar);
        c+=countnodes(root->right,maxsofar);
        return c;
        
    }
    int goodNodes(TreeNode* root) {
        return countnodes(root,root->val);
        
    }
};