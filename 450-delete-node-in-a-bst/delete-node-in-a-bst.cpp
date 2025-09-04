class Solution {
private:
    int findMin(TreeNode* root){
        while(root -> left){
            root = root -> left;
        }
        return root -> val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root -> val == key){
            if(!root -> left && !root -> right){
                delete root;
                return NULL;
            }
            else if(!root -> left && root -> right){
                auto temp = root -> right;
                delete root;
                return temp;
            }
            else if(root -> left && !root -> right){
                auto temp = root -> left;
                delete root;
                return temp;
            }
            else{
                int mini = findMin(root -> right);
                root -> val = mini;

                root -> right = deleteNode(root -> right,mini);
                return root;
            }
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left,key);
            return root;
        }
        else{
            root -> right = deleteNode(root -> right,key);
            return root;
        }
        return root;
    }
};