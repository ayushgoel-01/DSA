class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        int i = startIndex, j = startIndex;
        int cnt1 = 0, cnt2 = 0;
        while(words[i] != target || words[j] != target){
            if(words[i] != target){
                cnt1++;
                i = (i-1+n)%n;
            }
            if(words[j] != target){
                cnt2++;
                j = (j+1)%n;
            }

            if(i == j) break;
        }
        if(words[i] == target && words[j] == target) return min(cnt1,cnt2);
        return -1;
    }
};