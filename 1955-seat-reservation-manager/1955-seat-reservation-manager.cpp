class SeatManager {
public:

    int seat = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {}
    
    int reserve() {
        int ans;
        if(pq.size()) ans = pq.top(), pq.pop();
        else ans = ++seat;
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */