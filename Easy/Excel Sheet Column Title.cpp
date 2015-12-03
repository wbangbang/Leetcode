class Solution {
public:
    string convertToTitle(int n) {
        stack<char> v;
        string s;
        while(n) {
            int temp = n % 26;
            n = n / 26; 
            if(temp == 0) {               //temp == 0 is the special case.
                v.push('Z');
                n -= 1;                     
            }
            else{
                switch (temp) {
                    case 1:
                        v.push('A'); break;
                    case 2:
                        v.push('B'); break;
                    case 3:
                        v.push('C'); break;
                    case 4:
                        v.push('D'); break;
                    case 5:
                        v.push('E'); break;
                    case 6:
                        v.push('F'); break;
                    case 7:
                        v.push('G'); break;
                    case 8:
                        v.push('H'); break;
                    case 9:
                        v.push('I'); break;
                    case 10:
                        v.push('J'); break;
                    case 11:
                        v.push('K'); break;
                    case 12:
                        v.push('L'); break;
                    case 13:
                        v.push('M'); break;
                    case 14:
                        v.push('N'); break;
                    case 15:
                        v.push('O'); break;
                    case 16:
                        v.push('P'); break;
                    case 17:
                        v.push('Q'); break;
                    case 18:
                        v.push('R'); break;
                    case 19:
                        v.push('S'); break;
                    case 20:
                        v.push('T'); break;
                    case 21:
                        v.push('U'); break;
                    case 22:
                        v.push('V'); break;
                    case 23:
                        v.push('W'); break;
                    case 24:
                        v.push('X'); break;
                    case 25:
                        v.push('Y'); break;
                
                }
            }
        }
        while(!v.empty()) {
            s += v.top();
            v.pop();
        }
        return s;
    }
};