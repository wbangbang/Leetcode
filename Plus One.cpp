class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i > 0; i--) {
            digits[i]++;
            if(digits[i] < 10) return digits;
            digits[i] -= 10;
        }
        digits[0]++;
        if(digits[0] < 10) return digits;
        digits[0] -= 10;
        digits.insert(digits.begin(), 1);
        return digits;
    }
};