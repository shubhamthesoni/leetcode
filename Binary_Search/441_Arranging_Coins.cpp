class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high =  n;
        // n * (n+1)/2;
        // n*n/2 + n/2;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            long long count = (mid * ( mid +1))/2;
            if(count == n) return mid;
            else if(count < n) low = mid +1;
            else high = mid -1; 
        }
        return high;
    }
};
