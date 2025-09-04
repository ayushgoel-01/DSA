class Solution {
private:
    void solve(TreeNode* root, int& k, int& ans){
        if(!root) return;

        solve(root -> left,k,ans);
        k--;
        if(k == 0){
            ans = root -> val;
            return;
        }
        solve(root -> right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root,k,ans);

        return ans;
    }
};