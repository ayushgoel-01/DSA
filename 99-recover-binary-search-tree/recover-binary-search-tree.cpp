class Solution {
private:
    void solve(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &last){
        if(!root) return;

        solve(root -> left,prev,first,last);
        
        if(prev && prev -> val > root -> val){
            if(!first) first = prev;
            last = root;
        }
        
        prev = root;
        solve(root -> right,prev,first,last);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *last = NULL;
        solve(root,prev,first,last);

       swap(first -> val,last -> val);
    }
};