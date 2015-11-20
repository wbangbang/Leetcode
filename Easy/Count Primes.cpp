class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<bool> v;
        v.push_back(false);
        v.push_back(false);
        for(int i = 2; i < n; i++) {
            if(i % 2 == 0 && i != 2)
                v.push_back(false);         //even number except 2 will not be prime.
            else
                v.push_back(true);
        }
        for(int i = 3; i * i < n; i++) {//if i isn't prime or even, all v[i*x] has been set to false; so don't need to set again
            if(!v[i] || i % 2 == 0) continue;                
            for(int j = i * i; j < n; j += i) {
                if(j % 2 == 0) continue;
                v[j] = false;
            }
        }
        int count = 0;
        for(int i = 2; i< n; i++) {
            if(v[i]) count++;
        }
        return count;
    }
};