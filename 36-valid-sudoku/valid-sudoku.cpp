class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
            
                string row = to_string(i) + "row" + board[i][j];
                string col = to_string(j) + "col" + board[i][j];
                string box = to_string(i/3) + to_string(j/3) + "box" + board[i][j];

                if(st.count(row) >= 1 || st.count(col) >= 1 || st.count(box) >= 1) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};