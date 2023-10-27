class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), mx = INT_MIN;
        string ans = "";
        for(int i=0; i<n; i++){
            int l = i, r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l + 1 > mx){
                mx = r - l + 1;
                ans = s.substr(l, mx);
            }
            if(i == n-1) continue;
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--; 
                r++;
            }
            l++; 
            r--;
            if(r - l + 1 > mx){
                mx = r - l + 1;
                ans = s.substr(l, mx);
            }
        }
        return ans;
    }
};