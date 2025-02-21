/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    void solve(TreeNode* root, int val, unordered_set<int>& st){
        if(!root) return;

        if(root -> left){
            st.insert(2*val+1);
            solve(root -> left,2*val+1,st);
        }
        if(root -> right){
            st.insert(2*val+2);
            solve(root -> right,2*val+2,st);
        }
    }
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        solve(root,0,st);
    }
    
    bool find(int target) {
        if(target == 0 || st.count(target) >= 1) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */