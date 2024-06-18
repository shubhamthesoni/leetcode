bool sortf(vector<int> A, vector<int> B)
{
    if(A[0] != B[0]) return A[0] < B[0];
    return A[1] < B[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(),sortf);

       stack<pair<int, int>> S;
       S.push({intervals[0][0], intervals[0][1]});
       int count = 0;
       for(int i = 1; i < intervals.size(); i++)
       {
            if(S.top().second > intervals[i][0])
            {
                count++;
                S.top().second = min(S.top().second, intervals[i][1]);
            }
            else S.push({intervals[i][0], intervals[i][1]});
       } 
       return count;
    }
};
