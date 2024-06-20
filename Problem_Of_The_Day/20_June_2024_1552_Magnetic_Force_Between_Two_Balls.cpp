class Solution {
    bool evaluate(vector<int>& position, int m, int distance, int len) {
         int fcount = 0;
         int mcount = 1;
         int lastPlaced = position[0];
         for(int i = 1; i < len; i++)
         {
            if((position[i] - lastPlaced) >= distance)
            {
                mcount++;
                lastPlaced = position[i];
                if(mcount >= m) return true;
            }
           //fcount += (position[i] - position[i-1]);
           //if(fcount >= distance) { fcount = 0; mcount++; }
         }
         return false;
       };
public:
    int maxDistance(vector<int>& position, int m) {
        int len = position.size();
       if(len < m) return -1;

       int low = 1;
       int high = INT_MIN;
       //for(int x : position) {  high = max(high, x); }
       sort(position.begin(), position.end());
        high = (position.back() - position[0])/(m-1);


        int result = -1;
        //cout << "Low : "<<low<<" Mid : -1 " << " High : "<< high << endl;
       while(low <= high)
       {
         int mid = low + (high - low)/2;
         if(evaluate(position, m, mid, len)) { low = mid + 1; result = mid; }
         else high = mid - 1;;
         //cout << "Low : "<<low<<" Mid : "<< mid << " High : "<< high << endl;
       }
       return result;
       
    }
};
