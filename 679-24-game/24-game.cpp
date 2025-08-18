class Solution {
private:
    vector<double> getOperations(double a, double b){
        vector<double> v;
        v.push_back(a + b);
        v.push_back(a - b);
        v.push_back(b - a);
        v.push_back(a * b);
        v.push_back(a / b);
        v.push_back(b / a);

        return v;
    }

    bool solve(vector<double>& cards){
        int n = cards.size();

        if(n == 1){
            return fabs(cards[0] - 24.0) < 1e-6;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;

                vector<double> next;
                for(int k=0; k<n; k++){
                    if(k != i && k != j) next.push_back(cards[k]);
                }

                for(auto it: getOperations(cards[i],cards[j])){
                    next.push_back(it);
                    if(solve(next)) return true;
                    next.pop_back();            // Backtrack
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(),cards.end());
        return solve(nums);
    }
};