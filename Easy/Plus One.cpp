First Edition

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if(digits.empty()) return res;
        int n = digits.size();
        vector<int>::iterator it;
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] + 1 < 10) {
                if(res.empty())
                  res.push_back(digits[i] + 1);
                else {
                    it = res.begin();
                    res.insert(it, digits[i] + 1);
                }
                it = res.begin();
                res.insert(it, digits.begin(), digits.begin() + i);
                break;
            }
            if(res.empty())
                res.push_back(digits[i] - 9);
            else {
                it = res.begin();
                res.insert(it, digits[i] - 9);
            }
            if(!i) {
                it = res.begin();
                res.insert(it, 1);
            }
        }
        return res;
    }
};

Second Edition

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) res[i] = 0;
            else {
                res[i]++;
                return res;
            }
        }
        res[0] = 1;
        res.push_back(0);
        return res;
    }
};