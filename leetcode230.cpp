class Solution {
private:
    int ans = 0;

    void dfs(TreeNode* node, int& count, int k) {

        // Inorder = Left -> Node -> Right
        //
        // Recursive assumption:
        // dfs(node->left) will completely process all nodes
        // smaller than the current node.
        if (node->left) {
            dfs(node->left, count, k);
        }

        // Once the left subtree is finished, the current node
        // becomes the next node in the sorted inorder sequence.
        count++;

        // The kth node visited during inorder traversal
        // is the kth smallest element in a BST.
        if (count == k) {
            ans = node->val;
        }

        // Now let recursion process all nodes greater
        // than the current node.
        if (node->right) {
            dfs(node->right, count, k);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        // In a BST, inorder traversal produces elements
        // in sorted ascending order.
        int count = 0;

        dfs(root, count, k);

        return ans;
    }
};