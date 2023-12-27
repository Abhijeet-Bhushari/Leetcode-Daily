// color, time, consecutive similar colors

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char color;
        int n = colors.size(), max_time = 0, total = 0, cnt = 0, full = 0;
        for(int i=0; i<n; i++){
            if(color == colors[i]){
                max_time = max(max_time, neededTime[i]);
                full += neededTime[i];
                cnt++;
            }
            if(color != colors[i] || i == n-1){
                if(cnt > 1)total += full - max_time;
                color = colors[i];
                max_time = neededTime[i];
                full = neededTime[i];
                cnt = 1;
            }
        }
        return total;
    }
};