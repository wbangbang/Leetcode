class MinStack {
private:
    vector<int> val;
    vector<int> min;
    
public:
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int x) {
        val.push_back(x);
        if(x < min.back()) {
            min.push_back(x);
        }
        else min.push_back(min.back());
    }

    void pop() {
        val.pop_back();
        min.pop_back();
    }

    int top() {
        return val.back();
    }

    int getMin() {
        return min.back();
    }
};