class Solution {
public:
    
    int solve(vector<int> &cost, int cur, vector<int> &dp){
        if(cur >= cost.size()) return 0;
        if(dp[cur]!=-1) return dp[cur];
        dp[cur] = cost[cur] + min(solve(cost, cur+1, dp), solve(cost, cur+2, dp));
        return dp[cur];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};