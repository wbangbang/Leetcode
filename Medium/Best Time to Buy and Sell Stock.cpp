class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int min = prices[0], max = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min) min = prices[i];
            if(max < prices[i] - min) max = prices[i] - min;
        }
        return max;
    }
};