class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> n;
        int mid;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return min(nums[0], nums[1]);
        if(nums[0] < nums[nums.size() - 1]) return nums[0];
        if(nums.size() % 2 == 0) mid = nums.size() / 2;
        else mid = (nums.size() - 1) / 2;
        int t = nums[mid];
        if(t > nums[0]) {
            for(int i = mid + 1; i < nums.size(); i++) {
                n.push_back(nums[i]);
            }
            return findMin(n);
        }
        else {
            for(int i = 0; i < mid + 1; i++) {
                n.push_back(nums[i]);
            }
            return findMin(n);
        }
    }
    
    int min(int x, int y) {
        if(x < y) return x;
        else return y;
    }
};