class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int front = 0, end = piles.size();
        int ans = 0;
        while(front < end){
            ans += piles[front+1];
            front += 2;
            end -=1;
        }
        return ans;
    }
};