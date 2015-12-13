//G(N) = (B(n)/2) XOR B(n)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int i = 0, gray = 0;
        while(i < pow(2, n)) {
            gray = i ^ (i / 2);
            result.push_back(gray);
            i++;
        }
        return result;
    }
};