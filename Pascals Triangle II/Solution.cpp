class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<int> v = {1};
        long long ans = 1;
        for(int i=1; i<n; i++){
            ans *= (n - i);
            ans /= (i);
            v.push_back(ans);
        }
        return v;
    }
};