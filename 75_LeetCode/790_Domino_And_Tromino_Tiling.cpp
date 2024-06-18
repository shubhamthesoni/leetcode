class Solution {
    int makestate(bool t1, bool t2)
    {
        if( !t1 && !t2) return 0;
        if( t1 && !t2) return 1;
        if( !t1 && t2) return 2;
        return 3;
    }
public:
    int numTilings(int n) {
        vector<vector<int>> DP(n+1, vector<int>(4,-1));
        long long MOD = 1e9 + 7;

        function<int(int, bool, bool)> evaluate = [&](int index, bool t1, bool t2) { 
            if(index == n) return 1;
            int state = makestate(t1, t2);

            if(DP[index][state] != -1) return DP[index][state];

            bool t3 = (index < (n-1));
            bool t4 = (index < (n-1));
            int count = 0;

            if( t1 && t2 && t3) count += evaluate(index+1, false, true);
            count = count%MOD;
            if( t1 && t2 && t4) count += evaluate(index+1, true, false);
            count = count%MOD;
            if( t1 && !t2 && t3 && t4) count += evaluate(index+1, false, false);
            count = count%MOD;
            if( !t1 && t2 && t3 && t4) count += evaluate(index+1, false, false);
            count = count%MOD;
            if( t1 && t2 ) count += evaluate(index+1, true, true);
            count = count%MOD;
            if( t1 && t2 && t3 && t4) count += evaluate(index+1, false, false);
            count = count%MOD;


            if( t1 && !t2 && t3) count += evaluate(index+1, false, true);
            count = count%MOD;
            if( !t1 && t2 && t4) count += evaluate(index+1, true, false);
            count = count%MOD;
            if( !t1 && !t2 ) count += evaluate(index+1, true, true);

            DP[index][state] = count%MOD;
            //cout << t1 << ":"<<t2<<":"<<t3<<":"<<t4<<endl;
            //cout << "DP["<<index<<"]["<<state<<"] = "<<count<<endl;
            return DP[index][state];
        };

        return evaluate(0, true, true);
    }
};
