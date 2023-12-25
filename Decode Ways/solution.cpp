class Solution {
public:
    int n;
    vector<int> dp;
    map<string, bool> mp;
    int solve(string &s, int ind){
        if(ind >= n) return 1;
        if(dp[ind] != -1) return dp[ind];
        int ans;
        string temp = s.substr(ind, 1);
        if(mp[temp]){
            ans = solve(s, ind+1);
        }
        else return 0;
        dp[ind] = ans;
        if(ind == n-1) return ans;
        temp = s.substr(ind, 2);
        if(mp[temp]) ans += solve(s, ind+2);
        dp[ind] = ans;
        return ans;
    }
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n, -1);
        for(int i=1; i<=26; i++){
            mp[to_string(i)] = true;
        }
        return solve(s, 0);
    }
};