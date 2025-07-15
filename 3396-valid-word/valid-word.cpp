class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3) return false;

        bool f1 = false, f2 = false;
        for(auto i: word){
            if(isdigit(i)) continue;
            if(!(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z') && !(i >= '0' && i <= '9')){
                return false;
            }
            else{
                if(isVowel(i)) f1 = true;
                else f2= true;
            }
        }
        return f1 && f2;
    }
};