class RecentCounter {
    queue<int> Q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        Q.push(t);
        t -= 3000;
        while(Q.front() < t) Q.pop();
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
