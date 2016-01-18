class Solution {
public:
    int myAtoi(string str) {
        vector<int> v;
        int i = 0, flag = 1;
        double result = 0;                      //Q: if type is long, result will be wrong.
        while(str[i] == ' ' && i < str.size()) {//between the whitespace char and integral number only can be either of '+' or '-'.
            i++;
        }
        if(str[i] == 43 || str[i] == 45) {
            if(i == str.size() - 1) return 0;
            if((str[i + 1] > 57 || str[i + 1] < 48)) return 0;
            if(str[i] == 45) flag = -1;
            i++;
        }
        if(str[i] != 43 && str[i] != 45 && (str[i] > 57 || str[i] < 48)) return 0;
        while(str[i] <= 57 && str[i] >= 48 && i < str.size()) {
            v.push_back(str[i] - 48);
            i++;
        }
        int temp = v.size();
        for(int j = 0; j < temp; j++) {
            result += v[j] * pow(10, temp - 1 - j);//when type is long, processing "9223372036854775809" will make mistake when v[j] = 5.
            if(flag == 1) {
                if(result > 2147483647) return 2147483647;
            }
            else{
                if(result > 2147483648) return -2147483648;
            }
        }
        result *= flag;
        return (int)result;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int n = str.length(), flag = 1, i = 0;
        vector<int> nums;
        //skip whitespace
        while(isspace(str[i]) && i < n) i++;
        if(i == n) return 0;
        //if the first non-spaces-sequence is not valid
        if(!isdigit(str[i]) && str[i] != '+' && str[i] != '-') return 0;
        if(str[i] == '+' || str[i] == '-') {
            if(i + 1 >= n || !isdigit(str[i + 1])) return 0;
            if(str[i] == '-') flag = -flag;
            i++;
        }
        //valid number
        while(i < n && isdigit(str[i])) {
            nums.push_back(str[i] - '0');//cout<<"sfa";
            i++;
        }
        //invert to int
        long long result = 0;
        for(int j = 0; j < nums.size(); j++) {
            result *= 10;
            result += nums[j];
            //if overflow
            if(result > INT_MAX || result < INT_MIN) {
                result = flag == 1? result: -result;
                return result > INT_MAX? INT_MAX: INT_MIN;
            }
        }
        result = flag == 1? result: -result;
        return result;
    }
};

