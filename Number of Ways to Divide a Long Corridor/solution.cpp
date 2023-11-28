class Solution {
public:
    int numberOfWays(string corridor) {
        int cnt_s = 0, n = corridor.size(), MOD = 1000000007;
        long long ans = 1;
        for(int i=0; i<n; i++){
            if(corridor[i] == 'S'){
                cnt_s++;
                if(cnt_s % 2 == 0){
                    int j = 1;
                    while(i+j<n && corridor[i+j] == 'P') j++;
                    if(i+j < n-1){
                        ans *= j;
                        ans %= MOD;
                    }
                    i = i+j-1;
                }
            }
        }
        if(cnt_s == 0 || cnt_s % 2 != 0) return 0;
        return ans;
    }
};