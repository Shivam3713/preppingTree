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
    int heigh(TreeNode* node){
        if(!node) return 0;
        int lh = heigh(node->left);
        int rh = heigh(node->right);
        return 1+max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh = heigh(root->left);
        int rh = heigh(root->right);
        if(abs(lh-rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};