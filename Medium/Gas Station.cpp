class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n != cost.size() || !n) return -1;
        int start = 0, min = 0, tg = 0, tc = 0;
        for(int i = 0; i < n; i++) {
            if(gas[i] - cost[i] <= min) {
                min = gas[i] - cost[i];
                if(i == n - 1) {//start behind the cost-most one.
                    if(gas[0] - cost[0] > min) {
                        start = 0;
                    }
                }
                else {
                    if(gas[i + 1] - cost[i + 1] > min)
                        start = i + 1;
                }
            }
            //tg += gas[i];
            //tc += cost[i];
        }
        //if(tg < tc) return -1;
        int count = 0, temp = start, total = 0;
        while(count < n) {
            total += gas[temp] - cost[temp];
            if(total < 0) {
                return -1;
            }
            temp++;
            if(temp > n - 1) temp = 0;
            count++;
        }
        return start;
        
    }
};