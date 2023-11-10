class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;
        for(int i=0; i<adjacentPairs.size(); i++){
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int first;
        for(int i=0; i<adjacentPairs.size(); i++){
            if(mp[adjacentPairs[i][0]].size()==1){
                first = adjacentPairs[i][0];
            }
            if(mp[adjacentPairs[i][1]].size()==1){
                first = adjacentPairs[i][1];
            }
        }
        vector<int> ans;
        int last, cur = first;
        while(ans.size()<mp.size()){
            if(ans.size()==0){
                ans.push_back(cur);
                last = cur;
                cur = mp[cur][0];
            }
            else if(ans.size() == mp.size()-1){
                ans.push_back(cur);
                break;
            }
            else{
                ans.push_back(cur);
                int temp = cur;
                if(last == mp[cur][0]) cur = mp[cur][1];
                else cur = mp[cur][0];
                last = temp;
            }
        }
        return ans;
    }
};