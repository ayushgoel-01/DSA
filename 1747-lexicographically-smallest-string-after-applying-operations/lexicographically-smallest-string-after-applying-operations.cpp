class Solution {
private:
    void rotate(string& s, int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();

        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vis.insert(s);

        string ans = s;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans = min(ans,curr);

            string temp = curr;
            for(int i=1; i<n; i+=2){
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(vis.count(temp) <= 0){
                vis.insert(temp);
                q.push(temp);
            }

            rotate(curr,b);
            if(vis.count(curr) <= 0){
                vis.insert(curr);
                q.push(curr);
            }
        }
        return ans;
    }
};