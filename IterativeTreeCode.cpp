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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(root==nullptr)return preorder;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return preorder;
        
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(true){
            if(node!=nullptr){
               st.push(node);
               node=node->left;
            }else{
                if(st.empty()){break;}
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
        
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;              // final result
        if (root == nullptr) return post;

        stack<TreeNode*> st;           // LIFO stack
        TreeNode* cur = root;          // current node pointer

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);          // push current node
                cur = cur->left;       // go left
            } 
            else {
                TreeNode* temp = st.top()->right;   // check right child of top node
                if (temp == nullptr) {
                    // if no right child, pop and add to postorder
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);

                    // check if popped node was right child of stack top
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        post.push_back(temp->val);
                    }
                } 
                else {
                    // if right child exists, move to right
                    cur = temp;
                }
            }
        }
        return post;
    }
};



