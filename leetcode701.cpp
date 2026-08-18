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
        if(!root) return new TreeNode(val);
        TreeNode * curr = root;
        while(true){
            if(val > curr->val){ //if myu node would be on the right side
                if(curr->right) curr = curr->right; //agar right exist karta hai toh right jao
                else {curr->right = new TreeNode(val); // nahi toh naya node banake usko connect kardo
                break;}
            }
            else{
                if(curr->left) curr= curr->left; //agar left exist karta hai toh left jao
                else {curr->left = new TreeNode(val); //nahi toh naya node banake usko connect kardo
                break;}
            }

        }
        return root;
    }
};