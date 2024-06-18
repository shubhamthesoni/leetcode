class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int high = letters.size() -1;
        if(letters[high] <= target) return letters[0];
        int low = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(letters[mid] > target) { high = mid -1; }
            else { low = mid +1 ;}
        }
        return letters[low];
    }
};
