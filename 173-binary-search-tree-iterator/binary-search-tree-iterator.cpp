class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root = root -> left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto temp = st.top();
        st.pop();
        pushAll(temp -> right);
        return temp -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */