class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        for(int i=1; i<n; i++){
            prefMax[i] = max(prefMax[i-1],nums[i]);
        }

        suffMin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffMin[i] = min(suffMin[i+1],nums[i]);
        }

        vector<int> ans(n);
        ans[n-1] = prefMax[n-1];
        for(int i=n-2; i>=0; i--){
            if(prefMax[i] <= suffMin[i+1]){         // We can't go in right region
                ans[i] = prefMax[i];
            }
            else{       // As we can go on right section, so for all elements in right section, we  already stored optimal max ans in ans[i+1] index
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
};