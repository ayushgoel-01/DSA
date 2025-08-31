class Solution {
private:
    int findPos(vector<int>& arr, int el, int n){
        for(int i=0; i<n; i++){
            if(arr[i] == el) return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int& preIdx, int start, int end, int n){
        if(preIdx >= n || start > end) return NULL;

        int element = pre[preIdx++];
        TreeNode* root = new TreeNode(element);
        int pos = findPos(in,element,n);

        root -> left = solve(pre,in,preIdx,start,pos-1,n);
        root -> right =  solve(pre,in,preIdx,pos+1,end,n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIdx = 0;
        return solve(preorder,inorder,preIdx,0,n-1,n);
    }
};