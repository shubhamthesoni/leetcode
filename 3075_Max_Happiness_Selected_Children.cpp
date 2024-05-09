class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long int max_sum = 0;
        for(int i = 0; i < k; i++)
        {
            long long int temp = (happiness[i] -i);
            max_sum += (temp>0)? temp:0;
        }
        return max_sum;
    }
};
