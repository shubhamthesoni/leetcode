class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        if(len == 1) return arr;
        int low = 0;
        int high = len -1;
        int index = -1;
        int mid = 0;
        while(low < high)
        {
            mid = low + (high - low)/2;
            if((arr[mid] == x) || ( (arr[mid] < x) && (arr[mid+1] > x))) break;
            else if(arr[mid] < x) low = mid + 1;
            else high = mid;
        }
        index = mid;
        cout << index << endl;

        if(abs(x-arr[index]) > abs(x-arr[index+1])) index++;
        k--;

        low = index - 1 ;
        high = index + 1;

        while( (k > 0) && ( low >= 0) && (high < len))
        {
            if((x-arr[low]) > (arr[high] - x)) high++;
            else low--;
            k--;
        }
        while((k>0) && (low >= 0)) { low--; k--;}
        while((k>0) && (high < len)) { high++; k--;}

        //return arr;
        return vector<int>(arr.begin() + low + 1, arr.begin() + high);
    }
};
