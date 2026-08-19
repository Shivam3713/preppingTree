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
    TreeNode* helper(TreeNode* root){
        if(!root->right) return root->left;
        if(!root->left) return root->right;
        TreeNode* child = root->right;
        while(child->left){
            child = child->left;
        }
        child->left= root->left;
        root->left = nullptr;
        return root->right;

    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* parent= root;
        while(root){

    // If the node to be deleted is the original root,
    // there is no parent pointer to update.
    // So we directly return the new subtree root produced by helper().
    if(root->val == key)
        return helper(root);

    if(key < root->val){

        // We call helper() on root->left (not on root) because
        // root is the parent of the node that must be deleted.
        // helper() returns the new root of that subtree after deletion,
        // which must be attached back to root->left.
        if(root->left && root->left->val == key){
            root->left = helper(root->left);
            break;
        }

        root = root->left;
    }
    else{

        // Same idea here.
        // root->right is the node being deleted, while root is its parent.
        // After deletion, helper() returns the updated subtree root,
        // which is reattached to root->right.
        if(root->right && root->right->val == key){
            root->right = helper(root->right);
            break;
        }

        root = root->right;
    }
}
        return parent;
    }
};