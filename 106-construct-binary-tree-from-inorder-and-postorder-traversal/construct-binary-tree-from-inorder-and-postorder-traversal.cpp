class Solution {
private:
    int findPos(vector<int>& arr, int el, int n){
        for(int i=0; i<n; i++){
            if(arr[i] == el) return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& post, vector<int>& in, int& postIdx, int start, int end, int n){
        if(postIdx < 0 || start > end) return NULL;

        int element = post[postIdx--];
        TreeNode* root = new TreeNode(element);
        int pos = findPos(in,element,n);

        root -> right =  solve(post,in,postIdx,pos+1,end,n);
        root -> left = solve(post,in,postIdx,start,pos-1,n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return solve(postorder,inorder,idx,0,n-1,n);
    }
};