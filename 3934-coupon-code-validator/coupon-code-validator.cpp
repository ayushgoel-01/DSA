class Solution {
private:
    bool isValidChar(char c){
        return (isalnum(c)) || (c == '_');
    }

    bool valid(string& code, string& bl){
        int n = code.size();
        for(int i=0; i<n; i++){
            if(!isValidChar(code[i])) return false;
        }

        return bl == "electronics" || bl == "grocery" || bl == "pharmacy" || bl == "restaurant";
    }

    int category(string& s){
        if(s == "electronics") return 1;
        else if(s == "grocery") return 2;
        else if(s == "pharmacy") return 3;
        return 4;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int,string>> v;

        for(int i=0; i<n; i++){
            if(isActive[i] && !code[i].empty() && valid(code[i],businessLine[i])){
                v.push_back({category(businessLine[i]),code[i]});
            }
        }

        sort(v.begin(),v.end());
        
        vector<string> ans;
        for(auto it: v) ans.push_back(it.second);
        return ans;
    }
};