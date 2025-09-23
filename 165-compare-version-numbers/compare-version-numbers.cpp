class Solution {
private:
    void fillVector(vector<string>& v, string& s){
        int n = s.size();
        string temp = "";
        for(int i=0; i<n; i++){
            if(s[i] == '.'){
                v.push_back(temp);
                temp = "";
            }
            else temp += s[i];
        }
        v.push_back(temp);
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        fillVector(v1,version1);
        fillVector(v2,version2);

        int n = v1.size(), m = v2.size();
        int i = 0;
        while(i < n || i < m){
            int a = (i < n) ? stoi(v1[i]) : 0;
            int b = (i < m) ? stoi(v2[i]) : 0;

            if(a < b) return -1;
            else if(a > b) return 1;
            else i++;
        }
        return 0;
    }
};