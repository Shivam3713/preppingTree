#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
private:
    bool find(TreeNode*node, int target, vector<int>&path){
        if(!node){
            return false;
        };
        path.push_back(node->val);
        if(node->val == target) return true;
        if(find(node->left, target, path)){
            return true;
        }
        if(find(node->right, target, path)){
            return true;
        }
        path.pop_back();
        return node->val  == target;
        return false;

    }
public:
    // Write your LeetCode solution here.
    vector<int> rootToNode(TreeNode* root, int target) {
        vector<int>res;
        if(!root) return res;
        find(root, target, res);
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
               / \
              8   9

        Example paths:
        target = 9 -> 1 2 5 9
        target = 6 -> 1 3 6
        target = 4 -> 1 2 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<int> path = obj.rootToNode(root, target);

    if (path.empty()) {
        cout << "Target not found.\n";
    } else {
        cout << "Root to Node Path: ";
        for (int x : path)
            cout << x << " ";
        cout << '\n';
    }

    return 0;
}