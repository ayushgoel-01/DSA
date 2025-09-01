class Solution {
private:
    int solve(TreeNode* root, int& sum){
        if(!root) return 1;

        int left = solve(root -> left,sum);
        int right = solve(root -> right,sum);

        if(left == 0 || right == 0){
            sum++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        else return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int sum = 0;
        if(solve(root,sum) == 0) sum++;   // means there is only 1 single node
        return sum;
    }
};

/*  Return Conditions:- 
    0 means -> The node is not monitored
    1 means -> The node don't have camera but it is monitored
    2 means -> The node have camera
*/