class Solution {
#define ll long long
private:
    ll solve(vector<int>& nums1, vector<int>& nums2, ll p, int n, int m){
        ll finalCnt = 0;

        for(int i=0; i<n; i++){

            if(nums1[i] >= 0){
                int start = 0, end = m-1, cnt = -1;

                while(start <= end){
                    int mid = start + (end - start) / 2;

                    ll currp = 1LL * nums1[i] * nums2[mid];

                    if(currp <= p){
                        cnt = mid;
                        start = mid+1;
                    }
                    else end = mid-1;
                } 
                finalCnt += cnt+1;
            }
            else{
                int start = 0, end = m-1, cnt = m;

                while(start <= end){
                    int mid = start + (end - start) / 2;

                    ll currp = 1LL * nums1[i] * nums2[mid];

                    if(currp <= p){
                        cnt = mid;
                        end = mid-1;
                    }
                    else start = mid+1;
                }
                finalCnt += m-cnt;
            }
        }
        return finalCnt;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        int m = nums2.size();

        ll start = -1e10, end = 1e10, ans = 0;

        while(start <= end){
            ll mid = start + (end - start)/2;
            ll count = solve(nums1,nums2,mid,n,m);

            if(count >= k){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};