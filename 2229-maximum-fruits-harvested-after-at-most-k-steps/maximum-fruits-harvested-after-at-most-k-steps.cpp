class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> pref(n,0), pos(n,0);
        for(int i=0; i<n; i++){
            pos[i] = fruits[i][0];
            pref[i] = fruits[i][1] + (i > 0 ? pref[i-1] : 0);
        }

        int maxi = 0;
        for(int d=0; d<=k/2; d++){
            // Case1 - Move left and then right
            int rem = k - 2*d;
            int i = startPos - d;
            int j = startPos + rem;

            int left = lower_bound(pos.begin(),pos.end(),i) - pos.begin();
            int right = upper_bound(pos.begin(),pos.end(),j) - pos.begin()-1;

            if(left <= right){
                int total = pref[right] - (left > 0 ? pref[left-1] : 0);
                maxi = max(maxi,total);
            }

            // Case2 - Move Right and then left
            i = startPos - rem;
            j = startPos + d;

            left = lower_bound(pos.begin(),pos.end(),i) - pos.begin();
            right = upper_bound(pos.begin(),pos.end(),j) - pos.begin()-1;

            if(left <= right){
                int total = pref[right] - (left > 0 ? pref[left-1] : 0);
                maxi = max(maxi,total);
            }
        }
        return maxi;
    }
};