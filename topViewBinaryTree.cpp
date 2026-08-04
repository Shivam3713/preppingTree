#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
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

    void dfs(TreeNode* node, int row, int col, map<int, pair<int, int>> &mp){
        if(!node) return;
        if(mp.find(col) == mp.end()){
            mp[col].first = row;
            mp[col].second= node->val;
        }
        else {
            if (mp[col].first > row){
                mp[col].first = row;
                mp[col].second = node->val;
            }
        }
        //left side
        dfs(node->left, row+1, col-1, mp);
        //right side
        dfs(node->right, row+1, col+1, mp);
    }
public:
    vector<int> topView(TreeNode* root) {

        vector<int> ans;

        if (!root) return ans;

        // column -> {row, value}
        map<int, pair<int, int>> mp;

        dfs(root, 0, 0, mp);

        // Iterate columns from left to right
        // Push corresponding values into ans
        for(auto it:mp){
            ans.push_back(it.second.second);
        }

        return ans;
    }
};

// Paste your Solution class here

int main() {

    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7

        Top View:
        4 2 1 3 7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.topView(root);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}