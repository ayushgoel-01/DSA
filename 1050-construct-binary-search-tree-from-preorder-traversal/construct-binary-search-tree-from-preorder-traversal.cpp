class Solution {
private:
    int findIdx(vector<int>& v, int val, int n){
        for(int i=0; i<n; i++){
            if(v[i] == val) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& pre, vector<int>& in, int& preIdx, int start, int end, int n){
        if(preIdx >= n || start > end){
            return NULL;
        }

        int el = pre[preIdx++];
        TreeNode* node = new TreeNode(el);
        int idx = findIdx(in,el,n);

        node -> left = solve(pre,in,preIdx,start,idx-1,n);
        node -> right = solve(pre,in,preIdx,idx+1,end,n);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());

        int preIdx = 0;
        return solve(preorder,inorder,preIdx,0,n-1,n);
    }
};