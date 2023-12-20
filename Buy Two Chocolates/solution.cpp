class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn = INT_MAX, mn2 = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] <= mn){
                mn2 = mn;
                mn = prices[i];
            }
            else if(prices[i] < mn2){
                mn2 = prices[i];
            }
        }
        if(money - mn - mn2 >= 0) return money - mn - mn2;
        return money; 
    }
};