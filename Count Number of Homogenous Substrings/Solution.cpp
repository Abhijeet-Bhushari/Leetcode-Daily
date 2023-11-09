class Solution {
public:
    int countHomogenous(string s) {
        long long cnt = 1;
        long long res = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i-1] == s[i]){
                cnt++;
            }
            else{
                res += (cnt*(cnt+1))/2;
                res %= 1000000007;
                cnt = 1;
            }
        }
        res += (cnt*(cnt+1))/2;
        res %= 1000000007;
        return res;
    }
};