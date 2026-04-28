class Solution {
private:
    int solve(vector<int>& piles, int mid){
        int n = piles.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            if(piles[i] <= mid) cnt++;
            else{
                cnt += ceil((double)piles[i]/mid);
            }
        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1;
        long long end = accumulate(piles.begin(),piles.end(),0LL);
        int ans = 0;

        while(start <= end){
            long long mid = start + (end-start)/2;
            if(solve(piles,mid) <= h){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};