//I:1, V:5, X:10, L:50, C:100, D:500, M:1000   (1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000)
class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        for(int i = 0; i < 13; i++) {
            while(num >= nums[i]) {
                result += roman[i];
                num -= nums[i];
            }
        }
        return result;
    }
};