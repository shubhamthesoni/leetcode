class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> V(10, false);
        vector<vector<int>> R;
        if((n < 1) && (n > 45)) return R;

        function<void(int, int, int , vector<int> &)> evaluate = [&](int index, int count, int sum, vector<int>& C)
        {
            if(count > k) return;
            if(count == k) { if(sum == n) R.push_back(C); return; }
            if(sum > n) return;

            
            for(int i = index; i <= 9; i++)
            {
                if(V[i]==true) continue;
                if((sum+i)>n) return;
                V[i] = true;
                C.push_back(i);
                //printf("index : %d, Count %d, i: %d, sum: %d\n", index, count, i , sum);
                evaluate(i+1, count+1, sum+i, C);
                C.pop_back();
                V[i] = false;
            }
        };

        vector<int> C;
        evaluate(1, 0, 0, C);
        return R;
    }
};
