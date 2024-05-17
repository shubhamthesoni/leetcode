class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string words;
        int len = 0;

        while(ss >> words)
        {
            len = words.length();
        }
        return len;
    }
};
