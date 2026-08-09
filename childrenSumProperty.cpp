#include <bits/stdc++.h>
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
    bool checkChildrenSum(TreeNode* root) {
        // Your solution here
        if(!root || (root->left == nullptr && root->right == nullptr)) return true; //since if the node is nullptr it still satiesfies that it cant process both its own left and right
        int left =0, right =0;
        if(root->left){
            left = root->left->val;
        }
        if(root->right){
            right = root->right->val;
        }
        return (root->val == left+right) && checkChildrenSum(root->left) && checkChildrenSum(root->right);
        
    }
};

int main() {

    /*
                  10
                /    \
               4      6
              / \    / \
             2   2  3   3

        Children Sum Property:
        
        Node 10:
            4 + 6 = 10  ✓

        Node 4:
            2 + 2 = 4   ✓

        Node 6:
            3 + 3 = 6   ✓

        Therefore answer = true
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    Solution obj;

    bool result = obj.checkChildrenSum(root);

    if (result)
        cout << "Children Sum Property satisfied\n";
    else
        cout << "Children Sum Property NOT satisfied\n";

    return 0;
}