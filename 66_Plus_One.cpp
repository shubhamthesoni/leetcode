class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int sum = 1;
        for (int i = 0; i < digits.size(); i++) {
            sum += digits[i];
            digits[i] = sum%10;
            sum = sum / 10;
        }

        if (sum > 0) {
            digits.push_back(sum);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};
