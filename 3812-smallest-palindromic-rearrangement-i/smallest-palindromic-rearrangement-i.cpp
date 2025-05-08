class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(auto i: s) mp[i]++;

        string ans = "", temp = "";
        char ch = '#';

        for(auto it: mp){
            if(it.second % 2 == 1) ch = it.first;
        }

        for(auto it: mp){
            char ch = it.first;
            int f = it.second;
            if(f % 2 == 0){
                ans += string(f/2,ch);
                temp += string(f/2,ch);
            }
            else{
                ans += string(f/2,ch);
                temp += string(f/2,ch);
            }
        }

        if(ch != '#') ans += ch;
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};