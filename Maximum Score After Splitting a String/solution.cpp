class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), c1 = 0, c0 = 0, mx = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(s[i] == '0') c0++;
            else c1++;
            mx = max(c0 - c1, mx);
        }
        if(s[n-1] == '1') c1++;
        return mx + c1;
    }
};