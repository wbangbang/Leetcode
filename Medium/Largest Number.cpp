bool comp(int a, int b) {
        long i = 10, j = 10;
        while(i <= a) i *= 10;
        while(j <= b) j *= 10;
        return a * j + b > b * i + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string res = "";
        for(int i = 0; i < nums.size(); i++) {
            if(res == "0") break;
            res += to_string(nums[i]);
        }
        return res;
    }
};

