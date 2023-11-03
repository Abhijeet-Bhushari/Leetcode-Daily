class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1, ind = 0;
        vector<string> ans;
        while(ind < target.size()){
            while(cur != target[ind]){
                ans.push_back("Push");
                ans.push_back("Pop");
                cur++;
            }
            ans.push_back("Push");
            cur++;
            ind++;
        }
        return ans;
    }
};