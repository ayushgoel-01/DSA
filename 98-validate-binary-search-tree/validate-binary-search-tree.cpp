class Solution {
private:
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root -> val <= mini || root -> val >= maxi) return false;

        bool left = solve(root -> left,mini,root -> val);
        bool right = solve(root -> right,root -> val,maxi);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;  

        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};