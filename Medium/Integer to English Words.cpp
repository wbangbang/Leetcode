class Solution {
public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        string res = "";
        vector<string> ntow = {"", "Thousand", "Million", "Billion"};
        if(num < 1000) return helper(num);
        if(num < 1000000) {
            int temp = num % 1000;
            num = num / 1000;
            if(!temp)
                res += helper(num) + ' ' + "Thousand";
            else
                res += helper(num) + ' ' + "Thousand" + ' ' + helper(temp);
        }
        else if(num < 1000000000) {
            int num1 = num % 1000000, temp = num1 % 1000;
            num = num / 1000000;
            num1 = num1 / 1000;
            if(num1 && temp) {
                res += helper(num) + ' ' + "Million" + ' ' + helper(num1) + ' ' + "Thousand" + ' ' + helper(temp);
            }
            else if(!num1 && !temp) {
                res += helper(num) + ' ' + "Million";
            }
            else if(!num1) {
                res += helper(num) + ' ' + "Million" + ' ' + helper(temp); 
            }
            else {
                res += helper(num) + ' ' + "Million" + ' ' + helper(num1) + ' ' + "Thousand";
            }
        }
        else {
            int num2 = num % 1000000000, num1 = num2 % 1000000, temp = num1 % 1000;
            num = num / 1000000000;
            num2 = num2 / 1000000;
            num1 = num1 / 1000;
            if(num2 && num1 && temp) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num2) + ' ' + "Million" + ' ' + helper(num1) + ' ' + "Thousand" + ' ' + helper(temp);
            }
            else if(!num2 && !num1 && !temp) {
                res += helper(num) + ' ' + "Billion";
            }
            else if(!num2 && !num1) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(temp);
            }
            else if(!num2 && !temp) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num1) + ' ' + "Thousand";
            }
            else if(!num1 && !temp) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num2) + ' ' + "Million";
            }
            else if(!num2) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num1) + ' ' + "Thousand" + ' ' + helper(temp);
            }
            else if(!num1) {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num2) + ' ' + "Million" + ' ' + helper(temp);
            }
            else {
                res += helper(num) + ' ' + "Billion" + ' ' + helper(num2) + ' ' + "Million" + ' ' + helper(num1) + ' ' + "Thousand";
            }
        }
        return res;
    }
    
    string helper(int num) {
        vector<string> ntow = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> ntows = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> ntowss = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string res = "";
        int hd, td, sd, temp;
        temp = num % 100;
        hd = num / 100;
        sd = temp % 10;
        td =  temp / 10;//cout<<hd<<" "<<td<<" "<<sd;
        if(hd) res += ntow[hd] + ' ' + "Hundred";
        if(res != "" && td) res += ' ';
        if(td > 1) res += ntows[td];
        else if(td == 1) {res += ntowss[sd]; return res;}
        if(res != "" && sd) res += ' ';
        if(td != 1 && sd) res += ntow[sd];
        return res;
    }
};