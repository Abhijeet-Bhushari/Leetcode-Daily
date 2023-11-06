class SeatManager {
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    SeatManager(int n) {
        this->n = n;
        for(int i=1; i<=n; i++){
            this->min_heap.push(i);
        }
    }
    
    int reserve() {
        if(this->min_heap.size() == 0) return -1;
        int seat = this->min_heap.top();
        this->min_heap.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        this->min_heap.push(seatNumber);
    }
};