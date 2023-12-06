class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int w = n / 7;
        n %= 7;
        ans += (28 + n)*w + 7*(w *(w - 1))/2 + (n *(n + 1))/2;
        return ans;
    }
};