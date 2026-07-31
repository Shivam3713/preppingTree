#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);

                ans.push_back(node->val);
            }

            res.push_back(ans);
        }

        return res;
    }
};

int main() {

    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";

    for (auto &level : ans) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}