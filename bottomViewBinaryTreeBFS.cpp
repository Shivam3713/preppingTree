#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    vector<int> bottomView(TreeNode* root) {

        vector<int> res;

        if (root == nullptr)
            return res;

        // column -> node value
        map<int, int> mp;

        // {node, column}
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            TreeNode* curr = q.front().first;
            int col = q.front().second;
            q.pop();

            // Overwrite every time.
            // The last node seen in this column will remain.
            mp[col] = curr->val;

            if (curr->left)
                q.push({curr->left, col - 1});

            if (curr->right)
                q.push({curr->right, col + 1});
        }

        for (auto it : mp)
            res.push_back(it.second);

        return res;
    }
};

int main() {

    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7

        Bottom View:
        4 2 6 3 7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.bottomView(root);

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}