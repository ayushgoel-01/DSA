class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int mini = max(0,n-2*limit); // Assing other 2 children limit candies, so remaining = n-2*limit
        int maxi = min(n,limit);

        long long ans = 0;
        for(int i=mini; i<=maxi; i++){
            int N = n - i;          // Updated candies that are left

            int minch2 = max(0,N-limit);
            int maxch2 = min(N,limit);
            ans += (maxch2-minch2+1);
        }
        return ans;
    }
};