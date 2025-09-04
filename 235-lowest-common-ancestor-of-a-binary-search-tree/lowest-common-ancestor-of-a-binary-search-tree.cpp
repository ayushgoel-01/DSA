class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root -> val == p -> val || root -> val == q -> val) return root;

        auto left = solve(root -> left,p,q);
        auto right = solve(root -> right,p,q);

        if(left && right) return root;
        else if(left && !right) return left;
        else return right;

        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};