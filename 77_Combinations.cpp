class Solution {

    void combine(int n, int k, int s, vector<vector<int>> &R, vector<int> V)
    {
      if(V.size() == k) { R.push_back(V); return; }

      for(int i = s+1; i <= n; i++)
      {
        //vector<int> T = V;
        V.push_back(i);
        combine(n, k, i, R, V);
        V.pop_back();
      }
      return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> R;
      combine(n, k, 0, R, {});
      return R;
    }
};
