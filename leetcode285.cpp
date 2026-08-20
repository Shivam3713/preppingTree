class Solution{
public:
        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
            if(!root) return nullptr;
            TreeNode* ans = nullptr;
            while(root){
                if(p->val < root->val){
                    ans = root;
                    root= root->left;
                }
                else root= root->right;
            }
            return ans;

        }

        TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p){
            if(!root) return nullptr;
            TreeNode* ans = nullptr;
            while(root){
                if(p->val > root->val){
                    ans  = root;
                    root= root->right;
                }
                else root= root->left;
            }

            return ans;
        }
};