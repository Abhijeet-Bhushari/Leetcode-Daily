class Solution {
public:
    long long calc(int n){
        return n*(n-1)/2;       
    }

    int reverse(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
            if(n) ans *= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        int n = nums.size();
        for(int i=0; i<n; i++){
            rev.push_back(reverse(nums[i]));
        }
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i] - rev[i]]++;
        }
        long long ans = 0;
        int MOD = 1000000007;
        for(auto i:mp){
            if(i.second >= 2){
                ans += calc(i.second)%MOD;
            }
        }
        return ans%MOD;
    }
};