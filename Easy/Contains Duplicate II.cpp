class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        array<int, 100000> a;
        a.fill(-1);
        array<int, 100000> f;
        f.fill(-1);
        for(int i = 0; i < nums.size(); i++) {
            if(a[nums[i]] == -1) {
                a[nums[i]] = i;
            }
            else if(a[nums[i]] == -2) {
                continue;
            }
            else {
                if(i - a[nums[i]] > k) 
                    {a[nums[i]] = i; f[nums[i]] = 0;}
                else f[nums[i]] = 1;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(f[nums[i]] == 1) return true;
        }
        return false;
    }
};