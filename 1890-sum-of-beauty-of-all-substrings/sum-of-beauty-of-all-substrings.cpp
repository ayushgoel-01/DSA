class Solution {
private:
    int solve(string& s){
        int n = s.size();
        vector<int> v(26,0);

        for(auto i: s) v[i - 'a']++;

        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=0; i<26; i++){
            if(v[i] > maxi){
                maxi = v[i];
            }
            if(v[i] != 0 && v[i] < mini){
                mini = v[i];
            }
        }
        return maxi-mini;
    }
public:
    int beautySum(string s) {
        int n = s.size();

        int sum = 0;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                sum += solve(temp);
            }
        }
        return sum;
    }
};