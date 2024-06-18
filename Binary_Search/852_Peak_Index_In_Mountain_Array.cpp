class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int low = 0;
        int high = len - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if((arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1])) return mid;
            else if(arr[mid] > arr[mid+1]) high = mid -1;
            else low = mid +1; 
        }
        return -1;
    }
};
