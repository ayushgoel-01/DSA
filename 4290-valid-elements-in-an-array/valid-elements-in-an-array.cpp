class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {nums[0]};

        vector<int> v(n);
        v[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            v[i] = max(v[i+1],nums[i]);
        }

        vector<int> ans;
        ans.push_back(nums[0]);

        int val = nums[0];
        for(int i=1; i<n-1; i++){
            if(nums[i] > val || nums[i] > v[i+1]) ans.push_back(nums[i]);
            val = max(val,nums[i]);
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};