class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> heap;
        map<int, int> freq;
        for(auto i:nums){
            if(freq.find(i)==freq.end())heap.push(i);
            freq[i]++;
        }
        int operations = 0;
        while(heap.size()>1){
            int largest = heap.top();
            heap.pop();
            operations += freq[largest];
            int nextLargest = heap.top();
            freq[nextLargest] += freq[largest];
        }
        return operations;
    }
};