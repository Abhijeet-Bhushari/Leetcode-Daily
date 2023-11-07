class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> heap;
        int n = dist.size();
        for(int i=0; i<n; i++){
            heap.push((double)dist[i]/speed[i]);
        }
        int cnt = 0;
        while(!heap.empty()){
            if(heap.top() - cnt <= 0) return cnt;
            else{
                heap.pop();
                cnt++;
            }
        }
        return cnt;
    }
};