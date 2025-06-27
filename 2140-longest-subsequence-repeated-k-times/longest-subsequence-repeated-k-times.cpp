class Solution {
private:
    bool isSubsequence(string& s, string curr, int k){
        int i=0, j=0;
        int n = s.size();
        int m = curr.size();

        while(i < n && j < k*m){
            if(s[i] == curr[j%m]){
                j++;
            }
            i++;
        }
        return j >= k*m;
    }

    void solve(string& s, string curr, string& ans, vector<bool>& canUse, vector<int>& reqFreq, int k, int maxLen){
        if(curr.size() > maxLen) return;

        if((curr.size() > ans.size() || (curr.size() == ans.size() && curr > ans))
         && isSubsequence(s,curr,k)){
            ans = curr;
        }

        for(int i=0; i<26; i++){
            if(canUse[i] == false || reqFreq[i] == 0) continue;

            curr += 'a' + i;
            reqFreq[i]--;

            solve(s,curr,ans,canUse,reqFreq,k,maxLen);

            curr.pop_back();
            reqFreq[i]++;
        }
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();

        vector<int> freq(26,0);
        for(auto i: s){
            freq[i-'a']++;
        }

        vector<bool> canUse(26,false);
        vector<int> reqFreq(26,0);

        for(int i=0; i<26; i++){
            if(freq[i] >= k){
                canUse[i] = true;
                reqFreq[i] = freq[i]/k;
            }
        }

        int maxLen = n/k;

        string curr = "", ans = "";
        solve(s,curr,ans,canUse,reqFreq,k,maxLen);

        return ans;
    }
};