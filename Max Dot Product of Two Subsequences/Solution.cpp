class Solution
{
    public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1000000));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int a = dp[i-1][j-1], b = dp[i-1][j], c = dp[i][j-1], d = nums1[i-1] * nums2[j-1];
                dp[i][j] = max(max(a, b), max(c, d));
                dp[i][j] = max(dp[i][j], a + d);
            }
        }
        return dp[n][m];
    }
};