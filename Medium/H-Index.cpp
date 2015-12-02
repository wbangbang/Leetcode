class Solution {
public:
    int hIndex(vector<int>& citations) {
        array<int, 10000> a;
        a.fill(0);
        int num = 0, size = citations.size();
        if(!size) return 0;
        for(int i = 0; i < size; i++) {
            if(citations[i] >= size) a[size]++;
            else a[citations[i]]++;
        }
        for(int i = size; i >= 0; i--) {
            num += a[i];
            if(num >= i) return i;
        }
        return 0;
    }
};