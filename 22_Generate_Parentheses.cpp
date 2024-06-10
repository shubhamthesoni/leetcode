class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> R;

        function<void(int, int, string)> generate = [&](int i, int j, string s) {
            if(s.length() == n*2)
            {
              //cout << s << endl;
              R.push_back(s);
              return;
            }

                if(i < n)
                {
                    s.push_back('(');
                    generate(i+1, j , s);
                    s.pop_back();
                }

                if(i > j)
                {
                    s.push_back(')');
                    generate(i, j+1, s);
                    s.pop_back();
                    j++;
                }

        };

        generate(0, 0, "");
        return R;
    }
};
