class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0LL);

        // Equation :- F(k+1) = F(k) + sum - n * nums[n-k-1]

        int prev = 0, ans = INT_MIN;
        for(int i=0; i<n; i++){
            prev += i * nums[i];
        }
        ans = max(ans,prev);
        for(int i=n-1; i>=1; i--){
            int curr = prev + sum - n*nums[i];
            ans = max(ans,curr);
            prev = curr;
        }
        return ans;
    }
};