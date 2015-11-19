class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        for(int i = 0; i < numRows; i++) {
            vector<int> in, temp;
            in.push_back(1);
            if(i > 0) temp = out.back();
            for(int j = 1; j <= i; j++) {
                if(j == i) in.push_back(1);
                else
                    in.push_back(temp[j] + temp[j - 1]);
            }
            out.push_back(in);
        }
        return out;
    }
};