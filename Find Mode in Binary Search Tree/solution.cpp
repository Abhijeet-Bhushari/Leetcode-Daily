class Solution {
public:
    map<int, int> mp;
    void solve(TreeNode* &root){
        if(root == NULL) return;
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int mx = INT_MIN;
        for(auto i: mp){
            mx = max(i.second, mx);
        }
        vector<int> ans;
        for(auto i: mp){
            if(i.second == mx) ans.push_back(i.first);
        }
        return ans;
    }
};