class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = 0, i = 0, j = n-1;
        while(i < j){
            int val = (j-i) * min(height[i],height[j]);
            ans = max(ans,val);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }
};