class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int i = 0, j = 0, sum = 0;
        unordered_set<int> st;

        while(j < n){
            if(st.count(nums[j]) <= 0){
                st.insert(nums[j]);
                sum += nums[j];
            } 
            else{
                while(st.count(nums[j]) > 0){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                st.insert(nums[j]);
                sum += nums[j];
            }
           maxi = max(maxi,sum);
           j++;
        }
        return maxi;
    }
};