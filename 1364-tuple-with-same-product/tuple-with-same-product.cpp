class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                if(i == j) continue;

                int k = i+1, l = j-1;
                if(i == k || j == k) k++;
                if(i == l || j == l) l--;

                while(k < l){
                    long long a = nums[i] * nums[j];
                    long long b = nums[k] * nums[l];

                    if(a == b){
                        ans++;
                        k++;
                    }
                    else if(a > b) k++;
                    else l--;
                }
            }
        }
        return ans * 8;
    }
};