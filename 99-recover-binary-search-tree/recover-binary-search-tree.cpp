class Solution {
private:
    void findInorder(TreeNode* root, vector<int>& v){
        if(!root) return;

        findInorder(root -> left,v);
        v.push_back(root -> val);
        findInorder(root -> right,v);
    }

    void solve(TreeNode* root, vector<int>& v, int& i){
        if(!root || i >= v.size()) return;

        solve(root -> left,v,i);
        if(root -> val != v[i]){
            root -> val = v[i];
        }
        i++;
        solve(root -> right,v,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> v;

        findInorder(root,v);
        sort(v.begin(),v.end());
        int idx = 0;
        solve(root,v,idx);
    }
};