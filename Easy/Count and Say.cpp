class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) 
            return "1";
        else {
            string s = countAndSay(n - 1);
            string ss = "";
            int j = 0;
            while(j < s.size()) {
                char temp = s[j];
                int i = j, count = 0;
                while(s[i] == temp && i < s.size()) {
                    count++;
                    i++;
                }
                char x = count + '0';
                ss += x;
                ss += temp;
                j += count;
            }
            return ss;
        }
    }
};