// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
#if 0
        long long start = 1;
        long long end = n;
        int count = 0;
        long long mid = 1;
        int bad = 0;
        while(start <= end)
        {
            mid = (start+end);
            mid = (mid/2) + (mid%2);
            count++;
            bool result = isBadVersion(mid);
            if(result) bad = mid;
            cout << "Count : "<<count << " Result : "<< result << " mid : " << mid << " start : "<<start<<" end : "<<end << endl;
            if(result) { end = mid-1;}
            else {start = mid+1;}
        }
        return bad;
#endif
        long long l=0,h=n,ans=0;
        while(l<=h){
            long long  mid=(h+l)/2;
            if(isBadVersion(mid)) {
                ans=mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};
