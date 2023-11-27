class Solution {
public:
    int MOD = 1000000007;
    map<pair<int, int>, int> dp; 

    long long solve(int x, int n, vector<vector<int>> &graph){
        
        if(n == 1 && x != 5) return ((x == 4 || x == 6) ? 3 : 2);
        
        if(dp[{x,n}] > 0) return dp[{x,n}];
        
        long long temp = 0;
        for(int i=0; i<graph[x].size(); i++){
            temp += solve(graph[x][i], n-1, graph);
            temp %= MOD;
        }
        
        dp[{x, n}] = temp;
        return temp;
    }

    int knightDialer(int n) {
        if(n == 1) return 10;
        vector<vector<int>> graph = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3,9,0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {2,4}
        };
        long long cnt = 0;
        for(int i=0; i<10; i++){
            cnt += solve(i, n-1, graph);
            cnt %= MOD;
        }
        return cnt;
    }
};
