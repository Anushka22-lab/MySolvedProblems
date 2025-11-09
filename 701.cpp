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
    TreeNode* insertIntoBST(TreeNode* curr, int val) {
        if(!curr)return new TreeNode(val);//iterative
        TreeNode* root=curr;
        while(true){
            if(root->val>val){
                if(root->left!=nullptr){
                    root=root->left;
                }else{
                    root->left=new TreeNode(val);
                    break;
                }
            }else{
                if(root->right!=nullptr){
                    root=root->right;
                }else{
                    root->right=new TreeNode(val);
                    break;
                }
            }
        }
        return curr;
        
    }
};

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        if(val<root->val)
        root->left= insertIntoBST(root->left,val);
        else{
      root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};//recursive



