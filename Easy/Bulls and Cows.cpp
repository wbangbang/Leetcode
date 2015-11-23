class Solution {
public:
    string getHint(string secret, string guess) {
        int countA = 0, countB = 0;
        string s = "";
        array<int, 10> a;
        a.fill(0);
        int j = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[j]) {
                countA++;
                guess.erase(j, 1);
                continue;
            }
            a[secret[i] - '0']++;
            j++;
        }
        for(int i = 0; i < guess.size(); i++) {
            if(a[guess[i] - '0'] != 0) {
                countB++;
                a[guess[i] - '0']--;
            }
        }
        stringstream ss;
        ss << countA;
        s = ss.str() + 'A';
        stringstream sss;
        sss << countB;
        s += sss.str() + 'B';
        return s;
    }
};