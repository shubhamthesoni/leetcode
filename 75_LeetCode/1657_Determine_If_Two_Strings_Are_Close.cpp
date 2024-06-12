

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> V1(26, 0);
        vector<int> V2(26, 0);
        for(int x : word1) V1[x - 'a']++;
        for(int x : word2) V2[x - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            //cout << i << " " << V1[i] << " " << V2[i] << endl;
            if((V1[i] > 0) ^ (V2[i] > 0)) return false;
            //if(((V1[i] == 0) && (V2[i] != 0)) || ((V2[i]==0) && (V1[i] != 0))) return false;
        }
        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());
        for(int i = 0; i < 26; i++) if(V1[i] != V2[i]) return false;
        return true;
    }
};
