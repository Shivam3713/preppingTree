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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            // Keep going left
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{ //right me aaagaya aur temp ko right of last pushed element banaya
                TreeNode* temp = st.top()->right;
                //agar right side exist hi nahi karta
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && st.top()->right == temp){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }

                }
                else{
                    // agar right exist karta  hai toh curr ko as a save point use karke aaage bandhne ke liye
                    curr= temp;
                }
            }
        }

        return ans;
    }
};