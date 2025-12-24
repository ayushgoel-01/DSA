class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();

        int total = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());

        int i = 0, sum = 0;
        for(i=0; i<n; i++){
            sum += capacity[i];
            if(sum >= total) break;
        }
        return i+1;
    }
};