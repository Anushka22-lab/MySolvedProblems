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
private:
   TreeNode* findMin(TreeNode* root){
    while(root && root->left){
        root=root->left;
    }return root;
   }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }else{
            if(!root->left && !root->right){
                //node found
                //no child
                delete root;
                return nullptr;
           }
           else if(!root->left){//only right child
            TreeNode* temp=root->right;
            delete root;
            return temp;
           }
           else if(!root->right){//only left child
            TreeNode* temp=root->left;
            delete root;
            return temp;
           }else{
            TreeNode* succ=findMin(root->right);//both children
            root->val=succ->val;
            root->right=deleteNode(root->right,succ->val);
           }

        }
        return root;

        
    }
};