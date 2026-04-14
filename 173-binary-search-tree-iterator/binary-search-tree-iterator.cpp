class BSTIterator {
public:
    vector<int> v;
    int ptr = 0;

    void solve(TreeNode* root, vector<int>& v){
        if(!root) return;

        solve(root -> left,v);
        v.push_back(root -> val);
        solve(root -> right,v);
    }

    BSTIterator(TreeNode* root) {
        solve(root,v);
    }
    
    int next() {
        return v[ptr++];
    }
    
    bool hasNext() {
        if(ptr < v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */