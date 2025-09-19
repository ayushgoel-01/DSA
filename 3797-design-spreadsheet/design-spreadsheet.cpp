class Spreadsheet {
private:
    bool containsChar(string& s, int idx){
        int n = s.size();
        for(int i=idx; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9') continue;
            else return true;
        }
        return false;
    }
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
      grid = vector<vector<int>>(rows+1, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string s1 = formula.substr(0,idx);
        string s2 = formula.substr(idx+1);

        bool f1 = containsChar(s1,1);
        bool f2 = containsChar(s2,0);

        if(!f1 && !f2){
            int num1 = stoi(s1.substr(1));
            int num2 = stoi(s2.substr(0));
            return num1 + num2;
        }
        else if(!f1 && f2){
            int num1 = stoi(s1.substr(1));
            int col = s2[0] - 'A';
            int row = stoi(s2.substr(1));
            return num1 + grid[row][col];
        }
        else if(f1 && !f2){
            int num2 = stoi(s2.substr(0));
            int col = s1[1] - 'A';
            int row = stoi(s1.substr(2));
            return num2 + grid[row][col];
        }

        int col1 = s1[1] - 'A';
        int row1 = stoi(s1.substr(2));
        int col2 = s2[0] - 'A';
        int row2 = stoi(s2.substr(1));

        return grid[row1][col1] + grid[row2][col2];
        return 0;
    }
};