class Solution {
public:
    int n;
    int MOD = 1000000007;
    vector<vector<int>> dp;
    int solve(int pos, int rem){
        if(rem == 0 && pos == 0){
            return 1;
        } 
        else if(rem == 0) return 0;
        if(dp[pos][rem] != -1) return dp[pos][rem]; 
        dp[pos][rem] = 0;
        if(pos < n - 1) dp[pos][rem] += (dp[pos][rem] + solve(pos + 1, rem - 1)) % MOD;
        if(pos > 0) dp[pos][rem] = (dp[pos][rem] + solve(pos - 1, rem - 1)) % MOD;
        dp[pos][rem] = (dp[pos][rem] + solve(pos, rem - 1)) % MOD;
        return dp[pos][rem];
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        dp = vector(arrLen, vector<int>(steps + 1, -1));
        n = arrLen;
        return solve(0, steps);
    }
};