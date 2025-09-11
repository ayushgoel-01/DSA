class Solution {
private:
    int solve(TreeNode* root, bool pick, map<pair<TreeNode*,int>,int>& dp){
        if(!root) return 0;

        if(dp.find({root,pick}) != dp.end()) return dp[{root,pick}];

        int take = 0;
        if(pick) take = root -> val + solve(root -> left,false,dp) + solve(root -> right,false,dp);
        int notTake = solve(root -> left,true,dp) + solve(root -> right,true,dp);

        return dp[{root,pick}] = max(take,notTake);
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>,int> dp;
        return solve(root,true,dp);
    }
};