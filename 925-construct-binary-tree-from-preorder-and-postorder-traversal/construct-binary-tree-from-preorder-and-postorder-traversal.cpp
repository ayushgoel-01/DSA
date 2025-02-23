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
class Solution {
int preIdx = 0, postIdx = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr = new TreeNode(preorder[preIdx]);
        preIdx++;

        if(curr -> val != postorder[postIdx]){
            curr -> left = constructFromPrePost(preorder,postorder);
        }
        if(curr -> val != postorder[postIdx]){
            curr -> right = constructFromPrePost(preorder,postorder);
        }

        postIdx++;
        return curr;
    }
};