class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> groups;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                groups[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto i:groups){
            ans.insert(ans.end(), i.second.rbegin(), i.second.rend());
        }
        return ans;
        // vector<int> ans;
        // vector<int> check;
        // int mx = INT_MIN;
        // for(int i=0; i<nums.size(); i++){
        //     check.push_back(i);
        //     mx = max(i + (int)nums[i].size(), mx);
        // }
        // for(int i=0; i<mx; i++){
        //     for(int j=lower_bound(check.begin(), check.end(), i) - check.begin(); j>=0; j--){
        //         if(j==check.size()) j--;
        //         int k = check[j];
        //         // cout<<nums[k][i-k]<<" "<<i-k<<" "<<check[j]<<endl;
        //         if(nums[k].size()==i-k+1){
        //             check.erase(check.begin() + j);
        //         }
        //         // cout<<check.size()<<endl;
        //         ans.push_back(nums[k][i-k]);
        //     }
        // }
        // return ans;
    }
};