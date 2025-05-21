class Solution {
private:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> v = nums;
        auto cmp = [&](int x, int y){
            int sum1 = getSum(x);
            int sum2 = getSum(y);
            if(sum1 == sum2) return x < y;
            return sum1 < sum2;
        };
        sort(v.begin(),v.end(),cmp);

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        vector<bool> vis(n,false);
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(vis[i] || v[i] == nums[i]) continue;

            int cnt = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = mp[v[j]];
                cnt++;
            }
            ans += cnt-1;
        }
        return ans;
    }
};