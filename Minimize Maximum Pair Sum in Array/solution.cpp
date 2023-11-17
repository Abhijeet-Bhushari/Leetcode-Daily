class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), mx = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            if(nums[i] + nums[n-1-i] > mx){
                mx = nums[i] + nums[n-1-i];
            }
        }
        return mx;
    }
};