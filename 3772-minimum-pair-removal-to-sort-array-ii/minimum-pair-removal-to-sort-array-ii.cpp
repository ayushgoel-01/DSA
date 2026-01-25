class Solution {
#define ll long long
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<ll> v(nums.begin(),nums.end());          // To Avoid overflow, Create ll Copy

        vector<int> prevIdx(n), nextIdx(n);
        for(int i=0; i<n; i++){
            prevIdx[i] = i-1;
            nextIdx[i] = i+1;
        }

        int badPairs = 0;
        set<pair<ll,int>> st;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                badPairs++;
            }
            st.insert({nums[i]+nums[i+1],i});
        }

        int ans = 0;
        while(badPairs > 0){
            int first = st.begin() -> second;
            int second = nextIdx[first];

            int firstLeft = prevIdx[first];
            int secondRight = nextIdx[second];

            st.erase(st.begin());

            if(v[first] > v[second]) badPairs--;

            if(firstLeft >= 0){
                if(v[firstLeft] <= v[first] && v[firstLeft] > v[first] + v[second]) badPairs++;
                else if(v[firstLeft] > v[first] && v[firstLeft] <= v[first] + v[second]) badPairs--;
            }
            if(secondRight < n){
                if(v[second] <= v[secondRight] && v[first] + v[second] > v[secondRight]) badPairs++;
                else if(v[second] > v[secondRight] && v[first] + v[second] <= v[secondRight]) badPairs--;
            }

            if(firstLeft >= 0){
                st.erase({v[firstLeft] + v[first], firstLeft});
                st.insert({v[firstLeft] + v[first] + v[second], firstLeft});
            }
            if(secondRight < n){
                st.erase({v[second] + v[secondRight], second});
                st.insert({v[first] + v[second] + v[secondRight], first});

                prevIdx[secondRight] = first;
            }

            nextIdx[first] = secondRight;
            v[first] += v[second];
            ans++;
        }
        return ans;
    }
};