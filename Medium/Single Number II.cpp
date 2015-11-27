class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v;
        v.assign(32, 0);
        for(int i = 0; i < nums.size(); i++) {
            long mask = 1;
            for(int j = 31; j >= 0; j--) {
                if((nums[i] & mask) != 0)       //Notice the precedence of &, !=
                    v[j]++;
                mask <<= 1;
            }
        }cout<<v[0]<<endl;
        unsigned int single = 0;
        for(int i = 0; i < 32; i++) {
            if(v[i] % 3 == 1)
                single += 1;
            if(i == 31) continue;
            single <<= 1;
        }
        return single;
    }
};