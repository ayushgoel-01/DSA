class Solution {
private:
    bool isPalindrome(string& s){
        int n = s.size();
        int start = 0, end = n-1;

        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    string findBaseK(long long num, int k){
        if(num == 0) return "0";

        string ans = "";
        while(num){
            ans += to_string(num % k);
            num = num / k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    long long kMirror(int k, int n) {
        long long sum = 0;

        int l = 1;
        while(n > 0){
            int half = (l+1)/2;

            long long start = pow(10,half-1);
            long long end = pow(10,half)-1;

            for(int num=start; num<=end; num++){
                string first = to_string(num);
                string second = first;
                reverse(second.begin(),second.end());

                string pal = "";
                if(l%2 == 0){
                    pal = first + second;
                }
                else{
                    pal = first + second.substr(1);
                }

                long long palNum = stoll(pal);

                string baseK = findBaseK(palNum,k);

                if(isPalindrome(baseK)){
                    sum += palNum;
                    n--;
                    if(n <= 0) break;
                }
            }
            l++;
        }
        return sum;
    }
};