#if 0

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> S1(nums1.begin(), nums1.end());
        set<int> S2(nums2.begin(), nums2.end());
        vector<vector<int>> R;
        vector<int> L1;
        
        for(auto it : S1)
        {
            if(S2.find(it) == S2.end()) L1.push_back(it);
        }
    
        vector<int> L2;
        for(auto it : S2)
        {
            if(S1.find(it) == S1.end()) L2.push_back(it);
        }
        R.push_back(L1);
        R.push_back(L2);
        return R;
    }
};

#endif

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> M;
        for(int x: nums1) M[x] = 1;
        for(int x: nums2) { if(M[x] == 1) M[x] = 3; else if(M[x] == 0) M[x] = 2; }
        vector<vector<int>> R(2);
        for(auto it: M)
        {
            if(it.second == 1) R[0].push_back(it.first);
            else if(it.second == 2) R[1].push_back(it.first);
        }
        return R;
    }
};
