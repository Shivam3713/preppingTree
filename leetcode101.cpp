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
    bool check(TreeNode*left, TreeNode*right){
        if(left == nullptr || right ==nullptr) return left == right;

        if(left->val != right->val) return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        //we need to check if the left side of the root is
        // as same as the right side of the root but in a mirror view at every node, 
        // check if leftnode==rightnode and rightnode == leftnode of recusion treating the left child and 
        // right child of root as two dofferent trees
        return  root == nullptr || check(root->left, root->right);

        
    }
};