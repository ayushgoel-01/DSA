class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long currSum = accumulate(nums.begin(),nums.end(),0LL);
        long long sum = n * (n+1)/2;

        return sum - currSum;
    }
};