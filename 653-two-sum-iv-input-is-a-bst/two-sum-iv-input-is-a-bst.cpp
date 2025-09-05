class Solution {
private:
    bool solve(TreeNode* root, unordered_set<int>& st, int k){
        if(!root) return false;

        if(st.find(k - root -> val) != st.end()) return true;
        st.insert(root -> val);

        return solve(root -> left,st,k) || solve(root -> right,st,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return solve(root,st,k);
    }
};