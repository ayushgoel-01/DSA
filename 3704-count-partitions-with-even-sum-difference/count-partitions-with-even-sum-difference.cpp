class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        v[0] = nums[0];

        for(int i=1; i<n; i++){
            v[i] = v[i-1] + nums[i];
        }

        int ans = 0, sum = 0;
        for(int i=n-1; i>0; i--){
            sum += nums[i];
            if(abs(v[i-1]-sum) % 2 == 0) ans++;
        }
        return ans;
    }
};