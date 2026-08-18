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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* leftchild = curr->left;
                //now we need to go to the right most
                while(leftchild->right != nullptr){
                    leftchild = leftchild->right;
                }
                leftchild->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr=curr->right;
        }
    }
};