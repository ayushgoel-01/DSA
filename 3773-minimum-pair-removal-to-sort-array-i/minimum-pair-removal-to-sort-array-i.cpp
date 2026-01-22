class Solution {
private:
    bool solve(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(solve(nums)) return cnt;

            vector<int> v;
            int mini = INT_MAX, idx = 0;
            for(int j=0; j<nums.size()-1; j++){
                if(nums[j] + nums[j+1] < mini){
                    mini = nums[j] + nums[j+1];
                    idx = j;
                }
            }
            
            for(int j=0; j<nums.size(); j++){
                if(j == idx){
                    v.push_back(mini);
                }
                else if(j == idx+1) continue;
                else v.push_back(nums[j]);
            }
            nums = v;
            cnt++;
        }
        return cnt;
    }
};