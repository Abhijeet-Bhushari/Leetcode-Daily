class Solution {
public:
    int kthGrammar(int n, int k) {
        int row = 1, cur = 0, con_rate = pow(2, n - 1), chosen;
        for(int i=1; i<n; i++){
            row = i;
            con_rate /= 2;
            chosen = k - con_rate > 0? 1:0;
            cur = chosen == 0?(cur == 0? 0:1):(cur == 1? 0:1);
            chosen == 1? k -= con_rate : k = k;
        }
        return cur;
    }
};