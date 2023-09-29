class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false, dec = false;
        for(int i=1; i<nums.size(); i++){
            if(inc == false && nums[i] > nums[i-1]){
                inc = true;
            }
            if(dec == false && nums[i] < nums[i-1]){
                dec = true;
            }
        }
        if(inc && dec) return false;
        return true;
    }
};