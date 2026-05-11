class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(auto i: events){
            if(i == "W") counter++;
            else if(i == "WD" || i == "NB") score++;
            else score += stoi(i);

            if(counter >= 10) break;
        }
        return {score,counter};
    }
};