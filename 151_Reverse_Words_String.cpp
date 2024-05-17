class Solution {
public:
    string reverseWords(string s) {
        string result;
        stringstream ss(s);
        string words;

        while(ss >> words)
        {
            result = words + " " + result;
        }
        if(result.length()) result.pop_back();
        return result;
    }
};
