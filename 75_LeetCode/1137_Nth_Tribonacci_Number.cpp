class Solution {
    map<int, int> M;
public:
    int tribonacci(int n) {
        if(n==0)  return 0;
        if(n<=2) return 1;
        if(M.find(n) != M.end()) return M[n];
        M[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return M[n];
    }
};
