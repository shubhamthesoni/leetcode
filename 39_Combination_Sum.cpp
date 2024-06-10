class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> R;
        int len = candidates.size();

        function<void(int, int, vector<int>)> combinationSum = [&](int index, int currSum, vector<int> V) 
        {
            if(index == len) {
                if(currSum == target) R.push_back(V);
                return;
            }

            if(candidates[index] <= (target-currSum))
            {
                V.push_back(candidates[index]);
                combinationSum(index, currSum + candidates[index], V);
                V.pop_back();
            }
            combinationSum(index+1, currSum, V);


        };

        combinationSum(0, 0, {});
        return R;
    }
};
