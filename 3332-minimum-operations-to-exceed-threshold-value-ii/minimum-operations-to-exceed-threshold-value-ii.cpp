class Solution {
#define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq(nums.begin(),nums.end());

        int cnt = 0;
        while(pq.size() >= 2 && pq.top() < k){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();

            ll val = min(x,y) * 1LL * 2 + max(x,y);
            pq.push(val);
            cnt++;
        }
        return cnt;
    }
};