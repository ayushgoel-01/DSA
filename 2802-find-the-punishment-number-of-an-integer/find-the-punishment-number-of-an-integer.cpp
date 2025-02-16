class Solution {
private:
    bool solve(int i, int currSum, string s, int num){
        if(i >= s.size()) return currSum == num;

        if(currSum > num) return false;

        bool ans = false;

        for(int j=i; j<s.size(); j++){
            string sub = s.substr(i,j-i+1);
            int val = stoi(sub);

            ans = ans || solve(j+1,currSum+val,s,num);
            if(ans == true) return ans;
        }
        return ans;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++){
            int sq = i * i;
            string s = to_string(sq);

            if(solve(0,0,s,i)) ans += sq;
        }
        return ans;
    }
};