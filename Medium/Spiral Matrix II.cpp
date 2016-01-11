class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        vector<int> v;
        if(!n) return result;
        for(int i = 0; i < n; i++) {
            v.push_back(0);
        }
        for(int i = 0; i < n; i++) {
            result.push_back(v);
        }
        int i, j, is = 0, ie = n - 1, js = 0, je = n - 1, count = 1;
        while(is <= ie && js <= je) {
            for(j = js; j <= je; j++) {
                result[is][j] = count;
                count++;
            }
            is++;
            if(is > ie) break;
            for(i = is; i <= ie; i++) {
                result[i][je] = count;
                count++;
            }
            je--;
            if(je < js) break;
            for(j = je; j >= js; j--) {
                result[ie][j] = count;
                count++;
            }
            ie--;
            if(ie < is) break;
            for(i = ie; i >= is; i--) {
                result[i][js] = count;
                count++;
            }
            js++;
            if(js > je) break;
        }
        return result;
        
    }
};