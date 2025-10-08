class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int start = 0, end = m-1, idx = m;
            while(start <= end){
                int mid = start + (end - start)/2;
                long long val = potions[mid];
                val *= spells[i] * 1LL;

                if(val >= success){
                    idx = mid;
                    end = mid-1;
                }
                else start = mid+1;
            }
            ans[i] = m - idx;
        }
        return ans;
    }
};