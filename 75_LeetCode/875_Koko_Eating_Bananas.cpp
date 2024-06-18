class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int x: piles) high = max(high, x);

        int low = 1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            int count = 0;
            for(int x : piles) count += ceil((double)x/mid);
            //cout << "for "<<mid<<" : "<<count<<endl;
            //if( count == h) return mid;
            if( count > h) { low = mid+1;}
            else { high = mid;}
        }
        return low;
    }
};
