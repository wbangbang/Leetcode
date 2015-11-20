// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n, mid, f = n;
        while(begin <= end) {
            mid = begin + (end - begin) / 2;
            if(isBadVersion(mid)) {
                end = mid - 1;
                f = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        return f;
    }
};