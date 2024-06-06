class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> V(26, 0);
        vector<string> R;

        if(words.size() == 0) return R;
        for(char x: words[0])
        {
            V[x-'a']++;
        }

        for(int i = 1; i < words.size(); i++)
        {
            vector<int> T(26, 0);
            for(char x: words[i]) T[x-'a']++;

            for(int j = 0; j < 26; j++)
            V[j] = min(V[j], T[j]);
        }

        for(int i = 0; i < 26; i++)
        {
            while(V[i]--) 
            {
                string A; A.push_back(i+'a');
                R.push_back(A);
            }
        }

        return R;
    }
};
