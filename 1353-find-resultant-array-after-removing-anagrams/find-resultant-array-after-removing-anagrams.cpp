class Solution {
private:
    bool solve(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a == b;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        int j = n-1;
        while(j >= 1){
            if(solve(words[j],words[j-1])) words[j] = "-1";
            else j--;
        }

        vector<string> ans;
        for(auto i: words){
            if(i != "-1") ans.push_back(i);
        }
        return ans;
    }
};