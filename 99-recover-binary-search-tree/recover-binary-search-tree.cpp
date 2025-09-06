class Solution {
private:
    void solve(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &end){
        if(!root) return;

        solve(root -> left,prev,first,end);

        if(prev && prev -> val > root -> val){
            if(!first) first = prev;
            end = root;
        }

        prev = root;
        solve(root -> right,prev,first,end);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *end = NULL;
        solve(root,prev,first,end);
        swap(first -> val,end -> val);
    }
};