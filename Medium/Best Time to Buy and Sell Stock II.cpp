class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int profit = 0, min = prices[0], max = min;
        for(int i = 0; i < n - 1; i++) {
            if(max == min) {
                if(prices[i + 1] > max) {
                    max = prices[i + 1];
                }
                else if(prices[i + 1] < max) {
                    min = prices[i + 1];
                    max = min;
                }
            }
            else {
                if(prices[i + 1] > max) {
                    max = prices[i + 1];
                }
                else if(prices[i + 1] < max) {
                    profit += max - min;
                    min = prices[i + 1];
                    max = min;
                }
            }
        }
        if(max > prices[n - 1]) return profit += max -min;
        else return profit += prices[n - 1] - min;
    }
};