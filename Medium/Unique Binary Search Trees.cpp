class Solution {
public:
    int numTrees(int n) {
        array<int, 1000> a;
        a[0] = 1;
        for(int i = 1; i <= n; i++) {
            int count = 0;
            for(int j = 0; j < i; j++) {
                int left = j;
                int right = i - 1 - j;
                count += a[left] * a[right];
            }
            a[i] = count;
        }
        return a[n];
    }
};