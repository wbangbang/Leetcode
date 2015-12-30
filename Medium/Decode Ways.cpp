class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(!n) return 0;
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        if(s[1] != '0') {
            if(stoi(s.substr(0, 2)) > 26) dp[1] = 1;
            else dp[1] = 2;
        }
        else {
            if(stoi(s.substr(0, 2)) > 26) return 0 ;
            dp[1] = 1;
        }
        for(int i = 2; i < n; i++) {
            if(s[i] == '0') {
                if(s[i - 1] == '0' || stoi(s.substr(i - 1, 2)) > 26) return 0;
                else dp[i] = dp[i - 2];
            }
            else {
                if(s[i - 1] == '0' || stoi(s.substr(i - 1, 2)) > 26) dp[i] = dp[i - 1];
                else dp[i] = dp[i - 2] + dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};