class Solution {
    map<int,int> M;
public:
    bool isHappy(int n) {
        if(n==1) return true;
        if(M.find(n) != M.end()) return false;
        int temp = 0;
        int original = n;
        while(n)
        {
            temp += (n%10)*(n%10);
            n = n/10;
        } 
        M[original] = temp;
        return isHappy(temp); 
    }
};
