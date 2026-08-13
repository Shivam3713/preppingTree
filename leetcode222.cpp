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
    int leftheight(TreeNode* root){
        int ans =0;
        while(root){
            ans+=1;
            root = root->left;
        }
        return ans;
    }
    int rightheight(TreeNode* root){
        int ans =0;
        while(root){
            ans+=1;
            root=root->right;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans  =0;
        if(!root) return ans;
        int lh = leftheight(root); // since calculating height from the root and not from root->left or root->right
        int rh = rightheight(root);
        if(lh == rh) return (1<<lh) -1; //2^h -1 is the height formula for compelte BT
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};