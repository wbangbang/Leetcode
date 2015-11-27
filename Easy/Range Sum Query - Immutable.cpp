class NumArray {
    vector<int> v;
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            v.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return v[j];
        else return v[j] - v[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);