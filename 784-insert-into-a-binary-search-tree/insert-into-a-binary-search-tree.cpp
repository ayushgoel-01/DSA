class Solution {
private:
    TreeNode* solve(TreeNode* root, int val){
        if(!root){
            root = new TreeNode(val);
            return root;
        }

        if(root -> val > val){
            root -> left = solve(root -> left,val);
        }
        else root -> right = solve(root -> right,val);

        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};