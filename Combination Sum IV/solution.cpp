class Solution {    
    public:

    
    int solve(vector<int> &nums, int target, int cur, int cnt, vector<int> &dp){
        if(cur==target){
            return 1;
        }
        if(dp[cur]>-1) return dp[cur];
        for(int i=0;i<nums.size();i++){
            if(cur+nums[i]<=target){
                cnt+=solve(nums, target, cur+nums[i], 0, dp);
            }
        }
        dp[cur] = cnt;
        return dp[cur];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int cnt;
        vector<int> dp(target+1, -1);
        cnt = solve(nums, target, 0, 0, dp);
        return cnt;
    }
};