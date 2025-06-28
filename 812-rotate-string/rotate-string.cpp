class Solution {
private:
    bool solve(int idx, string& s, string& goal, int n, int m){
        int i = idx, j = 0;
        while(i < n && j < m){
            if(s[i] != goal[j]) return false;
            i++; j++;
        }

        if(j != m) i = 0;
        while(i < n && j < m){
            if(s[i] != goal[j]) return false;
            i++; j++;
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n != m) return false;

        for(int i=0; i<n; i++){
            if(s[i] == goal[0] && solve(i,s,goal,n,m)) return true;
        }

        return false;
    }
};