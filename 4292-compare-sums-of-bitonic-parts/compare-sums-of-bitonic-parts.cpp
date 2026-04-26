class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        long long sum1 = nums[0], sum2 = nums[n-1];
        int i = 1;
        while(i < n && nums[i] > nums[i-1]){
            sum1 += nums[i];
            i++;
        }
        i = n-2;
        while(i >= 0 && nums[i] > nums[i+1]){
            sum2 += nums[i];
            i--;
        }

        if(sum1 > sum2) return 0;
        return (sum1 < sum2) ? 1 : -1;
    }
};