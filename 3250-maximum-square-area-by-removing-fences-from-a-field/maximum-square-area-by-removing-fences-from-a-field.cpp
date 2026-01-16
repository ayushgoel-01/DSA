class Solution {
int mod = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<int> st1, st2;

        for(int i=0; i<hFences.size(); i++){ 
            for(int j=i+1; j<hFences.size(); j++){
                int diff = hFences[j] - hFences[i];
                st1.insert(diff);
            }
        }

        int maxSide = 0;

        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                int diff = vFences[j] - vFences[i];

                if(st1.count(diff) >= 1) maxSide = max(maxSide,diff);
            }
        }
        return (maxSide == 0) ? -1 : (maxSide * 1LL * maxSide) % mod;
    }
};