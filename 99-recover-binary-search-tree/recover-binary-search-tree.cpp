class Solution {
private:
    void solve(TreeNode* root, vector<int>& v){
        if(!root) return;

        solve(root -> left,v);
        v.push_back(root -> val);
        solve(root -> right,v);
    }
    void check(TreeNode* root, int& idx, vector<int>& v, int n){
        if(!root) return;

        check(root -> left,idx,v,n);
        root -> val = v[idx++];
        check(root -> right,idx,v,n);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> v;
        solve(root,v);

        int n = v.size();
        sort(v.begin(),v.end());
        int idx = 0;

        check(root,idx,v,n);
    }
};