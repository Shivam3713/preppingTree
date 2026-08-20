class BSTIterator{

    public:
        stack<TreeNode*> st;
        bool flag;

        BSTIterator(TreeNode* root, bool flag){ 
            // Constructor definition.
            // Stores traversal direction and initializes the stack
            // with either the leftmost path (inorder) or rightmost path
            // (reverse inorder).
            this->flag = flag;
            pushAll(root, flag);
        }

        void pushAll(TreeNode* root, bool flag){

            while(root){
                st.push(root);

                if(flag){
                    // Reverse inorder iterator:
                    // keep moving right and push all nodes
                    // until the rightmost node is reached.
                    root = root->right;
                }
                else{
                    // Inorder iterator:
                    // keep moving left and push all nodes
                    // until the leftmost node is reached.
                    root = root->left;
                }
            }
        }

        int next(){

            auto node = st.top();
            st.pop();

            // For the normal inorder iterator,
            // after visiting a node, we must process
            // its right subtree and push its leftmost path.
            if(node->right)
                pushAll(node->right, false);

            return node->val;
        }

        int before(){

            auto node = st.top();
            st.pop();

            // For the reverse inorder iterator,
            // after visiting a node, we must process
            // its left subtree and push its rightmost path.
            if(node->left)
                pushAll(node->left, true);

            return node->val;
        }
};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {

        if(!root) return false;

        BSTIterator left(root, false);
        // Creates an inorder iterator.
        // Constructor fills stack with the leftmost path,
        // so the first value returned will be the smallest.

        BSTIterator right(root, true);
        // Creates a reverse inorder iterator.
        // Constructor fills stack with the rightmost path,
        // so the first value returned will be the largest.

        int start = left.next();
        // Current smallest available value.

        int end = right.before();
        // Current largest available value.

        while(start < end){

            if(start + end < k){
                // Sum too small, move left iterator forward.
                start = left.next();
            }
            else if(start + end > k){
                // Sum too large, move right iterator backward.
                end = right.before();
            }
            else return true;
        }

        return false;
    }
};