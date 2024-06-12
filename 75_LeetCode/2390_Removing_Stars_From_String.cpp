class Solution {
public:
    string removeStars(string s) {
        stack<char> S;
        for(char x : s) {
            if(x == '*') { if(!S.empty()) S.pop(); }
            else S.push(x); 
        }
        string R;
        while( !S.empty()) { R.push_back(S.top()); S.pop(); }
        reverse(R.begin(), R.end());
        return R;
    }
};
