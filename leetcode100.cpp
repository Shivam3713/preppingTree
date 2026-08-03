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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //check for values if they're same, if same then  check for their children in both left and right subtree
        if( p == nullptr || q == nullptr) return p == q;
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};