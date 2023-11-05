class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int won = 1, highest = max(arr[0], arr[1]);
        for(int i=2; i<arr.size(); i++){
            if(won == k) return highest;
            if(arr[i] > highest){
                highest = arr[i];
                won = 1;
            }
            else won++;
        }
        return highest;
    }
};