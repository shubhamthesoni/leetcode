class Solution {
    vector<int> P;
    int len = 0;
public:
    Solution(vector<int>& w) {
        len = w.size();
        P.resize(len + 1);
        P[0] = 0;
        for(int i = 0; i < len; i++)
        {
            P[i+1] = P[i] + w[i];
        }
    }
    
    int pickIndex() {
        int pick = 1+ rand()%P[len];
        int index = lower_bound(P.begin(), P.end(), pick) - P.begin() - 1;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
