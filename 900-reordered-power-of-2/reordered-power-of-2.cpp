class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> v;
        long long num = 1;
        while(num < 1e9){
            v.push_back(to_string(num));
            num = num * 2;
        }

        string temp = to_string(n);
        sort(temp.begin(),temp.end());

        for(auto& i: v){
            sort(i.begin(),i.end());
            if(i == temp) return true;
        }
        return false;
    }
};