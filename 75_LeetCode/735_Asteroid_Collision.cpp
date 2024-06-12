class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> S;
        for(int i = 0; i < asteroids.size(); i++)
        {
            int x = asteroids[i];
            if(S.empty()) { S.push(x); }
            else
            {
                int t = S.top();
                if((t >= 0) && (x <= 0)) { 
                    if(abs(t) < abs(x)) { S.pop(); i--; }
                    else if(abs(t) == abs(x)) { S.pop(); }
                }
                else { 
                    S.push(x); 
                }
            }
        }
        vector<int> R;
        while(!S.empty()) { R.push_back(S.top()); S.pop(); }
        reverse(R.begin(), R.end());
        return R;
    }
};
