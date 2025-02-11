class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();

        while(true){
            int n = s.size();
            int i = 0;
            string temp = "";
            bool got = false;

            while(i < n){
                if(!got && s.substr(i,m) == part){
                    i += m;
                    got = true;
                }
                else temp += s[i++];
            }
            s = temp;
            if(!got) break;

        }
        return s;
    }
};