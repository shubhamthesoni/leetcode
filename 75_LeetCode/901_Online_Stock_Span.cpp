class StockSpanner {
    stack<pair<int, int>> S;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(S.empty()) { S.push({price, 1}); return 1; }

        int count = 1;
        while((!S.empty()) && (S.top().first <= price))
        {
            count += S.top().second; S.pop();
        }
        S.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
