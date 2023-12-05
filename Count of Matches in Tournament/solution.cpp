class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        int temp = n;
        while(temp>1){
            ans += temp/2;
            temp = temp/2 + temp%2;
        }
        return ans;
    }
};