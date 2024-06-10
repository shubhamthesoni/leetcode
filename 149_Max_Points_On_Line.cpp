class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoint = 1;
        int len = points.size();
        for(int i = 0; i < len; i++)
        {
            map<pair<int, int>, int> M;
            for(int j = i+1; j < len; j++)
            {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = __gcd(dx, dy);
                dx = dx/g;
                dy = dy/g;
                M[make_pair(dx, dy)]++;
                maxPoint = max(maxPoint, M[make_pair(dx, dy)]+1);
            }
        }
        return maxPoint;
    }
};
