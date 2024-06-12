class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int> DP;
       for(int x : arr)
       {
         DP[x]++;
       }
       set<int> S;
       for(auto it : DP)
       {
         if(S.find(it.second) != S.end()) return false;
         S.insert(it.second);
       } 

       return true;
    }
};
