class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       int len = bloomDay.size();
       if((len < (m*k)) return -1;

       int low = INT_MAX;
       int high = INT_MIN;
       for(int x : bloomDay) { low = min(low, x); high = max(high, x); }

       function<bool(int)> evaluate = [&](int day) {
         int fcount = 0;
         int mcount = 0;
         for(int x : bloomDay)
         {
           fcount = (x <= day) ? (fcount+1) : 0 ;
           if(fcount == k) { fcount = 0; mcount++; }
         }
         return (mcount >= m);
       };

       while(low < high)
       {
         int mid = low + (high - low)/2;
         if(evaluate(mid)) high = mid;
         else low = mid+1;
       }       
       return low;            
    }
};
