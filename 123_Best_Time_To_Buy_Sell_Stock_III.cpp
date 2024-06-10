class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int k = 2;
       vector<vector<vector<int>>> V(len+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

       for(int i = len-1; i >= 0; i--)
       {
         for(int j = 0; j <=1 ; j++)
         {
           for(int l = 1; l <= k; l++)
           {
             if(j == 0) V[i][j][l] = max(V[i+1][0][l], V[i+1][1][l] - prices[i]);
             else V[i][j][l] = max(V[i+1][1][l], V[i+1][0][l-1] + prices[i]);
           }
         }
       }
       return V[0][0][k];
  
    }
};
