class Solution {

public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> M;
        int len = nums.size();
        int sum = 0;
        for(int x : nums)
        {
            sum += x;
            int m = sum%k;
            if(m < 0) m = (m +k)%k;
            M[m]++;
            //cout << m << " : " << M[m]<<endl; 
        }

        function<int(int)> fact = [](int x) {
            return (x * (x+1))/2;
        };

        int count = 0;
        for(int i = 0 ; i < k; i++)
        {
            if(M.find(i) == M.end()) continue;
            //cout << "---> " << M[i] << " : " <<fact(M[i]-1) << endl; 
            if((i==0) || (M[i] > 1)) {count+= fact(M[i]-1);}
            if(i==0) count+=M[i];
        }

        return count;
    }
};
