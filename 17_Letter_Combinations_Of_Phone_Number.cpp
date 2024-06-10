class Solution {
    vector<vector<char>> D = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};

    void letterCombinations(string digits, int index, vector<string> & R, string combined)
    {
      if(index == digits.length()) { R.push_back(combined); return; }

      for(int i = 0; i < D[digits[index]-'2'].size(); i++)
      {
        string temp = combined;
        temp.push_back(D[digits[index]-'2'][i]);
        letterCombinations(digits, index+1, R, temp);
      }

      return ;
    }

public:
    vector<string> letterCombinations(string digits) {

      vector<string> R;
      int len = digits.length();

      if(len == 0) return R;

      letterCombinations(digits, 0, R, "");
      return R;

    }
};
