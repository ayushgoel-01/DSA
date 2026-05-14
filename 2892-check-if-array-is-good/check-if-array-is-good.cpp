class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int> v(201,0);
        for(auto i: nums){
            v[i]++;
            if(i != maxi && v[i] >= 2) return false;
        }
        for(int i=maxi; i>=1; i--){
            if(i == maxi){
                if(v[i] != 2) return false;
            }
            else if(v[i] != 1) return false;
        }
        return true;
    }
};