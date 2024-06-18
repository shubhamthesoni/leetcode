class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<pair<int, int>> S;
        
        for(int i = 0; i < len; i++)
        {
            if(i == 0) { S.push({temperatures[i], 0}); continue;}
            if(S.top().first >= temperatures[i]) { S.push({temperatures[i], i}); }
            else
            {
                while((!S.empty()) && (S.top().first < temperatures[i]))
                {
                    pair<int, int> P = S.top(); S.pop();
                    temperatures[P.second] = i - P.second;
                }
                S.push({temperatures[i], i});
            }
        }

        while(!S.empty())
        {
            temperatures[S.top().second] = 0;
            S.pop();
        }

        return temperatures;
    }
};
