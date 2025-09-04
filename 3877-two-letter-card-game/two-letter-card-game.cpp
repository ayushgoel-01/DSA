class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = cards.size();

        vector<int> first(10,0), second(10,0);
        int both = 0, totalFirst = 0, totalSecond = 0, maxFirst = 0, maxSecond = 0;

        for(auto it: cards){
            // Case 1 : XX
            if(it[0] == it[1] && it[0] == x) both++;
            // Case 2 : X?
            else if(it[0] == x){
                int idx = it[1] - 'a';
                second[idx]++;
                totalSecond++;
                maxSecond = max(maxSecond,second[idx]);
            }
            // Case 3 : ?X
            else if(it[1] == x){
                int idx = it[0] - 'a';
                first[idx]++;
                totalFirst++;
                maxFirst = max(maxFirst,first[idx]);
            }
        }

        // Ans from Case 2 & Case 3
        int ans = min(totalFirst/2, totalFirst-maxFirst) + min(totalSecond/2, totalSecond-maxSecond);

        // Check all the Combinations of dividing XX string with others
        for(int i=0; i<=both; i++){
            int firstContri = i;
            int secondContri = both-i;

            int newTotalFirst = totalFirst + firstContri;
            int newMaxFirst = max(maxFirst,firstContri);

            int newTotalSecond = totalSecond + secondContri;
            int newMaxSecond = max(maxSecond,secondContri);

            int newFirstGroup = min(newTotalFirst/2, newTotalFirst-newMaxFirst);
            int newSecondGroup = min(newTotalSecond/2, newTotalSecond-newMaxSecond);

            ans = max(ans,newFirstGroup + newSecondGroup);
        }
        return ans;
    }
};