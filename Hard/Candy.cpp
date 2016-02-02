class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(!n) return 0;
        if(n == 1) return 1;
        vector<int> count;
        count.assign(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) count[i] = count[i - 1] + 1;
        }
        int sum = 0;
        for(int i = n - 1; i >= 1; i--) {
            if(ratings[i] < ratings[i - 1] && count[i] >= count[i - 1]) count[i - 1] = count[i] + 1;
            sum += count[i];
        }
        sum += count[0];
        return sum;
    }
};