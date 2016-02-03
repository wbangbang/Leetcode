class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        //stack is used to store increasing bar
        stack<int> myStk; 
        //ensure that all the bars could be considered
        heights.push_back(-1);
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!myStk.empty() && heights[i] < heights[myStk.top()]) {
                //do not save index of h here, otherwise the rectangle to be considered will lose the part before h
                int h = heights[myStk.top()];
                myStk.pop();
                //if myStk is empty, it means that the bars before h has been pop out, i.e the bars before h are higher than h so the rectangle in terms of h has the width start from index 0
                maxArea = max(maxArea, h * (myStk.empty()? i: i - myStk.top() - 1));
            }
            myStk.push(i);
        }
        return maxArea;
    }
};