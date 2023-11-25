class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = 0;
        for(int i=1; i<n; i++){
            pre[i] = (nums[i] - nums[i-1])*(i) + pre[i-1];
        }
        int temp = 0;
        for(int i=n-2; i>=0; i--){
            int temp2 = pre[i];
            pre[i] += (nums[i+1] - nums[i])*(n - 1 - i) + temp;
            temp = pre[i] - temp2;
        }
        return pre;
    }
};