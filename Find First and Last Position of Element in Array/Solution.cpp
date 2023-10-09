class Solution {
public:
    int findFirst(vector<int> &nums, int target, int left, int mid){
        int l = left, r = mid;
        while(l <= r)
        {
            int m = (l + r)/2;
            if(m == l && nums[m] == target) return m;
            if(nums[m] == target && nums[m - 1] < target) return m;
            else if(nums[m] == target && nums[m - 1] == target) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
    int findLast(vector<int> &nums, int target, int mid, int right){
        int l = mid, r = right;
        while(l <= r)
        {
            int m = (l + r)/2;
            if(m == r && nums[m] == target) return m;
            if(nums[m] == target && nums[m + 1] > target) return m;
            else if(nums[m] == target && nums[m + 1] == target) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                int a = findFirst(nums, target, l, mid);
                int b = findLast(nums, target, mid, r);
                return {a, b};
            }
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return {-1, -1};
    }
};