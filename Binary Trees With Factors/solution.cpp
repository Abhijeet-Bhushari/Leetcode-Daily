class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        map<long long, long long> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = 1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if((long long)arr[j]*arr[j] > arr[i]) break;
                if((long long)arr[j]*arr[j] <= arr[i] && arr[i]%arr[j] == 0 && mp.find(arr[i]/arr[j])!=mp.end()){
                    if(arr[j] != arr[i]/arr[j]){
                        mp[arr[i]] += 2 * (mp[arr[j]] * mp[arr[i] / arr[j]]);
                    }
                    else{
                        mp[arr[i]] += mp[arr[j]] * mp[arr[j]];
                    }
                }
            }
        }
        long long ans = 0;
        for(auto i: mp){
            ans += i.second;
            ans%=1000000007;
        }
        return ans;
    }
};