class Solution {
public:
    void increase_bin(string &s, int t, int n){
        string new_s = "";
        while(t > 0){
            new_s = to_string(t%2) + new_s;
            t /= 2;
        }
        while(new_s.size() < n){
            new_s = '0' + new_s;
        }
        s = new_s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string s = "";
        map<string, int> mp;
        int t = -1;
        for(int i=0; i<=n; i++){
            t++;
            increase_bin(s, t, n);
            mp[s] = 0;
        }
        for(int i=0; i<n; i++){
            mp[nums[i]] = 1;
        }
        for(auto i: mp){
            if(i.second != 1) return i.first;
        }
        return "-1";
    }
};