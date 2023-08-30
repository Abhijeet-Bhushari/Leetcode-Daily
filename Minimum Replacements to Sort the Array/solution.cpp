class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0, lim = INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<=lim){
                lim = nums[i];
            }
            else {
                int broken = ceil((double)nums[i]/lim);
                ans += broken - 1;
                lim = nums[i]/(broken);
            }
        }
        return ans;
    }
};