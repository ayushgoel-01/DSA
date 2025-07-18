class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;

        vector<long long> leftMinSum(N,0), rightMaxSum(N,0);

        priority_queue<long long> pq;
        long long sum = 0;
        for(int i=0; i<2*n; i++){
            sum += nums[i];
            pq.push(nums[i]);

            if(pq.size() > n){
                sum -= pq.top();
                pq.pop();
            }
            leftMinSum[i] = sum;
        }

        priority_queue<long long,vector<long long>,greater<long long>> pq1;
        sum = 0;
        for(int i=N-1; i>=n; i--){
            sum += nums[i];
            pq1.push(nums[i]);

            if(pq1.size() > n){
                sum -= pq1.top();
                pq1.pop();
            }
            rightMaxSum[i] = sum;
        }

        long long ans = LLONG_MAX;
        for(int i=n-1; i<2*n; i++){
            ans = min(ans,leftMinSum[i]-rightMaxSum[i+1]);
        }
        return ans;
    }
};