class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int len1 = text1.length();
       int len2 = text2.length();

       vector<vector<int>> DP(len1, vector<int>(len2, -1));

       function<int(int, int)> evaluate = [&](int n1, int n2) {

            if((n1<0) || (n2 < 0)) return 0;
            if(DP[n1][n2] != -1) return DP[n1][n2];

            if(text1[n1] == text2[n2])
            {
                DP[n1][n2] = 1 + evaluate(n1-1, n2-1);
            }
            else
            {
                DP[n1][n2] = max(evaluate(n1-1, n2) , evaluate(n1, n2-1));
            }

            return DP[n1][n2];
       }; 

       return evaluate(len1-1, len2-1);
    }
};
