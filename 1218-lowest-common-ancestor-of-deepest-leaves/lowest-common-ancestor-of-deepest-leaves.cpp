class Solution {
private:
    pair<int,TreeNode*> solve(TreeNode* root){
        if(!root) return {0,root};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        if(left.first == right.first){
            return {left.first+1,root};         // Pair of depth & LCA
        }
        else if(left.first > right.first){
            return {left.first+1,left.second};
        }
        else return {right.first+1,right.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};