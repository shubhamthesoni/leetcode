class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256] = {0};
        int len = s.length();
        for(int i = 0; i < len; i++) hash[s[i]]++;

        int single_count = 0;
        int double_count = 0;
        for(int i = 0; i < 256; i++)
        {
            if(hash[i] % 2) single_count = 1;
            double_count += (hash[i]/2);
        }
        return double_count * 2 + single_count;
    }
};
