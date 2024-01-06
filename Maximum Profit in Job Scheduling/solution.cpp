class Solution {
public:
    map<pair<int, int>, int> dp; 
    int solve(vector<array<int, 3>> &job, int os, int oe, int op){
        int cur = upper_bound(job.begin(), job.end(), (array<int, 3>){os, oe, op}) - job.begin();
        if(cur >= job.size()) return 0;
        if(dp.find({os, oe}) != dp.end()) return dp[{os, oe}];
        int ans, l = job[cur][0], r = job[cur][1], val = job[cur][2];
        int a, b;
        a = val + solve(job, r, r, 0); //pick
        b = solve(job, l, r, val); // not pick
        ans = max(a, b);
        dp[{os, oe}] = ans;
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> job;
        for(int i=0; i<startTime.size(); i++){
            job.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(job.begin(), job.end());
        return solve(job, 0, 0, 0);
    }
};