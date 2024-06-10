class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> V(101, 0);
        for(int x: heights) V[x]++;

        int i = 0, j = 0;
        int result = 0;
        while((i < 101) && (j < heights.size()))
        {
            if(V[i] == 0) {i++; continue; }
            if(i != heights[j]) result++;
            V[i]--; 
            j++;
        }
        return result;
    }
};
