class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2) ans.push_back(nums[i]);
            else ans.insert(ans.begin(), nums[i]);
        }
        return ans;
    }
};