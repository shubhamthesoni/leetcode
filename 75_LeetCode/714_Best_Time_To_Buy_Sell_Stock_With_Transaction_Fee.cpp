class Solution {
    int DP[100002][2];
    int fee  = 0;
        int evaluate(vector<int> & prices, int index, int canBuy, int len) {
            if(index >= len) return 0;
            if(DP[index][canBuy] != -1) return DP[index][canBuy];

            if(canBuy == 1)
            {
                DP[index][canBuy] = max(evaluate(prices, index+1, 1, len), 
                                        evaluate(prices, index+1, 0, len) - prices[index] - fee);
            }
            else
            {
                DP[index][canBuy] = max(evaluate(prices, index+1, 0, len), 
                                        evaluate(prices, index+1, 1, len) + prices[index]);
            }
            return DP[index][canBuy];
        };
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        //int DP[len][2];
        this->fee = fee;
        memset(DP, -1, sizeof(DP));
        return evaluate(prices, 0, 1, len);
    }
};
