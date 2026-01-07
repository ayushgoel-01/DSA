class Solution {
int mod = 1e9 + 7;
private:
    int findSum(TreeNode* root){
        if(!root) return 0;

        int left = findSum(root -> left);
        int right = findSum(root -> right);

        return left + root -> val + right;
    }

    int solve(TreeNode* root, int totalSum, long long& ans){
        if(!root) return 0;

        int left = solve(root -> left,totalSum,ans);
        int right = solve(root -> right,totalSum,ans);

        long long sum1 = left + root -> val + right;
        long long sum2 = totalSum - sum1;

        ans = max(ans,(long long)sum1 * sum2);

        return left + root -> val + right;
    }
public:
    int maxProduct(TreeNode* root) {
        long long totalSum = findSum(root);
        long long ans = 0;
        solve(root,totalSum,ans);
        return ans % mod;
    }
};