class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H -F);
        if(C < E || F > D || A > G || B > H) 
            return area;
        if(D < H) {
            if(C < G) {
                return area - min(D - B, D - F) * min(C - A, C - E);
            }
            else {
                return area - min(D - B, D - F) * min(G - A, G - E);
            }
        }
        else {
            if(C < G) {
                return area - min(H - B, H - F) * min(C - A, C - E);
            }
            else {
                return area - min(H - B, H - F) * min(G - A, G - E);
            }
        }

    }

    int min(int a, int b) {
        if(a > b) return b;
        else return a;
    }
};