class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<bool> freq(101,false);
        vector<int> ans;
        
        for(auto i: nums){
            if(freq[i]){
                ans.push_back(i);
            }
            freq[i] = true;
        }
        return ans;
    }
};