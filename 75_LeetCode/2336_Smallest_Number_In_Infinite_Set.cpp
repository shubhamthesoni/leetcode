class SmallestInfiniteSet {
    vector<int> V = vector<int>(1001, 0);
    
    priority_queue<int, vector<int>, greater<int>> PQ; 
public:
    SmallestInfiniteSet() {
        iota(V.begin(), V.end(), 0);
        for(int x : V) PQ.push(x); PQ.pop();
    }
    
    int popSmallest() {
        int x = PQ.top();
        V[x] = 0; 
        PQ.pop();
        return x;
    }
    
    void addBack(int num) {
        if(V[num] != 0) return;
        PQ.push(num);
        V[num] = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
