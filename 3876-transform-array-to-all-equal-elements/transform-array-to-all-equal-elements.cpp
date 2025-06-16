class Solution {
private:
    bool solve(vector<int> nums, int k, int n, int val){
        int i=0;
        while(i < n && nums[i] == val) i++;

        while(i+1 < n){
            if(nums[i] != val){
                nums[i] *= -1;
                nums[i+1] *= -1;
                k--;
                if(k < 0) return false;
            }
            i++;
        }

        int sum = accumulate(nums.begin(),nums.end(),0);
        cout<<sum<<" ";
        return sum == val * n;
    }
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums,k,n,1) || solve(nums,k,n,-1); 
    }
};