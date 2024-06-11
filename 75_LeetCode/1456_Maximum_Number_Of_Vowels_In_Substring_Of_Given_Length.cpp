class Solution {
public:
    int maxVowels(string s, int k) {
        int currSum = 0;
        int maxSum = INT_MIN;
        int len = s.length();
        vector<int> DP(len, 0);
        unordered_set<char> V = {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0; i < k; i++)
        {
          if(V.find(s[i]) != V.end())
          {
            DP[i] = 1;
            currSum++;
          }
        }

        maxSum = currSum;

        int left = 0;
        for(int i = k; i < len; i++)
        {
            currSum -= DP[left++];
            if(V.find(s[i]) != V.end())
            {
              DP[i] = 1;
              currSum++;
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
