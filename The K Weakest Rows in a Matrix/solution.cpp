class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> ans;
        for(int i=0; i<n; i++){
            int sol = find(mat[i].begin(), mat[i].end(), 0) - mat[i].begin();
            ans.push_back({sol, i});
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};