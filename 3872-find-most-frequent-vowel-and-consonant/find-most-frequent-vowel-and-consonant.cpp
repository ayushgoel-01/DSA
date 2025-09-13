class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();

        vector<int> freq(26,0);
        for(auto i: s) freq[i-'a']++;

        int maxi1 = 0, maxi2 = 0;
        for(int i=0; i<26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                maxi1 = max(maxi1,freq[i]);
            }
            else maxi2 = max(maxi2,freq[i]);
        }
        return maxi1 + maxi2;
    }
};