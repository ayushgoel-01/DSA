class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int size1 = hBars.size();
        int size2 = vBars.size();

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxH = 1, maxV = 1;

        int curr = 1;
        for(int i=1; i<size1; i++){
            if(hBars[i] == hBars[i-1] + 1){
                curr++;
                maxH = max(maxH,curr);
            }
            else curr = 1;
        }

        curr = 1;
        for(int i=1; i<size2; i++){
            if(vBars[i] == vBars[i-1] + 1){
                curr++;
                maxV = max(maxV,curr);
            }
            else curr = 1;
        }

        int val = min(maxH,maxV) + 1;
        return val * val;
    }
};