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
    using Node=TreeNode;
    int leftheight(Node* n){
        int h=0;
        while(n){
            h++;
            n=n->left;
        }
        return h;
    }
    int rightheight(Node* n){
        int h=0;
        while(n){
            h++;
            n=n->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh)return (1<<lh)-1;//perfect(2^h-1)
        return 1+countNodes(root->left)+countNodes(root->right);//non-perfect
  
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
int c=0;
    void inorder(TreeNode* n){
       if(n==nullptr)return;
      
        inorder(n->left);
       c++;
         inorder(n->right);
    }
    int countNodes(TreeNode* root) {
         inorder(root);
         return c;
    }
};