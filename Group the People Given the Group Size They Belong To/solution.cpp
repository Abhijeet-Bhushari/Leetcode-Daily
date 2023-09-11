class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int, int>> dom;
        for(int i=0;i<groupSizes.size();i++){
            dom.push_back({groupSizes[i], i});
        }
        sort(dom.begin(), dom.end());
        vector<vector<int>> ans;
        int s = 0, temp = 0;
        for(int i=0; i<dom.size(); i++){
            if(i==0 || temp!=s){ans.push_back({}); temp=s;}
            ans[s].push_back(dom[i].second);
            if(dom[i].first==ans[s].size()) s++;
        }
        return ans;
    }
};