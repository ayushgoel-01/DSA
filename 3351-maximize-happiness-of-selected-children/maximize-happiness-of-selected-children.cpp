class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.rbegin(),happiness.rend());

        long long ans = 0, cnt = 0;
        for(int i=0; i<k; i++){
            if(i < k){
                happiness[i] -= cnt;
                cnt++;
            }
            else{
                happiness[i] -= k;
            }
            if(happiness[i] <= 0) happiness[i] = 0;
        }

        for(int i=0; i<k; i++){
            ans += happiness[i];
        }
        return ans;
    }
};