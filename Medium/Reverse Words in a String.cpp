class Solution {
public:
    void reverseWords(string &s) {
        int size = s.size();
        vector<string> v;
        int i = 0;
        while(i < size) {
            string temp;
            while(s[i] != ' ' && i < size) {
                temp += s[i];
                i++;
            }
            if(!temp.empty()) v.push_back(temp);
            i++;
        }
        s.clear();
        for(int j = v.size() - 1; j >= 0; j--) {
            s += v[j];
            if(j) s += ' ';
        }
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        int n = s.size(), begin = 0, end;
        stack<string> myStack;
        while(1) {
            while(begin < n && s[begin] == ' ') {
                begin++;
            }
            if(begin == n) break;
            end = begin;
            while(end < n && s[end] != ' ') {
                end++;
            }
            myStack.push(s.substr(begin, end - begin));//first store the word and then decide if break.
            if(end == n) break;
            begin = end;
        }
        s.clear();
        int size = myStack.size();//must store the initial size of stack.
        for(int i = 0; i < size; i++) {
            s += myStack.top();
            myStack.pop();
            if(i != size - 1) s += ' ';
        }
        return;
    }
};