class Solution {
private:
    void findDepth(TreeNode* root, int d, unordered_map<TreeNode*,int>& mp, int& maxDepth){
        if(!root) return;

        maxDepth = max(maxDepth,d);
        mp[root] = d;

        findDepth(root -> left,d+1,mp,maxDepth);
        findDepth(root -> right,d+1,mp,maxDepth);
    }

    TreeNode* solve(TreeNode* root, unordered_map<TreeNode*,int>& mp, int maxDepth){
        if(!root) return NULL;

        if(mp[root] == maxDepth) return root;

        auto left = solve(root -> left,mp,maxDepth);
        auto right = solve(root -> right,mp,maxDepth);

        if(left && right) return root;
        if(left) return left;
        return right; 
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        int maxDepth = 0;

        findDepth(root,0,mp,maxDepth);
        return solve(root,mp,maxDepth);
    }
};