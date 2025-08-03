class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();

        int ans = 0, maxi = weight[0];
        for(int i=1; i<n; i++){
            maxi = max(maxi,weight[i]);
            if(weight[i] < maxi){
                ans++;
                maxi = 0;
            }
        }
        return ans;
    }
};