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
public:
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN, ans = 1;
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 1;
        while(!q.empty()){
            int size = q.size();
            int currSum = 0;

            while(size--){
                auto node = q.front();
                q.pop();

                currSum += node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            if(currSum > maxi){
                maxi = currSum;
                ans = lvl;
            }
            lvl++;
        }
        return ans;
    }
};